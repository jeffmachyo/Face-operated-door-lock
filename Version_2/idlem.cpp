#include "idlem.hpp"
#include <string>
#include <iostream>
#include "devicemanager.hpp"


bool IdleSM::on_action() {
    // StateMachine::on_action();
    std::cout<<"Idle action called..."<<std::endl;
    // DeviceManager::getInstance()->get_factory("State")->create("ShutdownState");
    return this->on_exit();
}

bool IdleSM::on_entry() {
    // StateMachine::on_entry();
    this->set_finish_status(false);
    std::cout<<"Entered Idle State.."<<std::endl;
    // std::cout<<StateMachine::get_name()<<std::endl;
    // this->set_finish_status(false);
    return this->on_action();
}

bool IdleSM::on_exit() {
    // StateMachine::on_exit();
    std::cout<<"Exiting Idle State..."<<std::endl;
    this->set_finish_status(true);
    return true;
}

void IdleState::execute() {
    // DeviceManager::getInstance()->get_factory("StateMachine")->create("IdleSM");
    auto d1 = std::make_shared<IdleFactory>()->create_state_machine();
}
IdleState::IdleState() {
    this->execute();
}

IdleSM::IdleSM() {
    this->on_entry();
    // this->on_action();
    // this->on_exit();
}

std::shared_ptr<IdleSM> IdleSM::instance{nullptr};

std::shared_ptr<IdleSM> IdleSM::getInstance() {
    if (instance==nullptr) {
        
        std::shared_ptr<IdleSM> instance1(new IdleSM());
        instance1.swap(instance);
    }
    return instance;
}

std::shared_ptr<IdleState> IdleState::instance{nullptr};
// std::mutex InitializeSM::m_init;

std::shared_ptr<IdleState> IdleState::getInstance() {
    // std::lock_guard<std::mutex> lock(m_init);
    if (instance==nullptr) {
        
        std::shared_ptr<IdleState> instance1(new IdleState());
        instance1.swap(instance);
    }
    return instance;
    
}