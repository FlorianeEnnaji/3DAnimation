#ifndef CAT_H
#define CAT_H


#include "Object3D.h"
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

};

#endif // CAT_H
