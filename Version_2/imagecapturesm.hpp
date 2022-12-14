#ifndef IMAGECAPTURE_SM
#define IMAGECAPTURE_SM


#include "statemachines.hpp"
#include <string>
#include <memory>
#include <mutex>

class ImageCaptureSM: public StateMachine{

    private:
        static std::shared_ptr<ImageCaptureSM> instance;
        static std::mutex m_init;
        ImageCaptureSM();

    public:
        
        bool on_action();
        bool on_entry();
        bool on_exit();
        static std::shared_ptr<ImageCaptureSM> getInstance();
};

class InitialState: public State {
    private:
        static std::shared_ptr<InitialState> instance;
        // static std::mutex m_init;
        InitialState();
    public:
        void execute();
        static std::shared_ptr<InitialState> getInstance();
};



#endif