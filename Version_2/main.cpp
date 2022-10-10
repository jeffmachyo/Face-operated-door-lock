//This is the main entry point for the entire program
#include <iostream>
#include "devicemanager.hpp"

int main() {
    
    // auto d1 = std::make_shared<InitializeFactory>()->create_state();
    DeviceManager::getInstance()->create_state("InitialState");
    return 0;
}