#include "Quaternion.h"

Quaternion::Quaternion()
{
    w = 0;
    x = 0;
    y = 0;
    z = 0;
}

Quaternion Quaternion::operator*(const Quaternion& q){
    Quaternion quat;
    float w = this->w*q.w - this->x*q.x - this->y*q.y - this->z*q.z;
    float x = this->w*q.x + this->x*q.w + this->y*q.z - this->z*q.y;
    float y = this->w*q.y + this->y*q.w - this->x*q.z + this->z*q.x;
    float z = this->z*q.w + this->w*q.z + this->x*q.y - this->y*q.x;

    quat.set(w, x, y, z);
    quat.normalize();
    return quat;
}

Vec3 Quaternion::operator*(const Vec3& v){
    Quaternion q;

    q.set(0,v.x,v.y,v.z);
    q = this->operator*(q.operator*(this->conjuguate()));
    q.normalize();
    Vec3 vec;
    vec.x = q.x;
    vec.y = q.y;
    vec.z = q.z;
    return vec;
}

Quaternion Quaternion::operator*(float f){
    Quaternion q;

    q.set(this->w*f, this->x*f, this->y*f, this->z*f);
    q.normalize();
    return q;
}

Quaternion Quaternion::operator+(const Quaternion &q){
    Quaternion quat;

    quat.set(this->w+q.w, this->x+q.x, this->y+q.y, this->z+q.z);
    return quat;
}

Quaternion& Quaternion::operator*=(const Quaternion &q){
    float w = this->w*q.w - this->x*q.x - this->y*q.y - this->z*q.z;
    float x = this->w*q.x + this->x*q.w + this->y*q.z - this->z*q.y;
    float y = this->w*q.y + this->y*q.w - this->x*q.z + this->z*q.x;
    float z = this->z*q.w + this->w*q.z + this->x*q.y - this->y*q.x;

    this->set(w, x, y, z);
    this->normalize();
    return *this;
}

float Quaternion::dot(const Quaternion &q) {
    return (this->w*q.w + this->x*q.x + this->y*q.y + this->z*q.z);
}

void Quaternion::set(float w, float x, float y, float z){
    this->w = w;
    this->x = x;
    this->y = y;
    this->z = z;
}

void Quaternion::setFromAxis(float angle, float ax, float ay, float az){
    this->w=cos(angle/2);
    this->x=sin(angle/2)*ax;
    this->y=sin(angle/2)*ay;
    this->z=sin(angle/2)*az;
}

Quaternion Quaternion::conjuguate(){
    Quaternion q;

    q.set(this->w, -this->x, -this->y, -this->z);
    return q;
}

Quaternion Quaternion::slerp(const Quaternion& q1, const Quaternion& q2, float t){
    Quaternion quat1 = q1;
    Quaternion quat2 = q2;
    Quaternion quatProd = quat1.operator *(quat2.conjuguate());
    float teta = acos(quatProd.w);
    Quaternion quat;

    quat=(quat1.operator*((sin(teta)*(1-t))/sin(teta))).operator+(quat2.operator*((sin(teta)*t)/sin(teta)));

    return quat;
}

void Quaternion::normalize(){
    float norm = sqrt(this->w*this->w + this->x*this->x + this->y*this->y + this->z*this->z);

    this->x = this->x / norm;
    this->y = this->y / norm;
    this->z = this->z / norm;
    this->w = this->w / norm;
}

GLMatrix Quaternion::getRotationMatrix(){
    GLMatrix matrix;
    matrix.data[0]=1 - 2*this->y*this->y - 2*this->z*this->z;
    matrix.data[1]=2*this->x*this->y - 2*this->w*this->z;
    matrix.data[2]=2*this->x*this->z + 2*this->w*this->y;
    matrix.data[3]=0;

    matrix.data[4]=2*this->x*this->y + 2*this->w*this->z;
    matrix.data[5]=1 - 2*this->x*this->x - 2*this->z*this->z;
    matrix.data[6]=2*this->y*this->z - 2*this->w*this->x;
    matrix.data[7]=0;

    matrix.data[8]=2*this->x*this->z - 2*this->w*this->y;
    matrix.data[9]=2*this->y*this->z + 2*this->w*this->x;
    matrix.data[10]=1 - 2*this->x*this->x - 2*this->y*this->y;
    matrix.data[11]=0;

    matrix.data[12]=0; matrix.data[13]=0; matrix.data[14]=0; matrix.data[15]=1;
}

Vec3 Quaternion::getVec() {
    Vec3 vec;
    vec.x = this->x;
    vec.y = this->y;
    vec.z = this->z;
    return vec;
}

