#ifndef CAT_H
#define CAT_H

#include "../../Common/Object3D.h"
#include "ObjLoader.h"

class Cat : public Object3D
{
    public:

        //============================= LIFECYCLE ====================================
        /**************************************************************************
        * Name:Cat
        * Description: default constructor
        **************************************************************************/
        Cat();

        //============================= OPERATIONS ===================================
        /**************************************************************************
        * Name:walk
        * Description: begin or stop the walk animation on the 3D model
        **************************************************************************/
        void walk();

        /**************************************************************************
        * Name: run
        * Description: begin or stop the run animation on the 3D model
        **************************************************************************/
        void run();

        /**************************************************************************
        * Name: jump
        * Description: begin or stop the jump animation on the 3D model
        **************************************************************************/
        void jump();

    protected:
        //============================= OPERATIONS ===================================
        /**************************************************************************
        * Name:drawShape
        * Description: draw a Shape with a given shader
        * Input : shader_name: the name of the shader
        **************************************************************************/
        void drawShape( const char* shader_name );
        /**************************************************************************
        * Name: anim
        * Description: launches the animation of the 3D model
        **************************************************************************/
        void anim();
        /**************************************************************************
        * Name: walkAnim
        * Description: launches the walk animation of the 3D model
        **************************************************************************/
        void walkAnim();
        /**************************************************************************
        * Name: runAnim
        * Description: launches the run animation of the 3D model
        **************************************************************************/
        void runAnim();
        /**************************************************************************
        * Name: jumpAnim
        * Description: launches the jump animation of the 3D model
        **************************************************************************/
        void jumpAnim();

        //============================= ATTRIBUTE ACCESSORS ==========================
        /**************************************************************************
        * Name: setTabVertices
        * Description: set the table of vertices
        * Inputs:
            - origin: the original vertices table
            - destination: the destination vertices table
            - completion : the completion of the movement (between 0 and 1)
        **************************************************************************/
        void setTabVertices(std::vector< Vec3 > origin, std::vector< Vec3 > destination, float completion);

    protected:

        int m_AnimType;
        int m_StepOfAnim;
        ObjLoader* m_Obj;

        std::vector< Vec3 > m_TabVerticesOriginal;
        std::vector< Vec2 > m_TabTexCoordsOriginal;
        std::vector< Vec3 > m_TabNormalsOriginal;

        std::vector< Vec3 > m_TabVertices;
        std::vector< Vec2 > m_TabTexCoords;
        std::vector< Vec3 > m_TabNormals;


        std::vector< Vec3 > m_TabVerticesWalk1;
        std::vector< Vec2 > m_TabTexCoordsWalk1;
        std::vector< Vec3 > m_TabNormalsWalk1;

        std::vector< Vec3 > m_TabVerticesWalk2;
        std::vector< Vec2 > m_TabTexCoordsWalk2;
        std::vector< Vec3 > m_TabNormalsWalk2;


        std::vector< Vec3 > m_TabVerticesRun1;
        std::vector< Vec2 > m_TabTexCoordsRun1;
        std::vector< Vec3 > m_TabNormalsRun1;

        std::vector< Vec3 > m_TabVerticesRun2;
        std::vector< Vec2 > m_TabTexCoordsRun2;
        std::vector< Vec3 > m_TabNormalsRun2;

        std::vector< Vec3 > m_TabVerticesRun3;
        std::vector< Vec2 > m_TabTexCoordsRun3;
        std::vector< Vec3 > m_TabNormalsRun3;

        std::vector< Vec3 > m_TabVerticesRun4;
        std::vector< Vec2 > m_TabTexCoordsRun4;
        std::vector< Vec3 > m_TabNormalsRun4;


        std::vector< Vec3 > m_TabVerticesJump1;
        std::vector< Vec2 > m_TabTexCoordsJump1;
        std::vector< Vec3 > m_TabNormalsJump1;

        std::vector< Vec3 > m_TabVerticesJump2;
        std::vector< Vec2 > m_TabTexCoordsJump2;
        std::vector< Vec3 > m_TabNormalsJump2;

        std::vector< Vec3 > m_TabVerticesJump3;
        std::vector< Vec2 > m_TabTexCoordsJump3;
        std::vector< Vec3 > m_TabNormalsJump3;

        std::vector< Vec3 > m_TabVerticesJump4;
        std::vector< Vec2 > m_TabTexCoordsJump4;
        std::vector< Vec3 > m_TabNormalsJump4;

        std::vector< Vec3 > m_TabVerticesJump5;
        std::vector< Vec2 > m_TabTexCoordsJump5;
        std::vector< Vec3 > m_TabNormalsJump5;

        std::vector< Vec3 > m_TabVerticesJump6;
        std::vector< Vec2 > m_TabTexCoordsJump6;
        std::vector< Vec3 > m_TabNormalsJump6;

        std::vector< Vec3 > m_TabVerticesJump7;
        std::vector< Vec2 > m_TabTexCoordsJump7;
        std::vector< Vec3 > m_TabNormalsJump7;

};

#endif // CAT_H
