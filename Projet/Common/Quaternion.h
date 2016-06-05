#ifndef QUATERNION_H
#define QUATERNION_H

#include "../common/Vectors.h"
#include "../common/GlFramework.h"

class Quaternion: public Vec3
{
    private:


    public:
    float w;
    float x;
    float y;
    float z;
        Quaternion();
        Quaternion operator*(const Quaternion& q);
        Vec3 operator*(const Vec3& v);
        Quaternion operator*(float f);
        Quaternion operator+(const Quaternion &q);
        Quaternion& operator*=(const Quaternion &q);
        float dot(const Quaternion &q);
        void set(float w, float x, float y, float z);
        void setFromAxis(float angle, float ax, float ay, float az);
        Quaternion conjuguate();
        Quaternion slerp(const Quaternion& q1, const Quaternion& q2, float t);
        void normalize();
        GLMatrix getRotationMatrix();
        Vec3 getVec();
};

#endif // QUATERNION_H
