#include "Cat.h"
#include <math.h>

int g_Step = 0;

/////////////////////////////// PUBLIC ///////////////////////////////////////

//============================= LIFECYCLE ====================================

Cat::Cat()
{
    m_Obj = new ObjLoader();

    //Fill our tables
    GLboolean loaded1 = m_Obj->loadObj("../model/cat.obj",m_TabVerticesOriginal,m_TabTexCoordsOriginal,m_TabNormalsOriginal);

    GLboolean loaded2 = m_Obj->loadObj("../model/cat_walk_1.obj",m_TabVerticesWalk1,m_TabTexCoordsWalk1,m_TabNormalsWalk1);
    GLboolean loaded3 = m_Obj->loadObj("../model/cat_walk_2.obj",m_TabVerticesWalk2,m_TabTexCoordsWalk2,m_TabNormalsWalk2);

    GLboolean loaded4 = m_Obj->loadObj("../model/cat_run_1.obj",m_TabVerticesRun1,m_TabTexCoordsRun1,m_TabNormalsRun1);
    GLboolean loaded5 = m_Obj->loadObj("../model/cat_run_2.obj",m_TabVerticesRun2,m_TabTexCoordsRun2,m_TabNormalsRun2);
    GLboolean loaded6 = m_Obj->loadObj("../model/cat_run_3.obj",m_TabVerticesRun3,m_TabTexCoordsRun3,m_TabNormalsRun3);
    GLboolean loaded7 = m_Obj->loadObj("../model/cat_run_4.obj",m_TabVerticesRun4,m_TabTexCoordsRun4,m_TabNormalsRun4);

    GLboolean loaded8 = m_Obj->loadObj("../model/cat_jump_1.obj",m_TabVerticesJump1,m_TabTexCoordsJump1,m_TabNormalsJump1);
    GLboolean loaded9 = m_Obj->loadObj("../model/cat_jump_2.obj",m_TabVerticesJump2,m_TabTexCoordsJump2,m_TabNormalsJump2);
    GLboolean loaded10 = m_Obj->loadObj("../model/cat_jump_3.obj",m_TabVerticesJump3,m_TabTexCoordsJump3,m_TabNormalsJump3);
    GLboolean loaded11 = m_Obj->loadObj("../model/cat_jump_4.obj",m_TabVerticesJump4,m_TabTexCoordsJump4,m_TabNormalsJump4);
    GLboolean loaded12 = m_Obj->loadObj("../model/cat_jump_5.obj",m_TabVerticesJump5,m_TabTexCoordsJump5,m_TabNormalsJump5);
    GLboolean loaded13 = m_Obj->loadObj("../model/cat_jump_6.obj",m_TabVerticesJump6,m_TabTexCoordsJump6,m_TabNormalsJump6);
    GLboolean loaded14 = m_Obj->loadObj("../model/cat_jump_7.obj",m_TabVerticesJump7,m_TabTexCoordsJump7,m_TabNormalsJump7);

    m_TabVertices = m_TabVerticesOriginal;
    m_TabTexCoords = m_TabTexCoordsOriginal;
    m_TabNormals = m_TabNormalsOriginal;
    m_AnimType = 0;
    m_StepOfAnim = 0;
}

//============================= OPERATIONS ===================================
void Cat::walk()
{
    if (this->m_AnimType == 1)
    {
        this->m_AnimType = 0;
    }
    else
    {
        this->m_AnimType = 1;
    }
    this->m_StepOfAnim = 0;
    g_Step = 0;
}

void Cat::run()
{
    if (this->m_AnimType == 2)
    {
        this->m_AnimType = 0;
    }
    else
    {
        this->m_AnimType = 2;
    }
    this->m_StepOfAnim = 0;
    g_Step = 0;
}

void Cat::jump()
{
    if (this->m_AnimType == 3)
    {
        this->m_AnimType = 0;
    }
    else
    {
        this->m_AnimType = 3;
    }
    this->m_StepOfAnim = 0;
    g_Step = 0;
}

/////////////////////////////// PROTECTED ///////////////////////////////////

//============================= OPERATIONS ===================================

void Cat::drawShape( const char* shader_name )
{
    m_Framework->pushMatrix();
    GLuint vertex_buffer;
    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, m_TabVertices.size() * sizeof(Vec3), &m_TabVertices[0], GL_STATIC_DRAW);

    GLuint uv_buffer;
    glGenBuffers(1, &uv_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, uv_buffer);
    glBufferData(GL_ARRAY_BUFFER, m_TabTexCoords.size() * sizeof(Vec2), &m_TabTexCoords[0], GL_STATIC_DRAW);

    // 1rst attribute buffer : vertices
    GLint pos = glGetAttribLocation( m_Framework->getCurrentShaderId(), "position" );
    glEnableVertexAttribArray( pos );
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glVertexAttribPointer(
       pos,               // position
       3,                  // because of Vec3
       GL_FLOAT,           // type
       GL_FALSE,           // normalized?
       0,                  // stride
       (void*)0            // array buffer offset
    );

    GLint color = glGetAttribLocation( m_Framework->getCurrentShaderId(), "color" );
    glEnableVertexAttribArray( color );
    glBindBuffer(GL_ARRAY_BUFFER, uv_buffer);
    glVertexAttribPointer(
       color,               // color
       2,                  // size
       GL_FLOAT,           // type
       GL_FALSE,           // normalized?
       0,                  // stride
       (void*)0            // array buffer offset
    );

    // Draw the cat with TRIANGLES primitive
    glDrawArrays(GL_TRIANGLES, 0, m_TabVertices.size() );

    glDisableVertexAttribArray(pos);
    glDisableVertexAttribArray(color);
    m_Framework->popMatrix();

    switch (m_AnimType)
    {
        case 0:
            anim();
            break;
        case 1:
            walkAnim();
            break;
        case 2:
            runAnim();
            break;
        case 3:
            jumpAnim();
            break;
        default:
            break;
    }
}

