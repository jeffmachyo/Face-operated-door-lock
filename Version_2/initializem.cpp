#include "initializem.hpp"
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
void InitializeSM::on_action() {
    std::cout<<"Action called..."<<std::endl;
}

void InitializeSM::on_entry() {
    std::cout<<"Beginning called..."<<std::endl;
}

void InitializeSM::on_exit() {
    std::cout<<"Exit called..."<<std::endl;
}

void InitialState::execute() {
    
    InitializeSM i("InitializeSM");
    i.on_entry();
    i.on_action();
    i.on_exit();
}