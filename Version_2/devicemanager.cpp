#include "devicemanager.hpp"
#include <iostream>
#include <stdexcept>
#include "initializem.hpp"
#include "shutdownm.hpp"
#include "idlem.hpp"
#include "statemachines.hpp"


std::shared_ptr<StateMachine> InitializeFactory::create_state_machine(){

     std::shared_ptr<StateMachine> p1= InitializeSM::getInstance();

        return p1;
}

std::shared_ptr<State> InitializeFactory::create_state() {
     std::shared_ptr<State> p1 = InitialState::getInstance();
        return p1;
}

std::shared_ptr<StateMachine> IdleFactory::create_state_machine(){

     std::shared_ptr<StateMachine> p1= IdleSM::getInstance();

        return p1;
}

std::shared_ptr<State> IdleFactory::create_state() {
     std::shared_ptr<State> p1 = IdleState::getInstance();

        return p1;
}

DeviceManager::DeviceManager() {
 
}
std::shared_ptr<DeviceManager> DeviceManager::instance{nullptr};

std::shared_ptr<DeviceManager> DeviceManager::getInstance() {
    if (instance==nullptr) {
        std::shared_ptr<DeviceManager> instance1(new DeviceManager());

        instance1.swap(instance);
    }
    
        return instance;
}

std::shared_ptr<State> DeviceManager::create_state(std::string state) {
    if (state.compare("InitialState")==0) {

        return std::make_shared<InitializeFactory>()->create_state();        
    }
    else if (state.compare("IdleState")==0) {
        return std::make_shared<IdleFactory>()->create_state();
    }
    else {
        throw std::runtime_error("Factory sub class missing");
    }
    
}


