#include "initializem.hpp"
#include <string>
#include <iostream>
#include "devicemanager.hpp"

bool InitializeSM::on_action() {
    std::cout<<"Initialize action called..."<<std::endl;
    // DeviceManager::getInstance()->get_factory("State")->create("ShutdownState");
    
    // return InitializeSM::on_exit();
    return this->on_exit();
}

bool InitializeSM::on_entry() {
    std::cout<<"Initialize beginning called..."<<std::endl;
    
    // return InitializeSM::on_action();
    return this->on_action();
}

bool InitializeSM::on_exit() {
    std::cout<<"Initialize exit called..."<<std::endl;
    
    return true;
}

void InitialState::execute() {
    DeviceManager::getInstance()->get_factory("StateMachine")->create("InitializeSM");
    InitializeSM::getInstance();
    // if (InitializeSM::getInstance()->on_exit()==true) {
        // DeviceManager::getInstance()->get_factory("State")->create("IdleState");
    // }
     
}
InitialState::InitialState() {
    this->execute();
}

InitializeSM::InitializeSM() {
    this->on_entry();
    // this->on_action();
    // this->on_exit();
}

std::shared_ptr<InitializeSM> InitializeSM::instance{nullptr};
std::mutex InitializeSM::m_init;

std::shared_ptr<InitializeSM> InitializeSM::getInstance() {
    std::lock_guard<std::mutex> lock(m_init);
    if (instance==nullptr) {
        // auto instance = std::make_shared<InitializeSM>();
        // instance = new InitializeSM;
        // instance = new InitializeSM();
        std::shared_ptr<InitializeSM> instance1(new InitializeSM());
        instance1.swap(instance);
    }
    return instance;
    // else {
    //     // std::unique_ptr<InitializeSM> instance=NULL;
    //     // return instance;
    //     throw std::runtime_error("Created class instance more than once!");
    //     // catch(std::runtime_error) {

    //     // };
    // }
    return instance;
}
