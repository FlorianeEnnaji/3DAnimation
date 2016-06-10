#ifndef RW_H
#define RW_H

#include "../../Common/GlWindow.h"
#include "../../Common/Types.h"
#include "src/Camera.h"

class RW : public GlWindow
{
    private:
        Camera* m_Camera;
        Vec2 m_MousePosition;
        float m_CurrentRotationX;
        float m_CurrentRotationY;

	public:

        //============================= LIFECYCLE ====================================
        /**************************************************************************
        * Name: RW
        * Description: default constructor
        **************************************************************************/
        RW();

        /**************************************************************************
        * Name: ~RW
        * Description: the destructor
        **************************************************************************/
        ~RW();

        //============================= OPERATIONS ===================================
        /**************************************************************************
        * Name: initializeObjects
        * Description: Initialization of objects
        * Returns:
            - bool: return always true
        **************************************************************************/
		bool initializeObjects();

        /**************************************************************************
        * Name: render
        * Description: render of the scene
        **************************************************************************/
		void render();

        /**************************************************************************
        * Name: keyPressEvent
        * Description: do actions depending on which key was pressed
        * Inputs:
            - QKeyEvent*: the key press event
        **************************************************************************/
        void keyPressEvent(QKeyEvent*);
        /**************************************************************************
        * Name: mouseMoveEvent
        * Description: do actions depending on the mouse move
        * Inputs:
            - QMouseEvent*: the mouse move event
        **************************************************************************/
        void mouseMoveEvent(QMouseEvent*);

        void wheelEvent(QWheelEvent*);
};

#endif
