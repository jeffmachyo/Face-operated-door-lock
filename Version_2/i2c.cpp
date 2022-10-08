#include "i2c.hpp"
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>


I2C::I2C(std::string path) {
    fd = open (path.c_str(),O_RDWR);
    printf(path.c_str());
}

bool I2C::open_check(const int& var) {
    if (var<0) {
		printf("Error opening! Maybe try sudo?");
		return false;
	}
    return true;
}

bool I2C::status_check(int& st,int& var,const int& sl_addr,const int& i2c_addr) {
   st =ioctl(var,sl_addr,i2c_addr);
	if (st<0) {
		printf("Error addressing!");
		close(var);
		var = -1;
		return false;
	}
    printf("Open Success!\n");
    return true;
}

bool I2C::get_open_var() {
    return fd;
}

bool I2C::get_status_var() {
    return status;
}

std::shared_ptr<I2C> I2C::instance{nullptr};
std::mutex I2C::m_i2c;

std::shared_ptr<I2C> I2C::getInstance(std::string path) {
    std::lock_guard<std::mutex> lock(m_i2c);
    if (instance==nullptr) {
        
        std::shared_ptr<I2C> instance1(new I2C(path));
        instance1.swap(instance);
    }
    return instance;
    
}