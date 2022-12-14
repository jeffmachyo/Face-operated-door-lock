#include "imagecapturesm.hpp"
#include "initializem.hpp"
#include <string>
#include <iostream>
#include "devicemanager.hpp"
#include "i2c.hpp"
#include "camera.hpp"
#include "unistd.h"
#include "pwm.hpp"

auto i2c_1 = I2C::getInstance("/dev/i2c-1");
auto cam_1 = Camera::getInstance();
auto pwm_1 = PWM::getInstance(5);
std::string file_path = "/home/pi/Documents/TELE6550/Final/New_Image.jpg";


bool ImageCaptureSM::on_action() {
    std::cout<<"Initialize action called..."<<std::endl;
    
    cam_1->take_pic(file_path);
    fflush(stdout);
    sleep(5);
    cam_1->stop_pic();

    std::cout<<"Image successful..."<<std::endl;
    sleep(1);
    pwm_1->door_open();

    return this->on_exit();
}

bool ImageCaptureSM::on_entry() {
    this->set_finish_status(false);
    std::cout<<"Initialize beginning called..."<<std::endl;
    
    if (i2c_1->open_check(i2c_1->get_open_var())) {
        std::cout<<"Open for business!"<<std::endl;

        return this->on_action();
    }
    return false;
}

bool ImageCaptureSM::on_exit() {
    std::cout<<"Initialize exit called..."<<std::endl;
    this->set_finish_status(true);
    
    // this->set_sm_status("On Exit");
    return true;
}

void ImageCaptureState::execute() {
    
    auto init_sm = std::make_shared<InitializeFactory>()->create_state_machine();
    
    if (init_sm->get_finish_status()) {
        auto d1 = DeviceManager::getInstance();
        d1->set_next_state("IdleState").start();
    }
     
}
ImageCaptureState::ImageCaptureState() {
    this->execute();
}

ImageCaptureSM::ImageCaptureSM() {
    this->setName("ImageCaptureSM");
    // StateMachine::set_name("InitializeSM");
    this->on_entry();
    
}

std::shared_ptr<ImageCaptureSM> ImageCaptureSM::instance{nullptr};
std::mutex ImageCaptureSM::m_init;

std::shared_ptr<ImageCaptureSM> ImageCaptureSM::getInstance() {
    std::lock_guard<std::mutex> lock(m_init);
    if (instance==nullptr) {
        
        std::shared_ptr<ImageCaptureSM> instance1(new ImageCaptureSM());
        instance1.swap(instance);
    }
    return instance;
    
}

std::shared_ptr<InitialState> InitialState::instance{nullptr};
// std::mutex InitializeSM::m_init;

std::shared_ptr<InitialState> InitialState::getInstance() {
    // std::lock_guard<std::mutex> lock(m_init);
    if (instance==nullptr) {
        
        std::shared_ptr<InitialState> instance1(new InitialState());
        instance1.swap(instance);
    }
    return instance;
    
}
