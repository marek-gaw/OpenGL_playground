cmake_minimum_required(VERSION 3.2)
project(OpenGL_Playground)

set(CMAKE_CXX_STANDARD 11)



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

# executables - names has to be exactly the same as dir names
set(SAMPLES 1_hello 2_triangle)

foreach (SAMPLE ${SAMPLES})

    # Add sources and headers
    file(GLOB_RECURSE SOURCES
            "${CMAKE_SOURCE_DIR}/src/${SAMPLE}/*.c"
            "${CMAKE_SOURCE_DIR}/src/${SAMPLE}/*.cpp")
    file(GLOB_RECURSE HEADERS
       "${CMAKE_SOURCE_DIR}/src/${SAMPLE}/*.hpp")

    add_executable(${SAMPLE} ${SOURCES} ${HEADERS})
    target_link_libraries (${SAMPLE} ${OPENGL_LIBRARIES} ${GLFW3_LIBRARY} libglut.so
            ${GLEW_LIBRARY} Xxf86vm pthread Xrandr Xinerama Xi Xcursor)

endforeach(SAMPLE)






