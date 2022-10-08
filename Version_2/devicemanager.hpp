#ifndef DEVICE_SM
#define DEVICE_SM

#include <string>
#include <memory>
#include "statemachines.hpp"

class AbstractFactory {

    public:
        // virtual void create(std::string)=0;   
        virtual std::shared_ptr<AbstractState> create(std::string)=0; 
         
};



class StateMachineFactory: public AbstractFactory {
    public:
        // void create(std::string);
        std::shared_ptr<AbstractState> create(std::string);
};

class StateFactory: public AbstractFactory {
    public:
        // void create(std::string);
        std::shared_ptr<AbstractState> create(std::string);
};

class DeviceManager {
    private:
    // Using a singleton
        static std::unique_ptr<DeviceManager> instance;
        DeviceManager();

    public:
    std::shared_ptr<AbstractFactory> get_factory(std::string);
    static std::unique_ptr<DeviceManager> getInstance();
    
};



#endif