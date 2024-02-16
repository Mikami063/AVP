# Advanced Video Player by Qingyun Yang

cmake_minimum_required(VERSION 3.14)
project(AVP C CXX)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/glfw)

if(APPLE)
    list(APPEND EXTRA_LIBS "-framework OpenGL")
endif()

add_executable(AVP src/main.cpp)
target_link_libraries(AVP glfw ${EXTRA_LIBS})