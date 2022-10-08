#include "initializem.hpp"
#include <string>
#include <iostream>
#include "devicemanager.hpp"
#include "i2c.hpp"

auto i2c_1 = I2C::getInstance("/dev/i2c-1");

bool InitializeSM::on_action() {
    StateMachine::on_action();
    std::cout<<"Initialize action called..."<<std::endl;
    // DeviceManager::getInstance()->get_factory("State")->create("ShutdownState");
    
    // return InitializeSM::on_exit();
    return this->on_exit();
}

bool InitializeSM::on_entry() {
    StateMachine::on_entry();
    std::cout<<"Initialize beginning called..."<<std::endl;
    // State::setName("InitialState");
    // return InitializeSM::on_action();
    if (i2c_1->open_check(i2c_1->get_open_var())) {
        printf("Open for business!");
    }
    return this->on_action();
}

bool InitializeSM::on_exit() {
    StateMachine::on_exit();
    std::cout<<"Initialize exit called..."<<std::endl;
    this->set_Finished(true);
    this->set_finish_status(true);
    return true;
}

void InitialState::execute() {
    auto d1 = DeviceManager::getInstance()->get_factory("StateMachine")->create("InitializeSM");

    // ds1->status();
    std::cout<<d1->is_Finished()<<std::endl;
    // printf()
    if (InitializeSM::getInstance()->get_finish_status()==true) {
        DeviceManager::getInstance()->get_factory("State")->create("IdleState");
    }
     
}
InitialState::InitialState() {
    this->execute();
}

InitializeSM::InitializeSM() {
    StateMachine::set_name("InitializeSM");
    this->on_entry();
    
}

// void InitializeSM::status() {
//     std::cout<<"I am an initializer"<<std::endl;
// }

std::shared_ptr<InitializeSM> InitializeSM::instance{nullptr};
std::mutex InitializeSM::m_init;

std::shared_ptr<InitializeSM> InitializeSM::getInstance() {
    std::lock_guard<std::mutex> lock(m_init);
    if (instance==nullptr) {
        
        std::shared_ptr<InitializeSM> instance1(new InitializeSM());
        instance1.swap(instance);
    }
    return instance;
    
}
