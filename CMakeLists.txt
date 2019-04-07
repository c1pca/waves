cmake_minimum_required(VERSION 3.13)
project(ECG C)

add_definitions(-DGL_SILENCE_DEPRECATION)
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
include_directories(
        ${OPENGL_INCLUDE_DIR}
        ${SDL2_INCLUDE_DIRS}
)

set(CMAKE_C_STANDARD 99)

add_executable(ECG main.c init.c init.h display.c display.h shaders.c shaders.h defs.h buffer.c buffer.h data.c data.h fragment_shader.c vertex_shader.c)
target_link_libraries(ECG ${SDL2_LIBRARIES}
        ${OPENGL_LIBRARIES})