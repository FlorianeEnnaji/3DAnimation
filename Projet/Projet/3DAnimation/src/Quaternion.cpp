#include "Quaternion.h"

/////////////////////////////// PUBLIC ///////////////////////////////////////

//============================= LIFECYCLE ====================================

Quaternion::Quaternion()
{
    m_W = 0;
    m_X = 0;
    m_Y = 0;
    m_Z = 0;
}

//============================= OPERATORS ====================================

Quaternion Quaternion::operator*(const Quaternion& q)
{
    Quaternion quat;
    float w = this->m_W*q.m_W - this->m_X*q.m_X - this->m_Y*q.m_Y - this->m_Z*q.m_Z;
    float x = this->m_W*q.m_X + this->m_X*q.m_W + this->m_Y*q.m_Z - this->m_Z*q.m_Y;
    float y = this->m_W*q.m_Y + this->m_Y*q.m_W - this->m_X*q.m_Z + this->m_Z*q.m_X;
    float z = this->m_Z*q.m_W + this->m_W*q.m_Z + this->m_X*q.m_Y - this->m_Y*q.m_X;

    quat.set(w, x, y, z);
    quat.normalize();
    return quat;
}

Vec3 Quaternion::operator*(const Vec3& v)
{
    Quaternion q;

    q.set(0,v.x,v.y,v.z);
    q = this->operator*(q.operator*(this->conjuguate()));
    q.normalize();
    Vec3 vec;
    vec.x = q.m_X;
    vec.y = q.m_Y;
    vec.z = q.m_Z;
    return vec;
}

Quaternion Quaternion::operator*(float f)
{
    Quaternion q;

    q.set(this->m_W*f, this->m_X*f, this->m_Y*f, this->m_Z*f);
    q.normalize();
    return q;
}

Quaternion Quaternion::operator+(const Quaternion &q)
{
    Quaternion quat;

    quat.set(this->m_W+q.m_W, this->m_X+q.m_X, this->m_Y+q.m_Y, this->m_Z+q.m_Z);
    return quat;
}

Quaternion& Quaternion::operator*=(const Quaternion &q)
{
    float w = this->m_W*q.m_W - this->m_X*q.m_X - this->m_Y*q.m_Y - this->m_Z*q.m_Z;
    float x = this->m_W*q.m_X + this->m_X*q.m_W + this->m_Y*q.m_Z - this->m_Z*q.m_Y;
    float y = this->m_W*q.m_Y + this->m_Y*q.m_W - this->m_X*q.m_Z + this->m_Z*q.m_X;
    float z = this->m_Z*q.m_W + this->m_W*q.m_Z + this->m_X*q.m_Y - this->m_Y*q.m_X;

    this->set(w, x, y, z);
    this->normalize();
    return *this;
}

//============================= OPERATIONS ===================================

float Quaternion::dot(const Quaternion &q)
{
    return (this->m_W*q.m_W + this->m_X*q.m_X + this->m_Y*q.m_Y + this->m_Z*q.m_Z);
}

Quaternion Quaternion::conjuguate()
{
    Quaternion q;

    q.set(this->m_W, -this->m_X, -this->m_Y, -this->m_Z);
    return q;
}

Quaternion Quaternion::slerp(const Quaternion& q1, const Quaternion& q2, float t)
{
    Quaternion quat1 = q1;
    Quaternion quat2 = q2;
    quat1.normalize();
    quat2.normalize();
    Quaternion quat_prod = quat1.operator *(quat2);
    float teta = acos(quat_prod.m_W);
    Quaternion quat;

    quat=(quat1.operator*((sin(teta)*(1-t))/sin(teta))).operator+(quat2.operator*((sin(teta)*t)/sin(teta)));

    return quat;
}

void Quaternion::normalize()
{
    float norm = sqrt(this->m_W*this->m_W + this->m_X*this->m_X + this->m_Y*this->m_Y + this->m_Z*this->m_Z);

    this->m_X = this->m_X / norm;
    this->m_Y = this->m_Y / norm;
    this->m_Z = this->m_Z / norm;
    this->m_W = this->m_W / norm;
}

//============================= ATTRIBUTE ACCESSORS ==========================

GLMatrix Quaternion::getRotationMatrix()
{
    GLMatrix matrix;
    matrix.data[0]=1 - 2*this->m_Y*this->m_Y - 2*this->m_Z*this->m_Z;
    matrix.data[1]=2*this->m_X*this->m_Y - 2*this->m_W*this->m_Z;
    matrix.data[2]=2*this->m_X*this->m_Z + 2*this->m_W*this->m_Y;
    matrix.data[3]=0;

    matrix.data[4]=2*this->m_X*this->m_Y + 2*this->m_W*this->m_Z;
    matrix.data[5]=1 - 2*this->m_X*this->m_X - 2*this->m_Z*this->m_Z;
    matrix.data[6]=2*this->m_Y*this->m_Z - 2*this->m_W*this->m_X;
    matrix.data[7]=0;

    matrix.data[8]=2*this->m_X*this->m_Z - 2*this->m_W*this->m_Y;
    matrix.data[9]=2*this->m_Y*this->m_Z + 2*this->m_W*this->m_X;
    matrix.data[10]=1 - 2*this->m_X*this->m_X - 2*this->m_Y*this->m_Y;
    matrix.data[11]=0;

    matrix.data[12]=0; matrix.data[13]=0; matrix.data[14]=0; matrix.data[15]=1;
}

Vec3 Quaternion::getVec()
{
    Vec3 vec;
    vec.x = this->m_X;
    vec.y = this->m_Y;
    vec.z = this->m_Z;
    return vec;
}

void Quaternion::set(float w, float x, float y, float z)
{
    this->m_W = w;
    this->m_X = x;
    this->m_Y = y;
    this->m_Z = z;
}

void Quaternion::setFromAxis(float angle, float ax, float ay, float az)
{
    this->m_W=cos(angle/2);
    this->m_X=sin(angle/2)*ax;
    this->m_Y=sin(angle/2)*ay;
    this->m_Z=sin(angle/2)*az;
}
