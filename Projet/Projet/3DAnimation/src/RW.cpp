#include "RW.h"
#include "Cat.h"

#include <iostream>

using namespace std;


GLfloat angle1 = 30.0f;
GLfloat angle2 = 0.0f;

const GLfloat g_AngleSpeed = 10.0f;

Cat* cat;

RW::RW()
{
    setWindowTitle(trUtf8("3DAnimation"));
    cat = new Cat();
}


RW::~RW()
{
    delete cat;
}


bool
RW::initializeObjects()
{
	// Fond gris
	glClearColor( 0.2f, 0.2f, 0.2f, 1.0f );
	glEnable( GL_DEPTH_TEST );

	// Chargement des shaders
	createShader( "Shaders/color" );

    cout << "Shader color: ";
    if (useShader( "color" ))
    {
        cout << "Loaded!" << endl;
    }
    else
    {
        cout << "NOT Loaded!" << endl;
    }

	return true;
}


void
RW::render()
{
	// Initialisation de la caméra
    lookAt( 0, 5, 30, 0, 0, 0 );


	// Rendu des objets
	pushMatrix();
		rotate( angle1, 0, 1, 0 );
		rotate( angle2, 1, 0, 0 );

        translate( 0, 5, 0 );

        cat->draw();
    popMatrix();
}


void
RW::keyPressEvent( QKeyEvent* event )
{
	switch( event->key())
	{
		case Qt::Key_Escape:
			close();
			break;

		case Qt::Key_Left:
			angle1 -= g_AngleSpeed;
			break;

		case Qt::Key_Right:
			angle1 += g_AngleSpeed;
			break;

		case Qt::Key_Up:
			angle2 -= g_AngleSpeed;
			break;

		case Qt::Key_Down:
			angle2 += g_AngleSpeed;
			break;

		case Qt::Key_R:
			angle1 = angle2 = 0.0f;
			break;
	}
}
