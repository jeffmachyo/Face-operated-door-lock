#ifndef DEVICE_SM
#define DEVICE_SM

#include <string>
#include <memory>
#include "statemachines.hpp"

class AbstrasctFactory {

    public:
        // virtual void create(std::string)=0;   
        virtual std::shared_ptr<AbstractState> create(std::string)=0;  
};



class StateMachineFactory: public AbstrasctFactory {
    public:
        // void create(std::string);
        std::shared_ptr<AbstractState> create(std::string);
};

class StateFactory: public AbstrasctFactory {
    public:
        // void create(std::string);
        std::shared_ptr<AbstractState> create(std::string);
};

class DeviceManager {
    public:
    std::shared_ptr<AbstrasctFactory> get_factory(std::string);

};



#endif