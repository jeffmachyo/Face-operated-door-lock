#include "devicemanager.hpp"
#include <iostream>
#include <stdexcept>


void StateMachineFactory::create() {
    std::cout<<"I make State Machines"<<std::endl;
}

void StateFactory::create() {
    std::cout<<"I make States"<<std::endl;
}

// void AbstrasctFactory::create() {
//     throw std::runtime_error("Factory sub class missing");
// }

std::shared_ptr<AbstrasctFactory> DeviceManager::get_factory(std::string name) {
    if (name.compare("StateMachine")==0) {
        std::shared_ptr<AbstrasctFactory> p1(new StateMachineFactory());
        return p1;
    } 
    else if (name.compare("State")==0) {
        std::shared_ptr<AbstrasctFactory> p1(new StateFactory());
        return p1;
    }
    else {
        throw std::runtime_error("Factory sub class missing");
    }
}