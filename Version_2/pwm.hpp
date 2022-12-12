#ifndef PWM_OUT_H
#define PWM_OUT_H

#include <string>
#include <memory>
#include <mutex>

class PWM {
    private:
        static std::shared_ptr<PWM> instance;
        static std::mutex m_pwm;
        PWM(const int& port_number);
        int gpio_port;
        char buf[100];
        int frequency;

    public:
        
        bool door_open();
        static std::shared_ptr<PWM> getInstance(const int& port_number);
     
};






#endif
