#ifndef INITIALIZE_SM
#define INITIALIZE_SM


#include "statemachines.hpp"
#include <string>


class InitializeSM: public StateMachine{
    
    public:
        // using StateMachine::StateMachine;
        InitializeSM();
        void on_action();
        void on_entry();
        void on_exit();
};

class InitialState: public State {
    public:
        InitialState();
        void execute();
};


#endif