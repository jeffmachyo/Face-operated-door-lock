#include "shutdownm.hpp"
#include <string>
#include <iostream>

// InitializeSM::InitializeSM(std::string name):StateMachine(name) {
// InitializeSM::InitializeSM(std::string name) {
//     // this->name = name;
//     std::cout<<"Initialize state created"<<std::endl;
//     // int counter = counter;
// }
//     this->name = name;

// }

void ShutdownSM::on_action() {
    std::cout<<"Shutdown action called..."<<std::endl;
}

void ShutdownSM::on_entry() {
    std::cout<<"Shutdown beginning called..."<<std::endl;
}

void ShutdownSM::on_exit() {
    std::cout<<"Shutdown exit called..."<<std::endl;
}

void ShutdownState::execute() {
    
    ShutdownSM i;
    i.on_entry();
    i.on_action();
    i.on_exit();
}
ShutdownState::ShutdownState() {
    this->execute();
}