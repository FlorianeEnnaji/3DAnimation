#include "Cat.h"
#include <math.h>

int step = 0;

Cat::Cat()
{
    obj = new ObjLoader();
    //Fill our tables
    GLboolean loaded1 = obj->loadOBJ("../model/cat.obj",m_TabVerticesOriginal,m_TabTexCoordsOriginal,m_TabNormalsOriginal);

    GLboolean loaded2 = obj->loadOBJ("../model/cat_walk_1.obj",m_TabVertices_walk_1,m_TabTexCoords_walk_1,m_TabNormals_walk_1);
    GLboolean loaded3 = obj->loadOBJ("../model/cat_walk_2.obj",m_TabVertices_walk_2,m_TabTexCoords_walk_2,m_TabNormals_walk_2);

    GLboolean loaded4 = obj->loadOBJ("../model/cat_run_1.obj",m_TabVertices_run_1,m_TabTexCoords_run_1,m_TabNormals_run_1);
    GLboolean loaded5 = obj->loadOBJ("../model/cat_run_2.obj",m_TabVertices_run_2,m_TabTexCoords_run_2,m_TabNormals_run_2);
    GLboolean loaded6 = obj->loadOBJ("../model/cat_run_3.obj",m_TabVertices_run_3,m_TabTexCoords_run_3,m_TabNormals_run_3);
    GLboolean loaded7 = obj->loadOBJ("../model/cat_run_4.obj",m_TabVertices_run_4,m_TabTexCoords_run_4,m_TabNormals_run_4);

    GLboolean loaded8 = obj->loadOBJ("../model/cat_jump_1.obj",m_TabVertices_jump_1,m_TabTexCoords_jump_1,m_TabNormals_jump_1);
    GLboolean loaded9 = obj->loadOBJ("../model/cat_jump_2.obj",m_TabVertices_jump_2,m_TabTexCoords_jump_2,m_TabNormals_jump_2);
    GLboolean loaded10 = obj->loadOBJ("../model/cat_jump_3.obj",m_TabVertices_jump_3,m_TabTexCoords_jump_3,m_TabNormals_jump_3);
    GLboolean loaded11 = obj->loadOBJ("../model/cat_jump_4.obj",m_TabVertices_jump_4,m_TabTexCoords_jump_4,m_TabNormals_jump_4);
    GLboolean loaded12 = obj->loadOBJ("../model/cat_jump_5.obj",m_TabVertices_jump_5,m_TabTexCoords_jump_5,m_TabNormals_jump_5);
    GLboolean loaded13 = obj->loadOBJ("../model/cat_jump_6.obj",m_TabVertices_jump_6,m_TabTexCoords_jump_6,m_TabNormals_jump_6);
    GLboolean loaded14 = obj->loadOBJ("../model/cat_jump_7.obj",m_TabVertices_jump_7,m_TabTexCoords_jump_7,m_TabNormals_jump_7);

    m_TabVertices = m_TabVerticesOriginal;
    m_TabTexCoords = m_TabTexCoordsOriginal;
    m_TabNormals = m_TabNormalsOriginal;
    m_animType = 0;
    m_stepOfAnim = 0;
}

