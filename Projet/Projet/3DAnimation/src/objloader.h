#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <GL/glew.h>
#define QT_NO_OPENGL_ES_2

#include "Types.h"
#include "Object3D.h"
#include <vector>
#include <Vectors.h>
#include <iostream>

struct vec2
{
    float x;
    float y;
};

struct vec3
{
    float x;
    float y;
    float z;
};

class ObjLoader
{
    public:

         bool loadObj(const char* path,
                      std::vector<vec3>& m_TabVertices,
                      std::vector<vec2>& m_TabNormals,
                      std::vector<vec3>& m_TabTexCoords);
};

#endif // OBJLOADER_H
