#ifndef Tank_H
#define Tank_H
#include "components/simple_scene.h"
#include "lab_m1/lab5/lab_camera.h"
#include "lab_m1/lab5/object2D.h"
#include "lab_m1/lab5/transform3D.h"
#include "lab_m1/lab5/Tank.h"
namespace m1
{
    class Tank {
    private:
        float x;
        float y;
        float z;
        float rotation;
        int amountRotation;
        bool amRotating;
        int rotateDir;
        glm::vec3 forward_position;
    public:
        Tank() {
        }
        int getAmountRotation() {
            return amountRotation;
        }
        bool getAmRotating() {
            return amRotating;
        }
        int getRotateDir() {
            return rotateDir;
        }
        float getX() {
            return x;
        }
        float getY() {
            return y;
        }
        float getZ() {
            return z;
        }
        float getRotation() {
            return rotation;
        }
        void setRotation(float rot) {
            rotation = rot;
        }
        void setX(float tx) {
            x = tx;
        }
        void setY(float ty) {
            y = ty;
        }
        void setZ(float tz) {
            z = tz;
        }
        void setRotateDir(int rt) {
            rotateDir = rt;
        }
        void setAmRotating(bool rtt) {
            amRotating = rtt;
        }
        void setAmountRotation(int aaa) {
            amountRotation = aaa;
        }
        void setForwardPosition(glm::vec3 forward) {
            forward_position = forward;
        }
        glm::vec3 getForwardPosition() {
            return forward_position;
        }

        Tank(float x, float y, float z);

    };
}

#endif
