#include "idlem.hpp"
#include <string>
#include <iostream>
#include "devicemanager.hpp"
#include "i2c.hpp"

#define I2C_ADDR 0x10

auto i2c_1 = I2C::getInstance("/dev/i2c-1");

bool IdleSM::on_action() {
    std::cout<<"Idle action called..."<<std::endl;
    

    // Add if command comes in move to another state
    return this->on_exit();
}

bool IdleSM::on_entry() {
    this->set_finish_status(false);
    std::cout<<"Entered Idle State.."<<std::endl;
    
    return this->on_action();
}

bool IdleSM::on_exit() {

    std::cout<<"Exiting Idle State..."<<std::endl;
    this->set_finish_status(true);
    return true;
}

void IdleState::execute() {

    auto d1 = std::make_shared<IdleFactory>()->create_state_machine();
}
IdleState::IdleState() {
    this->execute();
}

IdleSM::IdleSM() {
    this->on_entry();

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