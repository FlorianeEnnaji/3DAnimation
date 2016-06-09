#ifndef QUATERNION_H
#define QUATERNION_H

#include "../../Common/Vectors.h"
#include "../../Common/GlFramework.h"

class Quaternion: public Vec3
{
    private:

    public:

        float m_W;
        float m_X;
        float m_Y;
        float m_Z;

        //============================= LIFECYCLE ====================================
        /**************************************************************************
        * Name: Quaternion
        * Description: default constructor
        **************************************************************************/
        Quaternion();


        //============================= OPERATORS ====================================
        /**************************************************************************
        * Name: operator*
        * Description: multiplication of a quaternion by a float
        * Inputs:
            - f: a float
        * Returns:
            - Quaternion: the result of the multiplication of a quaternion by a float
        **************************************************************************/
        Quaternion operator*(float f);
        /**************************************************************************
        * Name: operator*
        * Description: multiplication of a quaternion by a vector
        * Inputs:
            - v: a vec3
        * Returns:
            - Vec3: the result of the multiplication of a quaternion by a vector
        **************************************************************************/
        Vec3 operator*(const Vec3& v);
        /**************************************************************************
        * Name: operator*
        * Description: multiplication of a quaternion by a quaternion
        * Inputs:
            - q: a quaternion
        * Returns:
            - Quaternion: the result of the multiplication of a quaternion by a quaternion
        **************************************************************************/
        Quaternion operator*(const Quaternion& q);
        /**************************************************************************
        * Name: operator+
        * Description: addition of two quaternions
        * Inputs:
            - q: a quaternion
        * Returns:
            - Quaternion: the result of the addition of two quaternions
        **************************************************************************/
        Quaternion operator+(const Quaternion &q);
        /**************************************************************************
        * Name: operator*=
        * Description: *= operation on a quaternion by an other quaternion
        * Inputs:
            - q: a quaternion
        * Returns:
            - Quaternion: the result of the *= operation of two quaternions
        **************************************************************************/
        Quaternion& operator*=(const Quaternion &q);


        //============================= OPERATIONS ===================================
        /**************************************************************************
        * Name: dot
        * Description: the dot product between two quaternions
        * Inputs:
            - q: a quaternion
        * Returns:
            - float: the result of the dot product
        **************************************************************************/
        float dot(const Quaternion &q);
        /**************************************************************************
        * Name: conjuguate
        * Description: computes the conjuguates of a quaternion
        * Returns:
            - Quaternion: the conjuguates of the quaternion
        **************************************************************************/
        Quaternion conjuguate();
        /**************************************************************************
        * Name: slerp
        * Description: spherical linear interpolation function
        * Inputs:
            - q1: a quaternion
            - q2: a quaternion
            - t: interpolar parameter
        * Returns:
            - quaternion: the result of the spherical linear interpolation
        **************************************************************************/
        Quaternion slerp(const Quaternion& q1, const Quaternion& q2, float t);
        /**************************************************************************
        * Name: normalize
        * Description: normalization of a quaternion
        **************************************************************************/
        void normalize();


        //============================= ATTRIBUTE ACCESSORS ==========================
        /**************************************************************************
        * Name: getRotationMatrix
        * Description: get the rotation matrix
        * Returns:
            - GLMatrix: the rotation matrix
        **************************************************************************/
        GLMatrix getRotationMatrix();
        /**************************************************************************
        * Name: getVec
        * Description: return a vector with the x, y, and z composantes of a quaternion
        * Returns:
            - value: the vector representing the x, y, and z composantes of a quaternion
        **************************************************************************/
        Vec3 getVec();
        /**************************************************************************
        * Name: set
        * Description: set the w, x, y and z composantes of a quaternion
        * Inputs:
            - w: the w-composante of a quaternion
            - x: the x-composante of a quaternion
            - y: the y-composante of a quaternion
            - z: the z-composante of a quaternion
        **************************************************************************/
        void set(float w, float x, float y, float z);
        /**************************************************************************
        * Name: setFromAxis
        * Description: set the composantes of a quaternion given an axis and an angle
        * Inputs:
            - angle: the angle
            - ax: x-composante of a quaternion
            - ay: y-composante of a quaternion
            - az: z-composante of a quaternion
        **************************************************************************/
        void setFromAxis(float angle, float ax, float ay, float az);

};

#endif // QUATERNION_H
