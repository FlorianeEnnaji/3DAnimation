#include "Cat.h"
#include <math.h>

Cat::Cat()
{
    //Fill our tables
    ObjLoader obj;
    GLboolean loaded = obj.loadOBJ("/Users/florianeennaji/Documents/IN55/3DAnimation/Projet/Projet/3DAnimation/model/cat.obj",m_TabVertices,m_TabTexCoords,m_TabNormals);
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

}


void
Cat::anim()
{

}
