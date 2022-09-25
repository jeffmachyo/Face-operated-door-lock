#ifndef SHUTDOWN_SM
#define SHUTDOWN_SM


#include "statemachines.hpp"
#include <string>


class ShutdownSM: public StateMachine{
    
    public:
        // using StateMachine::StateMachine;
        // ShutdownSM();
        void on_action();
        void on_entry();
        void on_exit();
};

class ShutdownState: public State {
    public:
        ShutdownState();
        void execute();
};


#endif