#ifndef SHUTDOWN_SM
#define SHUTDOWN_SM


#include "statemachines.hpp"
#include <string>


class ShutdownSM: public StateMachine{
    
    public:
        // using StateMachine::StateMachine;
        ShutdownSM();
        bool on_action();
        bool on_entry();
        bool on_exit();
};

class ShutdownState: public State {
    public:
        ShutdownState();
        void execute();
};


#endif