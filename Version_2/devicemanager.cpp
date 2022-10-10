#include "devicemanager.hpp"
#include <iostream>
#include <stdexcept>
#include "initializem.hpp"
#include "shutdownm.hpp"
#include "idlem.hpp"
#include "statemachines.hpp"


std::shared_ptr<StateMachine> InitializeFactory::create_state_machine(){

     std::shared_ptr<StateMachine> p1= InitializeSM::getInstance();

        return p1;
}

std::shared_ptr<State> InitializeFactory::create_state() {
     std::shared_ptr<State> p1 = InitialState::getInstance();
        return p1;
}

std::shared_ptr<StateMachine> IdleFactory::create_state_machine(){

     std::shared_ptr<StateMachine> p1= IdleSM::getInstance();

        return p1;
}

std::shared_ptr<State> IdleFactory::create_state() {
     std::shared_ptr<State> p1 = IdleState::getInstance();

        return p1;
}

DeviceManager::DeviceManager() {
 
}

std::string& DeviceManager::get_current_state() {
    return this->current_state;
}

std::string& DeviceManager::get_next_state() {
    return this->next_state;
}

std::string& DeviceManager::get_previous_state() {
    return this->previous_state;
}

void DeviceManager::set_current_state(const std::string& state) {
    this->current_state = state;
}

DeviceManager& DeviceManager::set_next_state(const std::string& state) {
    this->next_state = state;
    return *this;
}

void DeviceManager::set_previous_state(const std::string& state) {
    this->previous_state = state;
}



std::shared_ptr<DeviceManager> DeviceManager::instance{nullptr};

std::shared_ptr<DeviceManager> DeviceManager::getInstance() {
    if (instance==nullptr) {
        std::shared_ptr<DeviceManager> instance1(new DeviceManager());

        instance1.swap(instance);
    }
    
        return instance;
}

std::shared_ptr<State> DeviceManager::create_state(std::string state) {
    if (state.compare("InitialState")==0) {

        return std::make_shared<InitializeFactory>()->create_state();        
    }
    else if (state.compare("IdleState")==0) {
        return std::make_shared<IdleFactory>()->create_state();
    }
    else {
        throw std::runtime_error("Factory sub class missing");
    }
    
}

void DeviceManager::start() {
    try {
        this->create_state(this->get_next_state());
    }
    catch (const std::runtime_error& error) {
        std::cout<<"No next state set.."<<std::endl;
    }
}


