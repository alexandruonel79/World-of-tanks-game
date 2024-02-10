#ifndef Projectile_H
#define Projectile_H
#include "components/simple_scene.h"
#include "lab_m1/lab5/lab_camera.h"
#include "lab_m1/lab5/object2D.h"
#include "lab_m1/lab5/transform3D.h"
#include "lab_m1/lab5/Projectile.h"
namespace m1
{
    class Projectile {
    private:
        float x;
        float y;
        float z;
        float timeAlive;
        glm::vec3 forward_position;
    public:
        Projectile() {
        }
        float getTimeAlive() {
            return timeAlive;
        }
        void setTimeAlive(float time) {
            timeAlive = time;
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
        void setX(float tx) {
            x = tx;
        }
        void setY(float ty) {
            y = ty;
        }
        void setZ(float tz) {
            z = tz;
        }
        void setForwardPosition(glm::vec3 forward) {
            forward_position = forward;
        }
        glm::vec3 getForwardPosition() {
            return forward_position;
        }

        Projectile(float x, float y, float z);

    };
}

#endif
