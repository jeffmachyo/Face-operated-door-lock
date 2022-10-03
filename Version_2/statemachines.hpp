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
    protected:
        static std::string state_name;
        static std::string sm_status;
        bool finish_status;
    
    public:
        // StateMachine(std::string name);
        static std::string get_name();
        static void set_name(std::string name);
        static std::string get_sm_status();
        static void set_sm_status(std::string status);

        bool get_finish_status();
        void set_finish_status(bool status);
        // virtual bool on_action()=0;
        // virtual bool on_entry()=0;
        // virtual bool on_exit()=0;

        bool on_action();
        bool on_entry();
        bool on_exit();
        
        // virtual void execute()=0;
};

class State: public AbstractState {
    // protected:
    //     static std::string state_name;

    public:
        // static std::string get_name();
        // static void set_name(std::string);
        virtual void execute()=0;
};

#endif