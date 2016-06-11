#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <GL/glew.h>
#define QT_NO_OPENGL_ES_2

#include "../../Common/Types.h"
#include "../../Common/Object3D.h"
#include <vector>
#include <../../Common/Vectors.h>
#include <iostream>

class ObjLoader
{
    public:

        //============================= LIFECYCLE ====================================
        /**************************************************************************
        * Name: ObjLoader
        * Description: the default constructor
        **************************************************************************/
        ObjLoader();

        //============================= OPERATIONS ===================================
        /**************************************************************************
        * Name: loadObj
        * Description: load a .obj file and parse it
        * Inputs:
            - path: the path of the .obj file
            - m_TabVertices: the table of vertices
            - m_TabTexCoords: the table of texture coordinates
            - m_TabNormals: the table of normals
        * Returns:
            - value: description of the returned value
        **************************************************************************/
        bool loadObj(const char* path,
                      std::vector<Vec3>& tabVertices,
                      std::vector<Vec2>& tabTexCoords,
                      std::vector<Vec3>& tabNormals);
};

#endif // OBJLOADER_H
