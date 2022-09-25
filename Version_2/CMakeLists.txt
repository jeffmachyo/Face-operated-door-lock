cmake_minimum_required(VERSION 3.16.3)

project(main)

include_directories(/usr/bin)
link_directories(/usr/bin)
link_libraries(sqlite3)
add_executable(${PROJECT_NAME} main.cpp initializem.cpp statemachines.cpp devicemanager.cpp shutdownm.cpp)

