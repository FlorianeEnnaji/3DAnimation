#include "Cat.h"
#include <math.h>

const GLfloat g_PawAperture = 10.0f;
const GLfloat g_PawAngleSpeed = 0.2f;

Cat::Cat()
{
    m_PawFrontLeftAngle = 0.0f;
    m_PawFrontRightAngle = 10.0f;
    m_PawBackLeftAngle = 5.0f;
    m_PawBackRightAngle = 20.0f;
}

void
Cat::drawShape( const char* shader_name )
{
    anim();

    // Head
    m_Framework->pushMatrix();
    m_Framework->scale( 2.0f, 2.0f, 2.0f );
    m_Cube.draw( shader_name );
    m_Framework->popMatrix();

    // Body
    m_Framework->translate( 3.0f, -2.0f, 0.0f );
    m_Framework->pushMatrix();
    m_Framework->scale( 4.0f, 2.0f, 2.0f );
    m_Body.draw( shader_name );
    m_Framework->popMatrix();

    // Paw left front
    m_Framework->pushMatrix();
    m_Framework->translate( -1.5f, -2.5f, 0.5f );
    m_Framework->rotate( g_PawAperture*sin(m_PawFrontLeftAngle), 0.0f, 0.0f, 1.0f );
    m_Framework->scale( 0.5f, 3.0f, 0.5f );
    m_Cube.draw( shader_name );
    m_Framework->popMatrix();

    // Paw right front
    m_Framework->pushMatrix();
    m_Framework->translate( -1.5f, -2.5f, -0.5f );
    m_Framework->rotate( g_PawAperture*sin(m_PawFrontRightAngle), 0.0f, 0.0f, 1.0f );
    m_Framework->scale( 0.5f, 3.0f, 0.5f );
    m_Cube.draw( shader_name );
    m_Framework->popMatrix();

    // Paw right back
    m_Framework->pushMatrix();
    m_Framework->translate( +1.5f, -2.5f, -0.5f );
    m_Framework->rotate( g_PawAperture*sin(m_PawBackRightAngle), 0.0f, 0.0f, 1.0f );
    m_Framework->scale( 0.5f, 3.0f, 0.5f );
    m_Cube.draw( shader_name );
    m_Framework->popMatrix();

    // Paw left back
    m_Framework->pushMatrix();
    m_Framework->translate( +1.5f, -2.5f, 0.5f );
    m_Framework->rotate( g_PawAperture*sin(m_PawBackLeftAngle), 0.0f, 0.0f, 1.0f );
    m_Framework->scale( 0.5f, 3.0f, 0.5f );
    m_Cube.draw( shader_name );
    m_Framework->popMatrix();

    // Queue
     m_Framework->pushMatrix();
    m_Framework->translate( 2.5f, 0.0f, 0.0f );
    m_Framework->scale( 2.5f, 0.5f, 0.5f );
    m_Cube.draw( shader_name );
    m_Framework->popMatrix();

}


void
Cat::anim()
{
    m_PawFrontLeftAngle += g_PawAngleSpeed;
    m_PawFrontRightAngle += g_PawAngleSpeed;
    m_PawBackLeftAngle += g_PawAngleSpeed;
    m_PawBackRightAngle += g_PawAngleSpeed;
}
