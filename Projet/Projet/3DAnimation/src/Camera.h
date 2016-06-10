#ifndef CAMERA_H
#define CAMERA_H


#include "../../Common/Vectors.h"
#include "../../Common/GlFramework.h"
#include "Quaternion.h"

class Camera {

    private:
        Vec3 m_Position;
        Quaternion m_Orientation;
        GLMatrix m_ViewMatrix;
        GLMatrix m_ProjectionMatrix;
        float m_Fov, m_NearPlan, m_FarPlan, m_Ratio;

    public:
        //============================= LIFECYCLE ====================================
        /**************************************************************************
        * Name:Camera
        * Description: default constructor
        **************************************************************************/
        Camera();

        /**************************************************************************
        * Name: Camera
        * Description: Constructor
        * Inputs:
            - pos: the position of the camera
            - ori: the origine of the frame
            - angle: the angle
            - fp: far plan
            - np: near plan
            - ratio: the ratio
        **************************************************************************/
        Camera(Vec3 pos, Vec3 ori, float angle, float fp, float np, float ratio);

        //============================= OPERATIONS ===================================
        /**************************************************************************
        * Name: translate
        * Description: translates the camera with a given vector of translation
        * Inputs:
            - x: the x-coordinate of the vector of translation
            - y: the y-coordinate of the vector of translation
            - z: the z-coordinate of the vector of translation
        **************************************************************************/
        void translate(float x, float y, float z);

        /**************************************************************************
        * Name: translateX
        * Description: translates the camera on the X-axis
        * Inputs:
            - shift: the shift on the X-axis
        **************************************************************************/
        void translateX(float shift);

        /**************************************************************************
        * Name: translateY
        * Description: translates the camera on the Y-axis
        * Inputs:
            - shift: the shift on the Y-axis
        **************************************************************************/
        void translateY(float shift);

        /**************************************************************************
        * Name:translateZ
        * Description: translates the camera on the Z-axis
        * Inputs:
            - shift: the shift on the Z-axis
        **************************************************************************/
        void translateZ(float shift);

        /**************************************************************************
        * Name: rotate
        * Description: rotates the camera with a given angle and an axis of rotation
        * Inputs:
            - angle: the angle of rotation
            - ax: the x-coordinate of axis of rotation
            - ay: the y-coordinate of axis of rotation
            - az: the z-coordinate of axis of rotation
        **************************************************************************/
        void rotate(float angle, float ax, float ay, float az);

        /**************************************************************************
        * Name: rotateX
        * Description: rotates the camera on the X-axis with a given angle
        * Inputs:
            - angle: the angle of rotation
        **************************************************************************/
        void rotateX(float angle);

        /**************************************************************************
        * Name: rotateY
        * Description: rotates the camera on the Y-axis with a given angle
        * Inputs:
            - angle: the angle of rotation
        **************************************************************************/
        void rotateY(float angle);

        /**************************************************************************
        * Name: rotateZ
        * Description: rotates the camera on the Z-axis with a given angle
        * Inputs:
            - angle: the angle of rotation
        **************************************************************************/
        void rotateZ(float angle);

        /**************************************************************************
        * Name: buildViewMatrix
        * Description: construct the view matrix
        **************************************************************************/
        void buildViewMatrix();

        /**************************************************************************
        * Name: buildProjectionMatrix
        * Description: construct the projection matrix
        **************************************************************************/
        void buildProjectionMatrix();

        //============================= ATTRIBUTE ACCESSORS ==========================
        /**************************************************************************
        * Name: getViewMatrix
        * Description: returns the view matrix
        * Returns:
            - GLMatrix&: the view matrix
        **************************************************************************/
        const GLMatrix& getViewMatrix();

        /**************************************************************************
        * Name:setAspectRatio
        * Description: set the aspect ratio
        * Inputs:
            - ar: the aspect ratio
        **************************************************************************/
        void setAspectRatio(float ar);

        /**************************************************************************
        * Name: setPlanes
        * Description:
        * Inputs:
            - np: near plan
            - fp: far plan
        **************************************************************************/
        void setPlanes(float np, float fp);

        /**************************************************************************
        * Name: setFOV
        * Description: set the field of view
        * Inputs:
            - angle:
        **************************************************************************/
        void setFOV(float angle);

        /**************************************************************************
        * Name: getProjectionMatrix
        * Description: get the projection matrix
        * Returns:
            - GLMatrix&: the projection matrix
        **************************************************************************/
        const GLMatrix& getProjectionMatrix();

        /**************************************************************************
        * Name: getPosition
        * Description: get the position of the camera
        * Returns:
            - Vec3: the position of the camera
        **************************************************************************/
        Vec3 getPosition();

        /**************************************************************************
        * Name: getOrientation
        * Description: get the orientation of the camera
        * Returns:
            - Quaternion : the orientation of the camera
        **************************************************************************/
        Quaternion getOrientation();

        /**************************************************************************
        * Name: setOrientation
        * Description: set the orientation of the camera
        * Inputs:
            - x: the x-coordinate
            - y: the y-coordinate
            - z: the z-coordinate
        **************************************************************************/
        void setOrientation(float x, float y, float z);

        /**************************************************************************
        * Name: setPosition
        * Description: set the position of the camera
        * Inputs:
            - x: the x-coordinate
            - y: the y-coordinate
            - z: the z-coordinate
        **************************************************************************/
        void setPosition(float x, float y, float z);

};
#endif // CAMERA_H
