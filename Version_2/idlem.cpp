#include "idlem.hpp"
#include <string>
#include <iostream>
#include "devicemanager.hpp"


bool IdleSM::on_action() {
    StateMachine::on_action();
    std::cout<<"Idle action called..."<<std::endl;
    // DeviceManager::getInstance()->get_factory("State")->create("ShutdownState");
    return this->on_exit();
}

bool IdleSM::on_entry() {
    StateMachine::on_entry();
    std::cout<<"Entered Idle State.."<<std::endl;
    std::cout<<StateMachine::get_name()<<std::endl;
    
    return this->on_action();
}

bool IdleSM::on_exit() {
    StateMachine::on_exit();
    std::cout<<"Exiting Idle State..."<<std::endl;

    return 1;
}

void IdleState::execute() {
    DeviceManager::getInstance()->get_factory("StateMachine")->create("IdleSM");
    
}
IdleState::IdleState() {
    this->execute();
}

IdleSM::IdleSM() {
    this->on_entry();
    // this->on_action();
    // this->on_exit();
}

std::unique_ptr<IdleSM> IdleSM::instance=0;

std::unique_ptr<IdleSM> IdleSM::getInstance() {
    if (instance==0) {
        std::unique_ptr<IdleSM> instance(new IdleSM());

        return instance;
        // instance = new DeviceManager();
    }
    else {
        throw std::runtime_error("Created class instance more than once!");
    }
    
}
