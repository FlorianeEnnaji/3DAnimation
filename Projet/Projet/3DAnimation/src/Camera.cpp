#include "Camera.h"
#include <iostream>

/////////////////////////////// PUBLIC ///////////////////////////////////////

//============================= LIFECYCLE ====================================

Camera::Camera()
{

}

Camera::Camera(Vec3 pos, Vec3 ori, float angle, float fp, float np, float ratio)
{
    this->m_FarPlan = fp;
    this->m_NearPlan = np;
    this->m_Ratio = ratio;
    this->m_Fov = angle;
    this->m_Position.x = pos.x;
    this->m_Position.y = pos.y;
    this->m_Position.z = pos.z;
    this->m_Orientation.setFromAxis(m_Fov,ori.x,ori.y,ori.z);

    buildProjectionMatrix();
    buildViewMatrix();
}

//============================= OPERATIONS ===================================

void Camera::translate(float x, float y, float z)
{
    translateX(x);
    translateY(y);
    translateZ(z);
}

void Camera::translateX(float shift)
{
    this->m_Position.x += shift;
    this->m_Orientation.m_X += shift;
}

void Camera::translateY(float shift)
{
    this->m_Position.y += shift;
    this->m_Orientation.m_Y += shift;
}

void Camera::translateZ(float shift)
{
    this->m_Position.z += shift;
    this->m_Orientation.m_Z += shift;
}

void Camera::rotate(float angle, float ax, float ay, float az)
{
    angle = (M_PI * m_Fov / 180.0f);
    Quaternion quat;
    quat.setFromAxis(angle, ax, ay, az);
    quat.normalize();

    m_Orientation = m_Orientation * quat;
    m_Orientation.normalize();
}

void Camera::rotateX(float angle)
{
    this->rotate(angle,1,0,0);
}

void Camera::rotateY(float angle)
{
    this->rotate(angle,0,1,0);
}

void Camera::rotateZ(float angle)
{
    this->rotate(angle,0,0,1);
}


void Camera::buildViewMatrix()
{
    this->m_ViewMatrix.m[0][0] = 1; this->m_ViewMatrix.m[0][1] = 0; this->m_ViewMatrix.m[0][2] = 0; this->m_ViewMatrix.m[0][3] = -m_Position.x;
    this->m_ViewMatrix.m[1][0] = 0; this->m_ViewMatrix.m[1][1] = 1; this->m_ViewMatrix.m[1][2] = 0; this->m_ViewMatrix.m[1][3] = -m_Position.y;
    this->m_ViewMatrix.m[2][0] = 0; this->m_ViewMatrix.m[2][1] = 0; this->m_ViewMatrix.m[2][2] = 1; this->m_ViewMatrix.m[2][3] = -m_Position.z;
    this->m_ViewMatrix.m[3][0] = 0; this->m_ViewMatrix.m[3][1] = 0; this->m_ViewMatrix.m[3][2] = 0; this->m_ViewMatrix.m[3][3] = 1;

    //View Matrix = rotation * translation
    this->m_ViewMatrix = (this->m_Orientation).getRotationMatrix() * this->m_ViewMatrix;
}

void Camera::buildProjectionMatrix()
{
    float alpha = 0.5f * (M_PI * m_Fov / 180.0f);
    float right = tan(alpha) * m_Ratio * m_NearPlan;
    float left = -right;
    float top = tan(alpha) * m_NearPlan;
    float bottom = -top;

    this->m_ProjectionMatrix.m[0][0] = (2*m_NearPlan) / (right - left);
    this->m_ProjectionMatrix.m[0][1] = 0;
    this->m_ProjectionMatrix.m[0][2] = (right + left) / (right - left);
    this->m_ProjectionMatrix.m[0][3] = 0;

    this->m_ProjectionMatrix.m[1][0] = 0;
    this->m_ProjectionMatrix.m[1][1] = (2*m_NearPlan) / (top - bottom);
    this->m_ProjectionMatrix.m[1][2] = (top + bottom) / (top - bottom);
    this->m_ProjectionMatrix.m[1][3] = 0;

    this->m_ProjectionMatrix.m[2][0] = 0;
    this->m_ProjectionMatrix.m[2][1] = 0;
    this->m_ProjectionMatrix.m[2][2] = (-m_FarPlan + m_NearPlan) / (m_FarPlan - m_NearPlan);
    this->m_ProjectionMatrix.m[2][3] = (-2 * m_NearPlan * m_FarPlan) / (m_FarPlan * m_NearPlan);

    this->m_ProjectionMatrix.m[3][0] = 0;
    this->m_ProjectionMatrix.m[3][1] = 0;
    this->m_ProjectionMatrix.m[3][2] = -1;
    this->m_ProjectionMatrix.m[3][3] = 0;
}

//============================= ATTRIBUTE ACCESSORS ==========================

const GLMatrix& Camera::getViewMatrix()
{
    return this->m_ViewMatrix;
}

void Camera::setAspectRatio(float ar)
{
    this->m_Ratio = ar;
}

void Camera::setPlanes(float np, float fp)
{
    this->m_NearPlan = np;
    this->m_FarPlan = fp;
}

void Camera::setFOV(float angle)
{
    this->m_Fov = angle;
}

const GLMatrix& Camera::getProjectionMatrix()
{
    return this->m_ProjectionMatrix;
}

Vec3 Camera::getPosition()
{
    return this->m_Position;
}

Quaternion Camera::getOrientation()
{
    return this->m_Orientation;
}

void Camera::setOrientation(float x, float y, float z)
{
    // update camera's orientation
    m_Orientation.m_X = x;
    m_Orientation.m_Y = y;
    m_Orientation.m_Z = z;
}
