#ifndef CAT_H
#define CAT_H


#include "Object3D.h"
#include "Shapes/Cubes.h"

class Cat : public Object3D
{
public:
    Cat();

protected:
    void drawShape( const char* shader_name );

protected:
    void anim();

protected:
    TwoColorCube m_Cube;
    MultipleColorCube m_Body;

    GLfloat m_PawFrontLeftAngle;
    GLfloat m_PawFrontRightAngle;
    GLfloat m_PawBackLeftAngle;
    GLfloat m_PawBackRightAngle;

};

#endif // CAT_H
