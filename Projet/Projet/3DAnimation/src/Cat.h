#ifndef CAT_H
#define CAT_H


#include "../../Common/Object3D.h"
#include "../../Common/Shapes/Cubes.h"
#include "objloader.h"

class Cat : public Object3D
{
public:
    Cat();

protected:
    void drawShape( const char* shader_name );

protected:
    void anim();

protected:

    std::vector< vec3 > m_TabVertices;
    std::vector< vec2 > m_TabTexCoords;
    std::vector< vec3 > m_TabNormals;

    TwoColorCube m_Cube;
    MultipleColorCube m_Body;

};

#endif // CAT_H
