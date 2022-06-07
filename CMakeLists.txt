cmake_minimum_required(VERSION 3.16.3)

project(main)

include_directories(/usr/bin)
link_directories(/usr/bin)
link_libraries(sqlite3)
add_executable(${PROJECT_NAME} main.cpp sensor.cpp camera.cpp pwm_out.cpp cloud_service.cpp db_store.cpp base64.cpp)

