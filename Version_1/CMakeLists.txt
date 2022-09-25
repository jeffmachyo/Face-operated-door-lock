cmake_minimum_required(VERSION 3.16.3)

project(smain)

add_executable(${PROJECT_NAME} smain.c sensor.c camera.c pwm_out.c cloud_service.c)

