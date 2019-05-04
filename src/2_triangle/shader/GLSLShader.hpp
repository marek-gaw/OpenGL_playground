/************************************************************
 *
 * file: GLSLShader.hpp
 * brief: Generic GLSL shader class
 *
 * Credits: This code/part of it, was originally presented in
 * "OpenGL Cookbook" by Muhammad Mobeen Movania. Yet this code
 * is/might be higlhy changed/adopted to my needs.
 * See README.md for references.
 *
 ************************************************************/

#ifndef SRC_2_TRIANGLE_SHADER_GLSLSHADER_HPP
#define SRC_2_TRIANGLE_SHADER_GLSLSHADER_HPP

#include <map>
#include <string>
#include <array>

#include <GL/glew.h>

class GLSLShader {
public:
    GLSLShader();
    void LoadFromString(GLenum whichShader, const std::string& source);
    void LoadFromFile(GLenum whichShader, const std:: string& filename);
    void CreateAndLinkProgram();
    void Use();
    void UnUse();
    void AddAttribute(const std::string& attribute);
    void AddUniform(const std::string& uniform);

    GLuint operator[](const std::string& attribute);
    GLuint operator()(const std::string& uniform);
    void DeleteShaderProgram();

private:
    enum ShaderType {VERTEX_SHADER, FRAGMENT_SHADER, GEOMETRY_SHADER};
    GLuint	_program;
    int _totalShaders;
    std::array<GLuint,3>_shaders; //0->shader wierzcho³ków, 1->shader fragmentów, 2->shader geometrii
    std::map<std::string,GLuint> _attributeList;
    std::map<std::string,GLuint> _uniformLocationList;

};

#endif // SRC_2_TRIANGLE_SHADER_GLSLSHADER_HPP
