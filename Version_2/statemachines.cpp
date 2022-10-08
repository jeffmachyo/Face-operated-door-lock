// Base class for the purpose of creation of subsequent state machines
#include <string>
#include "statemachines.hpp"
#include <iostream>

// StateMachine::StateMachine(std::string name){
//     this->name = name;
//     std::cout<<name+" state machine created"<<std::endl;
// }

std::string StateMachine::state_name;
std::string StateMachine::get_name() {
    return state_name;
}

void StateMachine::set_name(std::string name) {
    state_name = name;
}

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

bool StateMachine::on_action() {
    StateMachine::set_sm_status("On Action");

    return true;
}

bool StateMachine::on_entry() {
    StateMachine::set_sm_status("On Entry");

    return true;
}

bool StateMachine::on_exit() {
    StateMachine::set_sm_status("On Exit");

    return true;
}

bool StateMachine::get_finish_status() {
    return this->finish_status;
}

void StateMachine::set_finish_status(bool status) {
    this->finish_status = status;
}


void AbstractState::setName(std::string name) {
    this->name = name;
}

bool AbstractState::is_Finished() {
    return is_finished;
}

void AbstractState::set_Finished(bool value) {
    this->name = value;
}