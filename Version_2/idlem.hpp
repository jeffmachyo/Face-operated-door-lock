#ifndef IDLE_SM
#define IDLE_SM


#include "statemachines.hpp"
#include <string>
#include <memory>

class IdleSM: public StateMachine{

    private:
        static std::shared_ptr<IdleSM> instance;
        IdleSM();
    
    public:
        
        bool on_action();
        bool on_entry();
        bool on_exit();
        static std::shared_ptr<IdleSM> getInstance();
};

class IdleState: public State {
    private:
        static std::shared_ptr<IdleState> instance;
        IdleState();
    public:
        
        void execute();
        static std::shared_ptr<IdleState> getInstance();
};


#endif