void
Cat::drawShape( const char* shader_name )
{
    m_Framework->pushMatrix();
    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, m_TabVertices.size() * sizeof(vec3), &m_TabVertices[0], GL_STATIC_DRAW);

    GLuint uvbuffer;
    glGenBuffers(1, &uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, m_TabTexCoords.size() * sizeof(vec2), &m_TabTexCoords[0], GL_STATIC_DRAW);

    // 1rst attribute buffer : vertices
    GLint var1 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "position" );
    glEnableVertexAttribArray( var1 );
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
       var1,               // position
       3,                  // because of vec3
       GL_FLOAT,           // type
       GL_FALSE,           // normalized?
       0,                  // stride
       (void*)0            // array buffer offset
    );

    GLint var2 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "color" );
    glEnableVertexAttribArray( var2 );
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glVertexAttribPointer(
       var2,               // color
       2,                  // size
       GL_FLOAT,           // type
       GL_FALSE,           // normalized?
       0,                  // stride
       (void*)0            // array buffer offset
    );

    // Draw the cat with TRIANGLES primitive
    glDrawArrays(GL_TRIANGLES, 0, m_TabVertices.size() );

    glDisableVertexAttribArray(var1);
    glDisableVertexAttribArray(var2);
    m_Framework->popMatrix();

    switch(m_animType) {
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

void
Cat::setTabVertices(std::vector< vec3 > origin, std::vector< vec3 > destination, int interval)
{
    for (int i = 0; i < m_TabVertices.size(); i++) {
        m_TabVertices[i].x += (destination[i].x - origin[i].x) / interval;
        m_TabVertices[i].y += (destination[i].y - origin[i].y) / interval;
        m_TabVertices[i].z += (destination[i].z - origin[i].z) / interval;
    }
}

void
Cat::anim()
{
    if (step == 40) {
        m_TabVertices = m_TabVerticesOriginal;
        return;
    }
    //We finish another anim
    this->setTabVertices(m_TabVertices, m_TabVerticesOriginal, 40);
    step++;

}

void
Cat::walkAnim()
{
    if (m_stepOfAnim == 0) {
        //We start to walk
        if (step == 25) {
            step = 0;
            m_stepOfAnim = 1;
        } else {
            this->setTabVertices(m_TabVerticesOriginal, m_TabVertices_walk_1, 25);
            step++;
            return;
        }
    }
    if (step == 50) {
        if (m_stepOfAnim == 1) {
            m_stepOfAnim = 2;
        } else {
            m_stepOfAnim = 1;
        }
        step = 0;
    }
    if (m_stepOfAnim == 1) {
        this->setTabVertices(m_TabVertices_walk_1, m_TabVertices_walk_2, 50);
    } else {
        this->setTabVertices(m_TabVertices_walk_2, m_TabVertices_walk_1, 50);
    }

    step++;

}

void
Cat::runAnim()
{
    if (m_stepOfAnim == 0) {
        //We start to run
        if (step == 12) {
            step = 0;
            m_stepOfAnim = 1;
        } else {
            this->setTabVertices(m_TabVerticesOriginal, m_TabVertices_run_1, 12);
            step++;
            return;
        }
    }
    if (step == 25) {
        m_stepOfAnim++;
        if (m_stepOfAnim == 5) {
            m_stepOfAnim = 1;
        }
        step = 0;
    }
    if (m_stepOfAnim == 1) {
        this->setTabVertices(m_TabVertices_run_1, m_TabVertices_run_2, 25);
    } else if (m_stepOfAnim == 2) {
        this->setTabVertices(m_TabVertices_run_2, m_TabVertices_run_3, 25);
    } else if (m_stepOfAnim == 3) {
        this->setTabVertices(m_TabVertices_run_3, m_TabVertices_run_4, 25);
    } else {
        this->setTabVertices(m_TabVertices_run_4, m_TabVertices_run_1, 25);
    }

    step++;
}

void
Cat::jumpAnim()
{
    if (m_stepOfAnim == 0) {
        //We start to walk
        if (step == 12) {
            step = 0;
            m_stepOfAnim = 1;
        } else {
            this->setTabVertices(m_TabVerticesOriginal, m_TabVertices_jump_1, 12);
            step++;
            return;
        }
    }
    if (step == 25) {
        m_stepOfAnim++;
        if (m_stepOfAnim == 8) {
            m_stepOfAnim = 1;
        }
        step = 0;
    }
    if (m_stepOfAnim == 1) {
        this->setTabVertices(m_TabVertices_jump_1, m_TabVertices_jump_2, 25);
    } else if (m_stepOfAnim == 2) {
        this->setTabVertices(m_TabVertices_jump_2, m_TabVertices_jump_3, 25);
    } else if (m_stepOfAnim == 3) {
        this->setTabVertices(m_TabVertices_jump_3, m_TabVertices_jump_4, 25);
    } else if (m_stepOfAnim == 4) {
        this->setTabVertices(m_TabVertices_jump_4, m_TabVertices_jump_5, 25);
    } else if (m_stepOfAnim == 5) {
        this->setTabVertices(m_TabVertices_jump_5, m_TabVertices_jump_6, 25);
    } else if (m_stepOfAnim == 6) {
        this->setTabVertices(m_TabVertices_jump_6, m_TabVertices_jump_7, 25);
    } else {
        this->setTabVertices(m_TabVertices_jump_7, m_TabVertices_jump_1, 25);
    }

    step++;
}

void
Cat::walk()
{
    if (this->m_animType == 1) {
        this->m_animType = 0;
    } else {
        this->m_animType = 1;
    }
    this->m_stepOfAnim = 0;
    step = 0;

}

void
Cat::run()
{
    if (this->m_animType == 2) {
        this->m_animType = 0;
    } else {
        this->m_animType = 2;
    }
    this->m_stepOfAnim = 0;
    step = 0;
}

void
Cat::jump()
{
    if (this->m_animType == 3) {
        this->m_animType = 0;
    } else {
        this->m_animType = 3;
    }
    this->m_stepOfAnim = 0;
    step = 0;
}
