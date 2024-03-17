#pragma once

#include <glad/glad.h>

#include <memory>

class Mesh {
 public:
  ~Mesh();
  void create(GLfloat *vertices, unsigned int *indices,
              unsigned int numOfVertices, unsigned int numOfIndices);
  void render();
  void clear();

 private:
  GLuint m_vao = 0, m_vbo = 0, m_ibo = 0;
  GLsizei m_indexCount = 0;
};

using MeshPtr = std::shared_ptr<Mesh>;
