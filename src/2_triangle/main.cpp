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
#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../0_common/shader/GLSLShader.hpp"
#include "../0_common/OGLConstants.hpp"

#define GL_CHECK_ERRORS assert(glGetError()== GL_NO_ERROR);

GLSLShader shader;

GLuint vaoID;
GLuint vboVerticesID;
GLuint vboIndicesID;

struct Vertex {
    glm::vec3 position;
    glm::vec3 color;
};

Vertex vertices[3];
GLushort indices[3];

glm::mat4  P = glm::mat4(1);
glm::mat4 MV = glm::mat4(1);

void OnInit() {
    GL_CHECK_ERRORS
    shader.LoadFromFile(GL_VERTEX_SHADER, OGL::Constants::Glut::Shaders::vertPath);
    shader.LoadFromFile(GL_FRAGMENT_SHADER, OGL::Constants::Glut::Shaders::fragPath);
    shader.CreateAndLinkProgram();
    shader.Use();
    shader.AddAttribute("vVertex");
    shader.AddAttribute("vColor");
    shader.AddUniform("MVP");
    shader.UnUse();

    GL_CHECK_ERRORS

    vertices[0].color=glm::vec3(1,0,0);
    vertices[1].color=glm::vec3(0,1,0);
    vertices[2].color=glm::vec3(0,0,1);

    vertices[0].position=glm::vec3(-1,-1,0);
    vertices[1].position=glm::vec3(0,1,0);
    vertices[2].position=glm::vec3(1,-1,0);

    indices[0] = 0;
    indices[1] = 1;
    indices[2] = 2;

    GL_CHECK_ERRORS

    glGenVertexArrays(1, &vaoID);
    glGenBuffers(1, &vboVerticesID);
    glGenBuffers(1, &vboIndicesID);
    GLsizei stride = sizeof(Vertex);

    glBindVertexArray(vaoID);

    glBindBuffer (GL_ARRAY_BUFFER, vboVerticesID);
    glBufferData (GL_ARRAY_BUFFER, sizeof(vertices), &vertices[0], GL_STATIC_DRAW);
    GL_CHECK_ERRORS
    glEnableVertexAttribArray(shader["vVertex"]);
    glVertexAttribPointer(shader["vVertex"], 3, GL_FLOAT, GL_FALSE,stride,nullptr);
    GL_CHECK_ERRORS
    glEnableVertexAttribArray(shader["vColor"]);
    glVertexAttribPointer(shader["vColor"], 3, GL_FLOAT, GL_FALSE,stride, reinterpret_cast<const GLvoid*>(offsetof(Vertex, color)));
    GL_CHECK_ERRORS
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboIndicesID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices[0], GL_STATIC_DRAW);
    GL_CHECK_ERRORS

}

void OnShutdown() {
    shader.DeleteShaderProgram();

    glDeleteBuffers(1, &vboVerticesID);
    glDeleteBuffers(1, &vboIndicesID);
    glDeleteVertexArrays(1, &vaoID);

    std::cout << "OnShutdown\n";
}

void OnResize(int w, int h) {
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    P = glm::ortho(-1,1,-1,1);
}

void OnRender() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    shader.Use();
    glUniformMatrix4fv(shader("MVP"), 1, GL_FALSE, glm::value_ptr(P*MV));
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, nullptr);
    shader.UnUse();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitContextVersion (3, 3);
    glutInitContextFlags (GLUT_CORE_PROFILE | GLUT_DEBUG);
    glutInitWindowSize(OGL::Constants::Window::Width, OGL::Constants::Window::Height);
    glutCreateWindow("Triangle");

    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (GLEW_OK != err)	{
        err = glGetError();
        GL_CHECK_ERRORS
    }

    OnInit();
    glutCloseFunc(OnShutdown);
    glutDisplayFunc(OnRender);
    glutReshapeFunc(OnResize);

    glutMainLoop();


    return 0;
}
