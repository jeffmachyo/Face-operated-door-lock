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
// (new x());

        return p1;
}

std::shared_ptr<StateMachine> IdleFactory::create_state_machine(){

     std::shared_ptr<StateMachine> p1= IdleSM::getInstance();

        return p1;
}

std::shared_ptr<State> IdleFactory::create_state() {
     std::shared_ptr<State> p1 = IdleState::getInstance();
// (new x());

        return p1;
}



// std::shared_ptr<AbstractState> StateMachineFactory::create(std::string name) {
//     if (name.compare("InitializeSM")==0) {
        
//         std::shared_ptr<AbstractState> p1= InitializeSM::getInstance();

//         return p1;
//     }
//     else if (name.compare("ShutdownSM")==0) {
//         std::shared_ptr<AbstractState> p1(new ShutdownSM());

//         return p1;
//     }
    // else if (name.compare("IdleSM")==0) {
    //     std::shared_ptr<AbstractState> p1= IdleSM::getInstance();

    //     return p1;
    // }
    // else {
    //     throw std::runtime_error("Not a valid State Machine");
    // }
    // std::cout<<"I make State Machines"<<std::endl;
// }

// std::shared_ptr<AbstractState> StateFactory::create(std::string name) {
//     // std::cout<<"I make States"<<std::endl;
//     if (name.compare("InitialState")==0) {
//         std::shared_ptr<AbstractState> p1(new InitialState());

//         return p1;
//     }
//     else if (name.compare("ShutdownState")==0) {
//         std::shared_ptr<AbstractState> p1(new ShutdownState());

//         return p1;
//     }
//     else if (name.compare("IdleState")==0) {
//         std::shared_ptr<AbstractState> p1(new IdleState());

//         return p1;
//     }
//     else {
//         throw std::runtime_error("Not a valid State");
//     }
// }

// // void AbstrasctFactory::create() {
// //     throw std::runtime_error("Factory sub class missing");
// // }

// std::shared_ptr<AbstractFactory> DeviceManager::get_factory(std::string name) {
//     if (name.compare("StateMachine")==0) {
//         std::shared_ptr<AbstractFactory> p1(new StateMachineFactory());
//         return p1;
//     } 
//     else if (name.compare("State")==0) {
//         std::shared_ptr<AbstractFactory> p1(new StateFactory());
//         return p1;
//     }
//     else {
//         throw std::runtime_error("Factory sub class missing");
//     }
// }
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
    // else {
    else if (state.compare("IdleState")==0) {
        return std::make_shared<IdleFactory>()->create_state();
    }
    else {
        throw std::runtime_error("Factory sub class missing");
    }
    
}


