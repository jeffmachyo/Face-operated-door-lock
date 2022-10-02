//This is the main entry point for the entire program
#include <iostream>
// #include "initializem.hpp"
#include "devicemanager.hpp"

int main() {
    std::cout<<"Ndio kuanza sasa.."<<std::endl;
    // DeviceManager d;
    // d.get_factory("StateMachine")->create();
    DeviceManager::getInstance()->get_factory("State")->create("InitialState");
    // d.get_factory("State")->create("ShutdownState");
    
    return 0;
}