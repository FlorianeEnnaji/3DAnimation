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
    m_CurrentRotationX = 0.0;
    m_CurrentRotationY = 0.0;
    setWindowTitle(trUtf8("3DAnimation"));
    cat = new Cat();

    Vec3 *cameraPosition = new Vec3(20,10,30);
    m_MousePosition.x = 0;
    m_MousePosition.y = 5;
    Vec3 *cameraOrientation = new Vec3(0,5,0);
    m_Camera = new Camera(*cameraPosition, *cameraOrientation, 70, 40, 5, 0.7);
}


RW::~RW()
{
    delete cat;
    delete m_Camera;
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
    Quaternion orientation = m_Camera->getOrientation();
    lookAt( m_Camera->getPosition().x , m_Camera->getPosition().y, m_Camera->getPosition().z
                ,orientation.getVec().x, orientation.getVec().y, orientation.getVec().z);


    m_Camera->buildViewMatrix();
    m_Camera->buildProjectionMatrix();

    // Rendu des objets
	pushMatrix();
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
        m_Camera->translateX(-1);
        break;

    case Qt::Key_Right:
        m_Camera->translateX(1);
        break;

    case Qt::Key_Up:
        m_Camera->translateY(1);
        break;

    case Qt::Key_Down:
        m_Camera->translateY(-1);
        break;

    case Qt::Key_Plus:
        m_Camera->translateZ(-1);
        break;

    case Qt::Key_Minus:
        m_Camera->translateZ(1);
        break;

    case Qt::Key_W:
        cat->walk();
        break;

    case Qt::Key_R:
        cat->run();
        break;

    case Qt::Key_J:
        cat->jump();
        break;
    }
}

void
RW::mouseMoveEvent(QMouseEvent * event)
{
    this->setMouseTracking(true);
    float mouseSensitivity = 10.0;

      // the middle of the screen in the x direction
      int middleX = 1024/2;
      // the middle of the screen in the y direction
      int middleY = 768/2;

      // This function gets the position of the mouse
      Vec2 mousePosition = Vec2(event->pos().x(), event->pos().y());

      // if the mouse hasn't moved, return
      if((mousePosition.x == middleX) && (mousePosition.y == middleY))
        return;

      // otherwise move the mouse back to the middle of the screen
      int xDiff = mousePosition.x - middleX;
      int yDiff = mousePosition.y - middleY;

      m_CurrentRotationY = xDiff;
      m_CurrentRotationX = -yDiff;

      middleY = middleY - 175;
      middleX = middleX - 250;
      // We don't want to rotate more than the width of the window, so we cap it.
      if(!(xDiff > middleX) && !(xDiff < -middleX)) {
          m_Camera->setOrientation((xDiff)/mouseSensitivity,m_Camera->getOrientation().m_Y,m_Camera->getOrientation().m_Z);
        //m_Camera->rotateX((-yDiff)*100/MouseSensitivity);
      }

      // We don't want to rotate more than the height of the window, so we cap it.
      if (!(yDiff > middleY) && !(yDiff < -middleY)) {
          m_Camera->setOrientation(m_Camera->getOrientation().m_X,(-yDiff)/mouseSensitivity,m_Camera->getOrientation().m_Z);
        //m_Camera->rotateY((-xDiff)*100/MouseSensitivity);
      }
}
