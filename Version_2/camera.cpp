#include "camera.hpp"
#include <unistd.h>


Camera::Camera() {

}

bool Camera::take_pic(const std::string& file_name) {
    if (pid = fork()==0) {
        execl("/usr/bin/raspistill",
              "/usr/bin/raspistill",
              "-n",
              "-vf",
              "-o",
              file_name.c_str(),
              NULL);

        return true;    
    }
    return false;
}

bool Camera::stop_pic() {
    if (pid) {
        kill(pid,10);
        // sleep(1);
        // kill(pid,10);
        return true;
    }
    return false;
}

std::shared_ptr<Camera> Camera::instance{nullptr};
std::mutex Camera::m_cam;

std::shared_ptr<Camera> Camera::getInstance() {
    std::lock_guard<std::mutex> lock(m_cam);
    if (instance==nullptr) {
        
        std::shared_ptr<Camera> instance1(new Camera());
        instance1.swap(instance);
    }
    return instance;
    
}