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

    protected:
        // InitializeSM();
        // ~InitializeSM();

    public:
        // using StateMachine::StateMachine;
        friend std::shared_ptr<InitializeSM> std::make_shared<InitializeSM>();
        InitializeSM(InitializeSM& other) = delete;
        void operator = (const InitializeSM&) = delete;
        bool on_action();
        bool on_entry();
        bool on_exit();
        static std::shared_ptr<InitializeSM> getInstance();
};

class InitialState: public State {
    public:
        InitialState();
        void execute();
};



#endif