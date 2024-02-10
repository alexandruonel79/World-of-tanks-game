#pragma once

#include "components/simple_scene.h"
#include "lab_m1/lab5/lab_camera.h"
#include "lab_m1/lab5/object2D.h"
#include "lab_m1/lab5/transform3D.h"
#include "lab_m1/lab5/Projectile.h"
#include "lab_m1/lab5/Tank.h"


namespace m1
{
    class Lab5 : public gfxc::SimpleScene
    {
     public:
        Lab5();
        ~Lab5();

        void Init() override;

     private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void RenderMesh(Mesh *mesh, Shader *shader, const glm::mat4 &modelMatrix) override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;
        void RenderTank(glm::vec3 tank_pos, float rotation, bool isEnemy);
        void RenderScene(float deltaTimeSeconds);
        void RenderProjectiles(float deltaTimeSeconds);
        void RenderEnemyTanks(float deltaTimeSeconds);
        void checkCollisionProjectiles();
        void checkCollisionTanks();
        void checkCollisionEnemyBetweenEnemy();
     protected:
        implemented::Camera *camera;
        glm::mat4 projectionMatrix;
        GLenum polygonMode;

        // tank variables
        glm::vec3 forward_position;
        glm::vec3 tank_position;
        float tank_rotation;
        float turret_rotation;

        glm::mat4 modelMatrix;
        float lastTurn;

        std::vector<Projectile> projectiles;
        std::vector<Tank> enemyTanks;
        std::vector<Projectile> enemy_projectiles;
        float timePlayed;
        float raza_tank;
        float raza_proiectil;
    };
}   // namespace m1
