#ifndef DEVICE_SM
#define DEVICE_SM

#include <string>
#include <memory>
#include "statemachines.hpp"

class AbstractFactory {
    public:
        
        virtual std::shared_ptr<StateMachine> create_state_machine()=0;
        virtual std::shared_ptr<State> create_state()=0;
};

class InitializeFactory: public AbstractFactory {
    public:
        
        std::shared_ptr<StateMachine> create_state_machine();
        std::shared_ptr<State> create_state();


};

class IdleFactory: public AbstractFactory {
    public:
        
        std::shared_ptr<StateMachine> create_state_machine();
        std::shared_ptr<State> create_state();


};


class DeviceManager {
    private:
    // Using a singleton
        static std::shared_ptr<DeviceManager> instance;
        DeviceManager();
        std::string current_state;
        std::string next_state;
        std::string previous_state;

    public:
    static std::shared_ptr<DeviceManager> getInstance();
    std::string& get_current_state();
    std::string& get_next_state();
    std::string& get_previous_state();

    void set_current_state(const std::string&);
    DeviceManager& set_next_state(const std::string&);
    void set_previous_state(const std::string&);
    std::shared_ptr<State> create_state(std::string state);
    void start();

};



#endif