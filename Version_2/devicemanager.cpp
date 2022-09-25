#include "devicemanager.hpp"
#include <iostream>
#include <stdexcept>
#include "initializem.hpp"
#include "shutdownm.hpp"


std::shared_ptr<AbstractState> StateMachineFactory::create(std::string name) {
    if (name.compare("InitializeSM")==0) {
        std::shared_ptr<AbstractState> p1(new InitializeSM());

        return p1;
    }
    else if (name.compare("ShutdownSM")==0) {
        std::shared_ptr<AbstractState> p1(new ShutdownSM());

        return p1;
    }
    else {
        throw std::runtime_error("Not a valid State Machine");
    }
    // std::cout<<"I make State Machines"<<std::endl;
}

std::shared_ptr<AbstractState> StateFactory::create(std::string name) {
    // std::cout<<"I make States"<<std::endl;
    if (name.compare("InitialState")==0) {
        std::shared_ptr<AbstractState> p1(new InitialState());

        return p1;
    }
    else if (name.compare("ShutdownState")==0) {
        std::shared_ptr<AbstractState> p1(new ShutdownState());

        return p1;
    }
    else {
        throw std::runtime_error("Not a valid State");
    }
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