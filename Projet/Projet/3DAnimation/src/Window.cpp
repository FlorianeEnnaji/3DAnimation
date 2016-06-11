#include "Window.h"
#include "Cat.h"

#include <iostream>

using namespace std;

Cat* g_Cat;

/////////////////////////////// PUBLIC ///////////////////////////////////////

//============================= LIFECYCLE ====================================

RW::RW()
{
    m_CurrentRotationX = 0.0;
    m_CurrentRotationY = 0.0;
    setWindowTitle(trUtf8("3DAnimation"));
    g_Cat = new Cat();

    Vec3* camera_position = new Vec3(20,10,30);
    m_MousePosition.x = 0;
    m_MousePosition.y = 5;
    Vec3* camera_orientation = new Vec3(0,5,0);
    m_Camera = new Camera(*camera_position, *camera_orientation, 70, 40, 5, 0.7);
}

RW::~RW()
{
    delete g_Cat;
    delete m_Camera;
}

//============================= OPERATIONS ===================================

bool RW::initializeObjects()
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

void RW::render()
{
    Quaternion orientation = m_Camera->getOrientation();
    lookAt( m_Camera->getPosition().x , m_Camera->getPosition().y, m_Camera->getPosition().z,
            orientation.getVec().x, orientation.getVec().y, orientation.getVec().z);


    m_Camera->buildViewMatrix();
    m_Camera->buildProjectionMatrix();

    // Rendu des objets
	pushMatrix();
    g_Cat->draw();
    popMatrix();
}

void RW::keyPressEvent( QKeyEvent* event )
{
    switch (event->key())
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
            g_Cat->walk();
            break;

        case Qt::Key_R:
            g_Cat->run();
            break;

        case Qt::Key_J:
            g_Cat->jump();
            break;

        case Qt::Key_0:
            this->setMouseTracking(false);
            m_Camera->setPosition(20,10,30);
            m_Camera->setOrientation(0,5,0);
            break;

        case Qt::Key_1:
            this->setMouseTracking(false);
            m_Camera->setPosition(20,10,15);
            m_Camera->setOrientation(0,5,0);
            break;

        case Qt::Key_2:
            this->setMouseTracking(false);
            m_Camera->setPosition(-20,10,30);
            m_Camera->setOrientation(0,5,0);
            break;

        case Qt::Key_3:
            this->setMouseTracking(false);
            m_Camera->setPosition(-20,10,-30);
            m_Camera->setOrientation(0,5,0);
            break;

        case Qt::Key_4:
            this->setMouseTracking(false);
            m_Camera->setPosition(20,10,-30);
            m_Camera->setOrientation(0,5,0);
            break;

        case Qt::Key_5:
            this->setMouseTracking(false);
            m_Camera->setPosition(20,10,-15);
            m_Camera->setOrientation(0,5,0);
            break;


    }
}

void RW::wheelEvent(QWheelEvent * event)
{
    if (event->delta() < 0) {
        m_Camera->translateZ(1);
    } else {
        m_Camera->translateZ(-1);
    }
}

void RW::mouseMoveEvent(QMouseEvent * event)
{
    this->setMouseTracking(true);
    float mouseSensitivity = 10.0;

    // the middle of the screen in the x direction
    int middle_x = 1024/2;
    // the middle of the screen in the y direction
    int middle_y = 768/2;

    // This function gets the position of the mouse
    Vec2 mouse_position = Vec2(event->pos().x(), event->pos().y());

    // if the mouse hasn't moved, return
    if ((mouse_position.x == middle_x) && (mouse_position.y == middle_y))
    {
        return;
    }

    // otherwise move the mouse back to the middle of the screen
    int x_diff = mouse_position.x - middle_x;
    int y_diff = mouse_position.y - middle_y;

    m_CurrentRotationY = x_diff;
    m_CurrentRotationX = -y_diff;

    middle_y = middle_y - 175;
    middle_x = middle_x - 250;

    // We don't want to rotate more than the width of the window, so we cap it.
    if (!(x_diff > middle_x) && !(x_diff < -middle_x))
    {
        m_Camera->setOrientation((x_diff)/mouseSensitivity,m_Camera->getOrientation().m_Y,m_Camera->getOrientation().m_Z);
        //m_Camera->rotateX((-yDiff)*100/MouseSensitivity);
    }

    // We don't want to rotate more than the height of the window, so we cap it.
    if (!(y_diff > middle_y) && !(y_diff < -middle_y))
    {
        m_Camera->setOrientation(m_Camera->getOrientation().m_X,(-y_diff)/mouseSensitivity,m_Camera->getOrientation().m_Z);
        //m_Camera->rotateY((-xDiff)*100/MouseSensitivity);
    }
}
