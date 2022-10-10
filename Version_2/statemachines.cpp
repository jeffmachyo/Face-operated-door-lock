// Base class for the purpose of creation of subsequent state machines
#include <string>
#include "statemachines.hpp"
#include <iostream>


std::string AbstractState::getName(){
    return this->name;
}

std::string StateMachine::sm_status;
std::string StateMachine::get_sm_status() {
    return sm_status;
}

void StateMachine::set_sm_status(std::string status) {
    sm_status = status;
}

// bool StateMachine::on_action() {
//     StateMachine::set_sm_status("On Action");

//     return true;
// }

// bool StateMachine::on_entry() {
//     StateMachine::set_sm_status("On Entry");

//     return true;
// }

// bool StateMachine::on_exit() {
//     StateMachine::set_sm_status("On Exit");

//     return true;
// }

void AbstractState::setName(std::string name) {
    this->name = name;
}

bool AbstractState::get_finish_status() {
    return is_finished;
}

void AbstractState::set_finish_status(bool status) {
    is_finished = status;
}