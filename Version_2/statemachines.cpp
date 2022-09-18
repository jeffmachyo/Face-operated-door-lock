// Base class for the purpose of creation of subsequent state machines
#include <string>
#include "statemachines.hpp"
#include <iostream>

StateMachine::StateMachine(std::string name){
    this->name = name;
    std::cout<<name+" state machine created"<<std::endl;
}

std::string AbstractState::getName(){
    return this->name;
}

void AbstractState::setName(std::string name) {
    this->name = name;
}



// class Singleton {
//     private:
//         Singleton();
    
//     public:
//         static Singleton getInstance() {
//             static Singleton _instance;
//             return _instance;
//         }
// };