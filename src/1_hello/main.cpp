/************************************************************
 *
 * file: main.cpp
 * brief: App entry point
 *
 * Credits: This code/part of it, was originally presented in
 * "OpenGL Cookbook" by Muhammad Mobeen Movania. Yet this code
 * is/might be higlhy changed/adopted to my needs.
 * See README.md for references.
 *
 ************************************************************/

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <random>
#include <functional>

#include "OGLConstants.hpp"

void onRedraw() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(1,1,1,0);
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitContextVersion (OGL::Constants::Glut::Version::Major, OGL::Constants::Glut::Version::Minor);
    glutInitContextFlags (GLUT_CORE_PROFILE | GLUT_DEBUG);
    glutInitContextProfile(GLUT_FORWARD_COMPATIBLE);
    glutInitWindowSize(OGL::Constants::Window::Width, OGL::Constants::Window::Height);
    glutCreateWindow("1: Hello OpenGL");

    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (GLEW_OK != err)	{
        std::cerr << "Can't get GLEW info: "<< glewGetErrorString(err) << "\n";
    } else {
        std::cout << "GLEW: " << glewGetString(GLEW_VERSION) << "\n";
        std::cout << "Video card:: "<< glGetString (GL_VENDOR) << "\n";
        std::cout << "Renderer: "<< glGetString (GL_RENDERER) << "\n";
        std::cout << "Version: "<< glGetString (GL_VERSION) << "\n";
        std::cout << "GLSL: "<< glGetString (GL_SHADING_LANGUAGE_VERSION) << "\n";
    }

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0,255);

    glClearColor(1,0,0,0);

    glutDisplayFunc(onRedraw);

    glutMainLoop();

    return 0;
}
