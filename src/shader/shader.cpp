#include "shader/shader.h"

#include <cstring>
#include <fstream>
#include <iostream>

Shader::~Shader() { clear(); }

void Shader::createFromString(const std::string &vertexCode,
                              const std::string &fragmentCode) {
  CompileShader(vertexCode, fragmentCode);
}

void Shader::createFromFile(const std::string &vertexLoc,
                            const std::string &fragmentLoc) {
  CompileShader(read(vertexLoc), read(fragmentLoc));
}

GLuint Shader::getProjection() const { return m_uniformProj; }

GLuint Shader::getModel() const { return m_uniformModel; }

void Shader::use() { glUseProgram(m_shaderID); }

void Shader::clear() {
  if (m_shaderID != 0) {
    glDeleteProgram(m_shaderID);
    m_shaderID = 0;
  }
  m_uniformProj = 0;
  m_uniformModel = 0;
}

void Shader::CompileShader(const std::string &vertexCode,
                           const std::string &fragmentCode) {
  m_shaderID = glCreateProgram();

  if (!m_shaderID) {
    std::cout << "Error creating shader program!" << std::endl;
    return;
  }

  addShader(m_shaderID, vertexCode, GL_VERTEX_SHADER);
  addShader(m_shaderID, fragmentCode, GL_FRAGMENT_SHADER);

  GLint res = 0;
  GLchar log[1024] = {0};

  glLinkProgram(m_shaderID);
  glGetProgramiv(m_shaderID, GL_LINK_STATUS, &res);
  if (!res) {
    glGetProgramInfoLog(m_shaderID, sizeof(log), nullptr, log);
    std::cout << "Error linking shader program!" << log << std::endl;
    return;
  }

  glValidateProgram(m_shaderID);
  glGetProgramiv(m_shaderID, GL_VALIDATE_STATUS, &res);
  if (!res) {
    glGetProgramInfoLog(m_shaderID, sizeof(log), nullptr, log);
    std::cout << "Error validating shader program!" << log << std::endl;
    return;
  }

  m_uniformProj = glGetUniformLocation(m_shaderID, "projection");
  m_uniformModel = glGetUniformLocation(m_shaderID, "model");
}

void Shader::addShader(GLuint programId, const std::string &shaderCode,
                       GLenum shaderType) {
  GLuint s = glCreateShader(shaderType);

  const GLchar *c[1];
  c[0] = shaderCode.c_str();

  GLint codeLength[1];
  codeLength[0] = std::strlen(shaderCode.c_str());

  glShaderSource(s, 1, c, codeLength);
  glCompileShader(s);

  GLint res = 0;
  GLchar log[1024] = {0};
  glGetShaderiv(s, GL_COMPILE_STATUS, &res);
  if (!res) {
    glGetShaderInfoLog(s, sizeof(log), nullptr, log);
    std::cout << "Error compiling" << shaderType << "shader!" << log
              << std::endl;
    return;
  }

  glAttachShader(programId, s);
}

std::string Shader::read(const std::string &fileLoc) {
  std::string content;
  std::ifstream fileStream(fileLoc, std::ios::in);

  if (!fileStream.is_open()) {
    std::cout << "Error reading from file:" << fileLoc << std::endl;
    return std::string();
  }

  std::string line;
  while (!fileStream.eof()) {
    std::getline(fileStream, line);
    content.append(line + "\n");
  }

  fileStream.close();
  return content;
}
