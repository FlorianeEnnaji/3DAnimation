#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <GL/glew.h>
#define QT_NO_OPENGL_ES_2

#include "../../Common/Types.h"
#include "../../Common/Object3D.h"
#include <vector>
#include <../../Common/Vectors.h>
#include <iostream>

struct vec3{
float x;
float y;
float z;
};
struct vec2{
float x;
float y;
};

class ObjLoader
{
public:

     bool loadOBJ(
             const char * path,
              std::vector<vec3> & m_TabVertices,
              std::vector<vec2> & m_TabNormals,
              std::vector<vec3> & m_TabTexCoords

         );
};

#endif // OBJLOADER_H