void Cat::anim()
{
    if (g_Step == 40)
    {
        m_TabVertices = m_TabVerticesOriginal;
        return;
    }

    //We finish another anim
    this->setTabVertices(m_TabVertices, m_TabVerticesOriginal, g_Step/40.);
    g_Step++;
}

void Cat::walkAnim()
{
    if (m_StepOfAnim == 0)
    {
        //We start to walk
        if (g_Step == 18)
        {
            g_Step = 0;
            m_StepOfAnim = 1;
        }
        else
        {
            this->setTabVertices(m_TabVerticesOriginal, m_TabVerticesWalk1, g_Step/18.);
            g_Step++;
            return;
        }
    }
    if (g_Step == 36) {
        if (m_StepOfAnim == 1)
        {
            m_StepOfAnim = 2;
        }
        else
        {
            m_StepOfAnim = 1;
        }
        g_Step = 0;
    }
    if (m_StepOfAnim == 1)
    {
        this->setTabVertices(m_TabVerticesWalk1, m_TabVerticesWalk2, g_Step/36.);
    }
    else
    {
        this->setTabVertices(m_TabVerticesWalk2, m_TabVerticesWalk1, g_Step/36.);
    }

    g_Step++;
}

void Cat::runAnim()
{
    if (m_StepOfAnim == 0)
    {
        //We start to run
        if (g_Step == 6)
        {
            g_Step = 0;
            m_StepOfAnim = 1;
        }
        else
        {
            this->setTabVertices(m_TabVerticesOriginal, m_TabVerticesRun1, g_Step/6.);
            g_Step++;
            return;
        }
    }
    if (g_Step == 12)
    {
        m_StepOfAnim++;
        if (m_StepOfAnim == 5)
        {
            m_StepOfAnim = 1;
        }
        g_Step = 0;
    }
    if (m_StepOfAnim == 1)
    {
        this->setTabVertices(m_TabVerticesRun1, m_TabVerticesRun2, g_Step/12.);
    }
    else if (m_StepOfAnim == 2)
    {
        this->setTabVertices(m_TabVerticesRun2, m_TabVerticesRun3, g_Step/12.);
    }
    else if (m_StepOfAnim == 3)
    {
        this->setTabVertices(m_TabVerticesRun3, m_TabVerticesRun4, g_Step/12.);
    }
    else
    {
        this->setTabVertices(m_TabVerticesRun4, m_TabVerticesRun1, g_Step/12.);
    }

    g_Step++;
}

void Cat::jumpAnim()
{
    if (m_StepOfAnim == 0)
    {
        //We start to walk
        if (g_Step == 6)
        {
            g_Step = 0;
            m_StepOfAnim = 1;
        }
        else
        {
            this->setTabVertices(m_TabVerticesOriginal, m_TabVerticesJump1, g_Step/6.);
            g_Step++;
            return;
        }
    }
    if (g_Step == 12)
    {
        m_StepOfAnim++;
        if (m_StepOfAnim == 8)
        {
            m_StepOfAnim = 1;
        }
        g_Step = 0;
    }
    if (m_StepOfAnim == 1)
    {
        this->setTabVertices(m_TabVerticesJump1, m_TabVerticesJump2, g_Step/12.);
    }
    else if (m_StepOfAnim == 2)
    {
        this->setTabVertices(m_TabVerticesJump2, m_TabVerticesJump3, g_Step/12.);
    }
    else if (m_StepOfAnim == 3)
    {
        this->setTabVertices(m_TabVerticesJump3, m_TabVerticesJump4, g_Step/12.);
    }
    else if (m_StepOfAnim == 4)
    {
        this->setTabVertices(m_TabVerticesJump4, m_TabVerticesJump5, g_Step/12.);
    }
    else if (m_StepOfAnim == 5)
    {
        this->setTabVertices(m_TabVerticesJump5, m_TabVerticesJump6, g_Step/12.);
    }
    else if (m_StepOfAnim == 6)
    {
        this->setTabVertices(m_TabVerticesJump6, m_TabVerticesJump7, g_Step/12.);
    }
    else
    {
        this->setTabVertices(m_TabVerticesJump7, m_TabVerticesJump1, g_Step/12.);
    }

    g_Step++;
}

//============================= ATTRIBUTE ACCESSORS ==========================

void Cat::setTabVertices(std::vector< Vec3 > origin, std::vector< Vec3 > destination, float completion)
{
    //LERP method : start + (end - start)*percent

    for (int i = 0; i < m_TabVertices.size(); i++)
    {
        m_TabVertices[i] = origin[i] + (destination[i] - origin[i])*completion;
    }
}
