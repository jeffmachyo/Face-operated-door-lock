#include "initializem.hpp"
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
void InitializeSM::on_action() {
    std::cout<<"Initialize action called..."<<std::endl;
}

void InitializeSM::on_entry() {
    std::cout<<"Initialize beginning called..."<<std::endl;
    
}

void InitializeSM::on_exit() {
    std::cout<<"Initialize exit called..."<<std::endl;
}

void InitialState::execute() {
    DeviceManager d;
    d.get_factory("StateMachine")->create("InitializeSM");
    
}
InitialState::InitialState() {
    this->execute();
}

InitializeSM::InitializeSM() {
    this->on_entry();
    this->on_action();
    this->on_exit();
}

