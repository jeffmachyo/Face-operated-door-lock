#ifndef STATE_M
#define STATE_M
#include <string>

class AbstractState {
    protected:
        std::string name = std::string();
    public:
        std::string getName();
        void setName(std::string name);
        // void setName(std::string name);
        
};

class StateMachine: public AbstractState{
    // protected:
    //     std::string name = std::string();
    
    public:
        // StateMachine(std::string name);
        // std::string getName();
        
        virtual void on_action()=0;
        virtual void on_entry()=0;
        virtual void on_exit()=0;
        // virtual void execute()=0;
};

class State: public AbstractState {
    public:
        virtual void execute()=0;
};

#endif