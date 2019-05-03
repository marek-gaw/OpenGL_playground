cmake_minimum_required(VERSION 3.2)
project(OpenGL_Playground)

set(CMAKE_CXX_STANDARD 11)

# Add sources
file(GLOB_RECURSE SOURCES
        ${CMAKE_SOURCE_DIR}/src/*.c
        ${CMAKE_SOURCE_DIR}/src/*.cpp)

file(GLOB_RECURSE HEADERS
    ${CMAKE_SOURCE_DIR}/src/*.hpp)

set(CMAKE_MODULE_PATH /usr/local/lib/cmake)
set(CMAKE_MODULE_PATH /usr/local/lib/x86_64-linux-gnu/cmake/glm)
set(CMAKE_PREFIX_PATH /usr/local/lib/cmake/glfw)


find_package (OpenGL REQUIRED)
find_package (glfw3 REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package (GLEW REQUIRED STATIC)

include_directories(${GLUT_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS} ${GLEW_LIBRARY_DIRS} ${OPENGL_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS} ${GLEW_DEFINITIONS} ${OPENGL_DEFINITIONS})

# executables
set(SAMPLE 1_hello)

set(NAME 1_hello)

add_executable(${NAME} ${SOURCES} ${HEADERS})

target_link_libraries (${NAME} ${OPENGL_LIBRARIES} ${GLFW3_LIBRARY} libglut.so
        ${GLEW_LIBRARY} Xxf86vm pthread Xrandr Xinerama Xi Xcursor)

