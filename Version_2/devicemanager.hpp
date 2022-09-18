#ifndef DEVICE_SM
#define DEVICE_SM

#include <string>
#include <memory>
#include "statemachines.hpp"

class AbstrasctFactory {

    public:
        virtual void create()=0;    
};



class StateMachineFactory: public AbstrasctFactory {
    public:
        void create();
};

class StateFactory: public AbstrasctFactory {
    public:
        void create();
};

class DeviceManager {
    public:
    std::shared_ptr<AbstrasctFactory> get_factory(std::string);

};



#endif