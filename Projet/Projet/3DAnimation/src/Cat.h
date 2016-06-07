#ifndef CAT_H
#define CAT_H


#include "../../Common/Object3D.h"
#include "objloader.h"

class Cat : public Object3D
{
public:
    Cat();
    void walk();
    void run();
    void jump();

protected:
    void drawShape( const char* shader_name );

protected:
    void anim();
    void walkAnim();
    void runAnim();
    void jumpAnim();
    void setTabVertices(std::vector< vec3 > origin, std::vector< vec3 > destination, int interval);

protected:

    int m_animType;
    int m_stepOfAnim;
    ObjLoader* obj;

    std::vector< vec3 > m_TabVerticesOriginal;
    std::vector< vec2 > m_TabTexCoordsOriginal;
    std::vector< vec3 > m_TabNormalsOriginal;

    std::vector< vec3 > m_TabVertices;
    std::vector< vec2 > m_TabTexCoords;
    std::vector< vec3 > m_TabNormals;


    std::vector< vec3 > m_TabVertices_walk_1;
    std::vector< vec2 > m_TabTexCoords_walk_1;
    std::vector< vec3 > m_TabNormals_walk_1;

    std::vector< vec3 > m_TabVertices_walk_2;
    std::vector< vec2 > m_TabTexCoords_walk_2;
    std::vector< vec3 > m_TabNormals_walk_2;


    std::vector< vec3 > m_TabVertices_run_1;
    std::vector< vec2 > m_TabTexCoords_run_1;
    std::vector< vec3 > m_TabNormals_run_1;

    std::vector< vec3 > m_TabVertices_run_2;
    std::vector< vec2 > m_TabTexCoords_run_2;
    std::vector< vec3 > m_TabNormals_run_2;

    std::vector< vec3 > m_TabVertices_run_3;
    std::vector< vec2 > m_TabTexCoords_run_3;
    std::vector< vec3 > m_TabNormals_run_3;

    std::vector< vec3 > m_TabVertices_run_4;
    std::vector< vec2 > m_TabTexCoords_run_4;
    std::vector< vec3 > m_TabNormals_run_4;


    std::vector< vec3 > m_TabVertices_jump_1;
    std::vector< vec2 > m_TabTexCoords_jump_1;
    std::vector< vec3 > m_TabNormals_jump_1;

    std::vector< vec3 > m_TabVertices_jump_2;
    std::vector< vec2 > m_TabTexCoords_jump_2;
    std::vector< vec3 > m_TabNormals_jump_2;

    std::vector< vec3 > m_TabVertices_jump_3;
    std::vector< vec2 > m_TabTexCoords_jump_3;
    std::vector< vec3 > m_TabNormals_jump_3;

    std::vector< vec3 > m_TabVertices_jump_4;
    std::vector< vec2 > m_TabTexCoords_jump_4;
    std::vector< vec3 > m_TabNormals_jump_4;

    std::vector< vec3 > m_TabVertices_jump_5;
    std::vector< vec2 > m_TabTexCoords_jump_5;
    std::vector< vec3 > m_TabNormals_jump_5;

    std::vector< vec3 > m_TabVertices_jump_6;
    std::vector< vec2 > m_TabTexCoords_jump_6;
    std::vector< vec3 > m_TabNormals_jump_6;

    std::vector< vec3 > m_TabVertices_jump_7;
    std::vector< vec2 > m_TabTexCoords_jump_7;
    std::vector< vec3 > m_TabNormals_jump_7;

};

#endif // CAT_H
