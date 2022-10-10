#ifndef INITIALIZE_SM
#define INITIALIZE_SM


#include "statemachines.hpp"
#include <string>
#include <memory>
#include <mutex>

class InitializeSM: public StateMachine{

    private:
        static std::shared_ptr<InitializeSM> instance;
        static std::mutex m_init;
        InitializeSM();

    public:
        
        bool on_action();
        bool on_entry();
        bool on_exit();
        static std::shared_ptr<InitializeSM> getInstance();
};

class InitialState: public State {
    private:
        static std::shared_ptr<InitialState> instance;
        // static std::mutex m_init;
        InitialState();
    public:
        // InitialState();
        void execute();
        static std::shared_ptr<InitialState> getInstance();
};



#endif