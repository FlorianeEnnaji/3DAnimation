#ifndef CAMERA_H
#define CAMERA_H


#include "Vectors.h"
#include "GlFramework.h"
#include "Quaternion.h"

class Camera {

    private:
        Vec3 m_Position;
        Quaternion m_Orientation;
        GLMatrix m_ViewMatrix;
        GLMatrix m_ProjectionMatrix;
        float m_Fov, m_NearPlan, m_FarPlan, m_Ratio;

    public:
        Camera();
        Camera(Vec3 pos, Vec3 ori, float angle, float fp, float np, float ratio);
        void translate(float x, float y, float z);
        void translateX(float shift);
        void translateY(float shift);
        void translateZ(float shift);
        void rotate(float angle, float ax, float ay, float az);
        void rotateX(float angle);
        void rotateY(float angle);
        void rotateZ(float angle);

        const GLMatrix& getViewMatrix();
        void buildViewMatrix();

        const GLMatrix& getProjectionMatrix();
        void buildProjectionMatrix();

        Vec3 getPosition();
        Quaternion getOrientation();
        void setOrientation(float x, float y, float z);

        void setAspectRatio(float ar);
        void setPlanes(float np, float fp);
        void setFOV(float angle);

};
#endif // CAMERA_H
