#include "pwm.hpp"
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

PWM::PWM(const int& gpio_port) {
    this->gpio_port = gpio_port;
    
}

bool PWM::door_open(char* buf,const int& gpio_port,const int& frequency) {

    FILE* fd = fopen("/sys/class/gpio/export","w");
    fprintf(fd,"%d",gpio_port);
    fclose(fd);
    
    sprintf(buf,"/sys/class/gpio/gpio%d/direction",gpio_port);
    fd = fopen(buf,"w");
    fprintf(fd,"out");
    fclose(fd);

    sprintf(buf,"/sys/class/gpio/gpio%d/value",gpio_port);
    fd = fopen(buf,"w");







    // if (var<0) {
        
	// 	printf("Error opening! Maybe try sudo?\n");
	// 	return false;
	// }
    return true;
}


std::shared_ptr<PWM> PWM::instance{nullptr};
std::mutex PWM::m_pwm;

std::shared_ptr<PWM> PWM::getInstance(const int& gpio_port) {
    std::lock_guard<std::mutex> lock(m_pwm);
    if (instance==nullptr) {
        
        std::shared_ptr<PWM> instance1(new PWM(gpio_port));
        instance1.swap(instance);
    }
    return instance;
    
}