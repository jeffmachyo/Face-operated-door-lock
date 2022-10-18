#ifndef PWM_OUT_H
#define PWM_OUT_H

#include <string>
#include <memory>
#include <mutex>

class PWM {
    private:
        static std::shared_ptr<PWM> instance;
        static std::mutex m_pwm;
        PWM(const int& gpio_port);
        int gpio_port;
        // const char buf[100];

    public:
        
        bool door_open(char* buf,const int& gpio_port,const int& frequency);
        static std::shared_ptr<PWM> getInstance(const int& gpio_port);
     
};






#endif
