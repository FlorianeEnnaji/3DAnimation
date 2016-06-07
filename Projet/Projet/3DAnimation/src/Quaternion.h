#ifndef QUATERNION_H
#define QUATERNION_H

#include "../common/Vectors.h"
#include "../common/GlFramework.h"

class Quaternion: public Vec3
{
    private:

    public:

        float m_W;
        float m_X;
        float m_Y;
        float m_Z;

        Quaternion();
        Quaternion operator*(float f);
        Quaternion operator*(const Quaternion& q);
        Quaternion operator+(const Quaternion &q);
        Quaternion& operator*=(const Quaternion &q);
        Quaternion conjuguate();
        Quaternion slerp(const Quaternion& q1, const Quaternion& q2, float t);

        Vec3 operator*(const Vec3& v);
        float dot(const Quaternion &q);
        void normalize();

        void set(float m_W, float m_X, float m_Y, float m_Z);
        void setFromAxis(float angle, float ax, float ay, float az);

        GLMatrix getRotationMatrix();
        Vec3 getVec();
};

#endif // QUATERNION_H
