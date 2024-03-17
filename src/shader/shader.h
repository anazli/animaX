#pragma once

#include <glad/glad.h>

#include <string>

class Shader {
 public:
  ~Shader();
  void createFromString(const std::string& vertexCode,
                        const std::string& fragmentCode);
  void createFromFile(const std::string& vertexLoc,
                      const std::string& fragmentLoc);
  GLuint getProjection() const;
  GLuint getModel() const;
  void use();
  void clear();

 private:
  void CompileShader(const std::string& vertexCode,
                     const std::string& fragmentCode);
  void addShader(GLuint programId, const std::string& shaderCode,
                 GLenum shaderType);

  std::string read(const std::string& fileLoc);

  GLuint m_shaderID, m_uniformProj, m_uniformModel;
};
