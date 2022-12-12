#include "pwm.hpp"
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

PWM::PWM(const int& port_number) {
    // this->gpio_port = gpio_port;
    gpio_port = port_number;
    frequency=20000; //For now

}

bool PWM::door_open() {

    FILE* fd = fopen("/sys/class/gpio/export","w");
    fprintf(fd,"%d",gpio_port);
    fclose(fd);
    
    sprintf(buf,"/sys/class/gpio/gpio%d/direction",gpio_port);
    fd = fopen(buf,"w");
    fprintf(fd,"out");
    fclose(fd);

    sprintf(buf,"/sys/class/gpio/gpio%d/value",gpio_port);
    fd = fopen(buf,"w");

    for(int i=0;i<frequency;i++) {
		fd = fopen(buf,"w");
		fprintf(fd,"1");
		fclose(fd);
		fd = fopen(buf, "w");
		fprintf(fd,"0");
		fclose(fd);
		usleep(100);
	}
	// return 1;






    // if (var<0) {
        
	// 	printf("Error opening! Maybe try sudo?\n");
	// 	return false;
	// }
    return true;
}


std::shared_ptr<PWM> PWM::instance{nullptr};
std::mutex PWM::m_pwm;

std::shared_ptr<PWM> PWM::getInstance(const int& port_number) {
    std::lock_guard<std::mutex> lock(m_pwm);
    if (instance==nullptr) {
        
        std::shared_ptr<PWM> instance1(new PWM(port_number));
        instance1.swap(instance);
    }
    return instance;
    
}