﻿#ifndef RW_h
#define RW_h


#include "../../Common/GlWindow.h"
#include "../../Common/Types.h"
#include "../../Common/Camera.h"


class RW : public GlWindow
{
    private:
    Camera* m_Camera;
    Vec2 m_mousePosition;
    float m_currentRotationX;
    float m_currentRotationY;

	public:
        RW();
        ~RW();

		/*!
		*\brief Initialization des objets.
		*/
		bool initializeObjects();

		/*!
		*\brief Rendu de la scène.
		*/
		void render();

		void keyPressEvent(QKeyEvent *);
        void mouseMoveEvent(QMouseEvent *);
};


#endif
