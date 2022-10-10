#ifndef STATE_M
#define STATE_M
#include <string>

class AbstractState {
    protected:
        std::string name = std::string();
        bool is_finished;
        // static std::shared_ptr<AbstractState> instance;
    public:
        std::string getName();
        void setName(std::string name);
        bool get_finish_status();
        void set_finish_status(bool status);
        // static std::shared_ptr<AbstractState> getInstance();
        
};
class StateMachine: public AbstractState{
    protected:
        static std::string sm_status;
    
    public:
        static std::string get_sm_status();
        static void set_sm_status(std::string status);

        virtual bool on_action()=0;
        virtual bool on_entry()=0;
        virtual bool on_exit()=0;

};

class State: public AbstractState {
    
    public:
        virtual void execute()=0;
};

#endif