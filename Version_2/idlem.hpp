#ifndef IDLE_SM
#define IDLE_SM


#include "statemachines.hpp"
#include <string>
#include <memory>

class IdleSM: public StateMachine{

    private:
        static std::unique_ptr<IdleSM> instance;
        IdleSM();
    
    public:
        // using StateMachine::StateMachine;
        
        bool on_action();
        bool on_entry();
        bool on_exit();
        static std::unique_ptr<IdleSM> getInstance();
};

class IdleState: public State {
    public:
        IdleState();
        void execute();
};


#endif