#include "shutdownm.hpp"
#include <string>
#include <iostream>
#include "devicemanager.hpp"

// InitializeSM::InitializeSM(std::string name):StateMachine(name) {
// InitializeSM::InitializeSM(std::string name) {
//     // this->name = name;
//     std::cout<<"Initialize state created"<<std::endl;
//     // int counter = counter;
// }
//     this->name = name;

// }

bool ShutdownSM::on_action() {
    std::cout<<"Shutdown action called..."<<std::endl;
    return this->on_exit();
}

bool ShutdownSM::on_entry() {
    std::cout<<"Shutdown beginning called..."<<std::endl;

    return this->on_action();
}

bool ShutdownSM::on_exit() {
    std::cout<<"Shutdown exit called..."<<std::endl;
    return 1;
}

void ShutdownState::execute() {
    DeviceManager::getInstance()->get_factory("StateMachine")->create("ShutdownSM");
    // if (ShutdownSM::getInstance()->on_exit()) {
    //     DeviceManager::getInstance()->get_factory("State")->create("IdleState");
    // }
    // ShutdownSM i;
    // i.on_entry();
    // i.on_action();
    // i.on_exit();
}
ShutdownState::ShutdownState() {
    this->execute();
}

ShutdownSM::ShutdownSM() {
    this->on_entry();
    // this->on_action();
    // this->on_exit();
}