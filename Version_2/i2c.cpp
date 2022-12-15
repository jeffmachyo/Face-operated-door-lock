#include "i2c.hpp"
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>

I2C::I2C(const std::string& path) {
    fd = open (path.c_str(),O_RDWR);
}

bool I2C::start(const int& i2c_address) {
    status=ioctl(fd,I2C_SLAVE,i2c_address);
}

bool I2C::open_check(const int& var) {
    if (var<0) {
        
		printf("Error opening! Maybe try sudo?\n");
		return false;
	}
    return true;
}

bool I2C::status_check(int& st,int& var,const int& sl_addr,const int& i2c_addr) {
   st =ioctl(var,sl_addr,i2c_addr);
	if (st<0) {
		printf("Error addressing!\n");
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

bool I2C::send_message(const uint8_t* buffer) {
    write(fd, buffer, 1);
}
bool I2C::receive_message(uint8_t* buffer) {
    read(fd, buffer, 1);
}

std::shared_ptr<I2C> I2C::instance{nullptr};
std::mutex I2C::m_i2c;

std::shared_ptr<I2C> I2C::getInstance(const std::string& path) {
    std::lock_guard<std::mutex> lock(m_i2c);
    if (instance==nullptr) {
        
        std::shared_ptr<I2C> instance1(new I2C(path));
        instance1.swap(instance);
    }
    return instance;
    
}