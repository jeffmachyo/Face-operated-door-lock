#ifndef I2C_PERIPHERAL
#define I2C_PERIPHERAL


#include "statemachines.hpp"
#include <string>
#include <memory>
#include <mutex>

class I2C {
    private:
        static std::shared_ptr<I2C> instance;
        static std::mutex m_i2c;
        I2C(std::string path);
        int fd,status,value;

    public:
        
        bool open_check(const int& var);
        bool status_check(int& st,int& var,const int& sl_addr,const int& i2c_addr);
        bool get_open_var();
        static std::shared_ptr<I2C> getInstance(std::string path);
        bool get_status_var(); 
};






#endif

