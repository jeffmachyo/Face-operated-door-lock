//This is the main entry point for the entire program
#include <iostream>
#include "devicemanager.hpp"

int main() {
    
    auto d1 = DeviceManager::getInstance();
    d1->set_next_state("InitialState");
    d1->start();

    return 0;
}