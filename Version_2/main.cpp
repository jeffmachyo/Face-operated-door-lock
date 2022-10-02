//This is the main entry point for the entire program
#include <iostream>
#include "devicemanager.hpp"

int main() {
    
    DeviceManager::getInstance()->get_factory("State")->create("InitialState");
   
    return 0;
}