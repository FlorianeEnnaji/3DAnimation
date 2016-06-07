#ifndef CAT_H
#define CAT_H

#include "../../Common/Object3D.h"
#include "ObjLoader.h"

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

        int m_AnimType;
        int m_StepOfAnim;
        ObjLoader* m_Obj;

        std::vector< vec3 > m_TabVerticesOriginal;
        std::vector< vec2 > m_TabTexCoordsOriginal;
        std::vector< vec3 > m_TabNormalsOriginal;

        std::vector< vec3 > m_TabVertices;
        std::vector< vec2 > m_TabTexCoords;
        std::vector< vec3 > m_TabNormals;


        std::vector< vec3 > m_TabVerticesWalk1;
        std::vector< vec2 > m_TabTexCoordsWalk1;
        std::vector< vec3 > m_TabNormalsWalk1;

        std::vector< vec3 > m_TabVerticesWalk2;
        std::vector< vec2 > m_TabTexCoordsWalk2;
        std::vector< vec3 > m_TabNormalsWalk2;


        std::vector< vec3 > m_TabVerticesRun1;
        std::vector< vec2 > m_TabTexCoordsRun1;
        std::vector< vec3 > m_TabNormalsRun1;

        std::vector< vec3 > m_TabVerticesRun2;
        std::vector< vec2 > m_TabTexCoordsRun2;
        std::vector< vec3 > m_TabNormalsRun2;

        std::vector< vec3 > m_TabVerticesRun3;
        std::vector< vec2 > m_TabTexCoordsRun3;
        std::vector< vec3 > m_TabNormalsRun3;

        std::vector< vec3 > m_TabVerticesRun4;
        std::vector< vec2 > m_TabTexCoordsRun4;
        std::vector< vec3 > m_TabNormalsRun4;


        std::vector< vec3 > m_TabVerticesJump1;
        std::vector< vec2 > m_TabTexCoordsJump1;
        std::vector< vec3 > m_TabNormalsJump1;

        std::vector< vec3 > m_TabVerticesJump2;
        std::vector< vec2 > m_TabTexCoordsJump2;
        std::vector< vec3 > m_TabNormalsJump2;

        std::vector< vec3 > m_TabVerticesJump3;
        std::vector< vec2 > m_TabTexCoordsJump3;
        std::vector< vec3 > m_TabNormalsJump3;

        std::vector< vec3 > m_TabVerticesJump4;
        std::vector< vec2 > m_TabTexCoordsJump4;
        std::vector< vec3 > m_TabNormalsJump4;

        std::vector< vec3 > m_TabVerticesJump5;
        std::vector< vec2 > m_TabTexCoordsJump5;
        std::vector< vec3 > m_TabNormalsJump5;

        std::vector< vec3 > m_TabVerticesJump6;
        std::vector< vec2 > m_TabTexCoordsJump6;
        std::vector< vec3 > m_TabNormalsJump6;

        std::vector< vec3 > m_TabVerticesJump7;
        std::vector< vec2 > m_TabTexCoordsJump7;
        std::vector< vec3 > m_TabNormalsJump7;

};

#endif // CAT_H
