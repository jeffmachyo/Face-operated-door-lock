#ifndef CAM_PERIPHERAL
#define CAM_PERIPHERAL

#include <string>
#include <memory>
#include <mutex>
#include <signal.h>

class Camera {
    private:
        static std::shared_ptr<Camera> instance;
        static std::mutex m_cam;
        Camera();
        std::string file_name;
        pid_t pid = 0;

    public:
        
        bool take_pic(const std::string& file_name);
        bool stop_pic();
        static std::shared_ptr<Camera> getInstance();
};






#endif

