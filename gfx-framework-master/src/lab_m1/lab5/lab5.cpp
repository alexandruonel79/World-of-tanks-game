#include "lab_m1/lab5/lab5.h"

#include <vector>
#include <string>
#include <iostream>
#include <cstdlib> 
#include <ctime>   

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Lab5::Lab5()
{
}


Lab5::~Lab5()
{
}


void Lab5::Init()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    timePlayed = glfwGetTime();

    camera = new implemented::Camera();

    // tank initial position
    forward_position = glm::vec3(0.0f, 0.0f, 1.0f);
    tank_position = glm::vec3(0.0f, 0.5f, -1.5f);
    tank_rotation = 0;
    turret_rotation = 0;
    lastTurn = 0;

    // set some enemies
    Tank new_tank_1;
    new_tank_1 = Tank(15, 0, 15);
    new_tank_1.setRotation(0);
    new_tank_1.setForwardPosition(forward_position);
    new_tank_1.setAmountRotation(0);
    new_tank_1.setAmRotating(false);
    new_tank_1.setRotateDir(-1);
    enemyTanks.push_back(new_tank_1);

    Tank new_tank_2;
    new_tank_2 = Tank(-15, 0, 15);
    new_tank_2.setRotation(0);
    new_tank_2.setForwardPosition(forward_position);
    new_tank_2.setAmountRotation(0);
    new_tank_2.setAmRotating(false);
    new_tank_2.setRotateDir(-1);
    enemyTanks.push_back(new_tank_2);

    Tank new_tank_3;
    new_tank_3 = Tank(15, 0, -15);
    new_tank_3.setRotation(0);
    new_tank_3.setForwardPosition(forward_position);
    new_tank_3.setAmountRotation(0);
    new_tank_3.setAmRotating(false);
    new_tank_3.setRotateDir(-1);
    enemyTanks.push_back(new_tank_3);

    Tank new_tank_4;
    new_tank_4 = Tank(5, 0, -15);
    new_tank_4.setRotation(0);
    new_tank_4.setForwardPosition(forward_position);
    new_tank_4.setAmountRotation(0);
    new_tank_4.setAmRotating(false);
    new_tank_4.setRotateDir(-1);
    enemyTanks.push_back(new_tank_4);

    Tank new_tank_5;
    new_tank_5 = Tank(-15, 0, -15);
    new_tank_5.setRotation(0);
    new_tank_5.setForwardPosition(forward_position);
    new_tank_5.setAmountRotation(0);
    new_tank_5.setAmRotating(false);
    new_tank_5.setRotateDir(-1);
    enemyTanks.push_back(new_tank_5);

    Tank new_tank_6;
    new_tank_6 = Tank(20, 0, 10);
    new_tank_6.setRotation(0);
    new_tank_6.setForwardPosition(forward_position);
    new_tank_6.setAmountRotation(0);
    new_tank_6.setAmRotating(false);
    new_tank_6.setRotateDir(-1);
    enemyTanks.push_back(new_tank_6);

    Tank new_tank_7;
    new_tank_7 = Tank(30, 0, 30);
    new_tank_7.setRotation(0);
    new_tank_7.setForwardPosition(forward_position);
    new_tank_7.setAmountRotation(0);
    new_tank_7.setAmRotating(false);
    new_tank_7.setRotateDir(-1);
    enemyTanks.push_back(new_tank_7);

    Tank new_tank_8;
    new_tank_8 = Tank(36, 0, 36);
    new_tank_8.setRotation(0);
    new_tank_8.setForwardPosition(forward_position);
    new_tank_8.setAmountRotation(0);
    new_tank_8.setAmRotating(false);
    new_tank_8.setRotateDir(-1);
    enemyTanks.push_back(new_tank_8);

    Tank new_tank_9;
    new_tank_9 = Tank(40, 0, 20);
    new_tank_9.setRotation(0);
    new_tank_9.setForwardPosition(forward_position);
    new_tank_9.setAmountRotation(0);
    new_tank_9.setAmRotating(false);
    new_tank_9.setRotateDir(-1);
    enemyTanks.push_back(new_tank_9);

    Tank new_tank_10;
    new_tank_10 = Tank(25, 0, 45);
    new_tank_10.setRotation(0);
    new_tank_10.setForwardPosition(forward_position);
    new_tank_10.setAmountRotation(0);
    new_tank_10.setAmRotating(false);
    new_tank_10.setRotateDir(-1);
    enemyTanks.push_back(new_tank_10);

    camera = new implemented::Camera();

    Mesh* senile = object2D::CreateSenile("senile", 0.2, glm::vec3(0.522, 0.522, 0.522));
    AddMeshToList(senile);

    Mesh* corp_Tanc = object2D::CreateCorpTanc("corp_Tanc", 0.2, glm::vec3(0.09, 0.239, 0.09));
    AddMeshToList(corp_Tanc);

    Mesh* top_Tanc = object2D::CreateTopTanc("top_Tanc", 0.2, glm::vec3(0.204, 0.569, 0.204));
    AddMeshToList(top_Tanc);

    Mesh* tureta_Tanc = object2D::CreateCircle("tureta_Tanc", 0.2, glm::vec3(0.522, 0.522, 0.522));
    AddMeshToList(tureta_Tanc);

    // for enemy
    Mesh* corp_Tanc_Red= object2D::CreateCorpTanc("corp_Tanc_Red", 0.2, glm::vec3(0.922, 0.043, 0.043));
    AddMeshToList(corp_Tanc_Red);

    Mesh* top_Tanc_Red = object2D::CreateTopTanc("top_Tanc_Red", 0.2, glm::vec3(0.922, 0.043, 0.043));
    AddMeshToList(top_Tanc_Red);

    // mesh cub gri
    Mesh* cub_gri = object2D::CreateCub("cub_gri", 0.2, glm::vec3(0.757, 0.757, 0.788));
    AddMeshToList(cub_gri);

    {
        Mesh* mesh = new Mesh("sphere");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "sphere.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    // TODO(student): After you implement the changing of the projection
    // parameters, remove hardcodings of these parameters
    projectionMatrix = glm::perspective(RADIANS(60), window->props.aspectRatio, 0.01f, 200.0f);

    raza_tank = 2.0;
    raza_proiectil = 0.4;
}

void Lab5::RenderTank(glm::vec3 tank_pos, float rotation, bool isEnemy) {
    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(tank_pos.x, tank_pos.y, tank_pos.z);
    modelMatrix *= transform3D::Scale(1, 1, 1);
    modelMatrix *= transform3D::RotateOY(rotation);

    if (!isEnemy) {
        RenderMesh(meshes["corp_Tanc"], shaders["VertexColor"], modelMatrix);
    }
    else {
        RenderMesh(meshes["corp_Tanc_Red"], shaders["VertexColor"], modelMatrix);
    }
    
    glm::mat4 modelMatrixSenila = modelMatrix;
    modelMatrix *= transform3D::Translate(-0.35, -0.2, 0);
    modelMatrix *= transform3D::Scale(2.2f, 1, 2.2f);
    RenderMesh(meshes["senile"], shaders["VertexColor"], modelMatrix);


    modelMatrixSenila *= transform3D::Translate(0.35, -0.2, 0);
    modelMatrixSenila *= transform3D::Scale(2.2f, 1, 2.2f);
    RenderMesh(meshes["senile"], shaders["VertexColor"], modelMatrixSenila);

    modelMatrix *= transform3D::Translate(0.16f, 0.3f, 0);
    modelMatrix *= transform3D::Scale(0.3f, 0.9f, 0.5f);

    if (!isEnemy) {
        RenderMesh(meshes["top_Tanc"], shaders["VertexColor"], modelMatrix);
    }
    else {
        RenderMesh(meshes["top_Tanc_Red"], shaders["VertexColor"], modelMatrix);
    }

    if (!isEnemy) {
        modelMatrix *= transform3D::RotateOY(turret_rotation);
    }
    modelMatrix *= transform3D::Translate(0, 0.5f, 0);
    modelMatrix *= transform3D::Scale(0.3f, 0.3f, 1);
    RenderMesh(meshes["tureta_Tanc"], shaders["VertexColor"], modelMatrix);

    if (!isEnemy) {
        glm::vec3 positioning_correction = glm::vec3(-3, 2, -3);
        forward_position = glm::rotate(glm::mat4(1.0f), rotation, glm::vec3(0, 1, 0)) * glm::vec4(0, 0, 1, 0);
        glm::vec3 position = tank_pos + forward_position * -positioning_correction.z + glm::vec3(0, positioning_correction.y, 0);
        camera->Set(position, tank_pos, glm::vec3(0, 1, 0));
    }
}

void Lab5::RenderEnemyTanks(float deltaTimeSeconds) {
    for (int i = 0; i < enemyTanks.size(); i++) {
        glm::vec3 position_enemy = glm::vec3(enemyTanks[i].getX(), enemyTanks[i].getY(), enemyTanks[i].getZ());
        RenderTank(position_enemy, enemyTanks[i].getRotation(), true);
    }
}

void Lab5::RenderProjectiles(float deltaTimeSeconds) {
    for (int i = 0; i < projectiles.size(); i++) {
        if (glfwGetTime() - projectiles[i].getTimeAlive() >= 10) {
            // delete it
            projectiles.erase(projectiles.begin() + i);
            break;
        }
        modelMatrix = glm::mat4(1);
        projectiles[i].setX(projectiles[i].getX() - projectiles[i].getForwardPosition().x * deltaTimeSeconds * 10);
        projectiles[i].setY(projectiles[i].getY() - projectiles[i].getForwardPosition().y * deltaTimeSeconds * 10);
        projectiles[i].setZ(projectiles[i].getZ() - projectiles[i].getForwardPosition().z * deltaTimeSeconds * 10);

        modelMatrix *= transform3D::Translate(projectiles[i].getX(), projectiles[i].getY(), projectiles[i].getZ());
        modelMatrix *= transform3D::Scale(0.2f, 0.2f, 0.2f);
        RenderMesh(meshes["sphere"], shaders["VertexColor"], modelMatrix);
    }
}

void Lab5::RenderScene(float deltaTimeSeconds) {
    // building one 
    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(5, 0, 6);
    modelMatrix *= transform3D::Scale(10, 5, 3);
    RenderMesh(meshes["cub_gri"], shaders["VertexColor"], modelMatrix);
    // building two 
    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(-5, 0, -6);
    modelMatrix *= transform3D::Scale(8, 7, 6);
    RenderMesh(meshes["cub_gri"], shaders["VertexColor"], modelMatrix);
    // deocamdata doar asta
    RenderTank(tank_position, tank_rotation, false);
    RenderEnemyTanks(deltaTimeSeconds);
}

void Lab5::checkCollisionProjectiles() {
    for (int i = 0; i < projectiles.size(); i++) {
        for (int j = 0; j < enemyTanks.size(); j++) {
            float distance = sqrt((projectiles[i].getX() - enemyTanks[j].getX()) * (projectiles[i].getX() - enemyTanks[j].getX()) +
                ((projectiles[i].getY() - enemyTanks[j].getY()) * (projectiles[i].getY() - enemyTanks[j].getY())) +
                ((projectiles[i].getZ() - enemyTanks[j].getZ()) * (projectiles[i].getZ() - enemyTanks[j].getZ()))
            );

            if (distance < raza_proiectil + raza_tank) {
                enemyTanks.erase(enemyTanks.begin() + j);
                projectiles.erase(projectiles.begin() + i);
                cout << "COLLISION DETECTED" << endl;
                break;
            }
        }
    }
}
void Lab5::checkCollisionTanks() {
        for (int j = 0; j < enemyTanks.size(); j++) {
            float distance = sqrt((tank_position.x - enemyTanks[j].getX()) * (tank_position.x - enemyTanks[j].getX()) +
                ((tank_position.y - enemyTanks[j].getY()) * (tank_position.y - enemyTanks[j].getY())) +
                ((tank_position.z - enemyTanks[j].getZ()) * (tank_position.z - enemyTanks[j].getZ()))
            );
            if (distance < raza_tank + raza_tank) {
                glm::vec3 tank_center(tank_position.x, tank_position.y, tank_position.z);
                glm::vec3 enemy_center(enemyTanks[j].getX(), enemyTanks[j].getY(), enemyTanks[j].getZ());
                glm::vec3 dif = enemy_center - tank_center;

                float dist_p = (raza_tank + raza_tank - distance);
                glm::vec3 P = dist_p * glm::normalize(dif);

                tank_center += P * -0.5f;
                enemy_center += P * 0.5f;

                tank_position.x = tank_center.x;
                tank_position.z = tank_center.z;

                enemyTanks[j].setX(enemy_center.x);
                enemyTanks[j].setZ(enemy_center.z);

                cout << "WE BUMPED !!!!" << endl;
                break;
            }
        }
}
void Lab5::checkCollisionEnemyBetweenEnemy() {
    for (int i = 0; i < enemyTanks.size(); i++) {
        for (int j = 0; j < enemyTanks.size() && j != i; j++) {
            float distance = sqrt((enemyTanks[i].getX() - enemyTanks[j].getX()) * (enemyTanks[i].getX() - enemyTanks[j].getX()) +
                ((enemyTanks[i].getY() - enemyTanks[j].getY()) * (enemyTanks[i].getY() - enemyTanks[j].getY())) +
                ((enemyTanks[i].getZ() - enemyTanks[j].getZ()) * (enemyTanks[i].getZ() - enemyTanks[j].getZ()))
            );
            if (distance < raza_tank + raza_tank) {
                glm::vec3 tank_center(enemyTanks[i].getX(), enemyTanks[i].getY(), enemyTanks[i].getZ());
                glm::vec3 enemy_center(enemyTanks[j].getX(), enemyTanks[j].getY(), enemyTanks[j].getZ());
                glm::vec3 dif = enemy_center - tank_center;

                float dist_p = (raza_tank + raza_tank - distance);
                glm::vec3 P = dist_p * glm::normalize(dif);

                tank_center += P * -0.5f;
                enemy_center += P * 0.5f;

                enemyTanks[i].setX(tank_center.x);
                enemyTanks[i].setZ(tank_center.z);

                enemyTanks[j].setX(enemy_center.x);
                enemyTanks[j].setZ(enemy_center.z);

                cout << "ENEMY TANKS BUMPED !!!!" << endl;
                break;
            }
        }
    }
}
void Lab5::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}


void Lab5::Update(float deltaTimeSeconds)
{

    // check for game time ending
    // set to 3 minutes
    if (glfwGetTime() - timePlayed >= 180) {
        cout << "Game OVER" << endl;
        exit(0);
    }

    // Sets the screen area where to draw
    glm::ivec2 resolution = window->GetResolution();
    glViewport(0, 0, resolution.x, resolution.y);

    RenderScene(deltaTimeSeconds);
    RenderProjectiles(deltaTimeSeconds);

    for (int i = 0; i < enemyTanks.size(); i++) {
        enemyTanks[i].setX(enemyTanks[i].getX() - enemyTanks[i].getForwardPosition().x * deltaTimeSeconds);
        enemyTanks[i].setY(enemyTanks[i].getY() - enemyTanks[i].getForwardPosition().y * deltaTimeSeconds);
        enemyTanks[i].setZ(enemyTanks[i].getZ() - enemyTanks[i].getForwardPosition().z * deltaTimeSeconds);

        if ((glfwGetTime() - lastTurn >= 1) && !enemyTanks[i].getAmRotating() && enemyTanks[i].getAmountRotation() == 0) {
            int rotateOrNot = rand() % 2;

            if (rotateOrNot == 1) {
                enemyTanks[i].setAmRotating(true);
                enemyTanks[i].setRotateDir(rand() % 2);
                enemyTanks[i].setAmountRotation(rand() % 10 + 30);
            }
            else {
                enemyTanks[i].setAmRotating(false);
            }
        }

        if (enemyTanks[i].getAmRotating()) {
            if (enemyTanks[i].getRotateDir() == 0) {
                enemyTanks[i].setRotation(enemyTanks[i].getRotation() + deltaTimeSeconds * 5);

                glm::vec4 aux_enemy = glm::rotate(glm::mat4(1.f), deltaTimeSeconds * 5, glm::vec3(0, 1, 0)) * glm::vec4(enemyTanks[i].getForwardPosition(), 0);
                glm::vec3 forward_position_aux = glm::normalize(glm::vec3(aux_enemy));
                enemyTanks[i].setForwardPosition(forward_position_aux);

                enemyTanks[i].setAmountRotation(enemyTanks[i].getAmountRotation() - 1);
            }
            else {
                enemyTanks[i].setRotation(enemyTanks[i].getRotation() - deltaTimeSeconds * 5);

                glm::vec4 aux_enemy = glm::rotate(glm::mat4(1.f), -deltaTimeSeconds * 5, glm::vec3(0, 1, 0)) * glm::vec4(enemyTanks[i].getForwardPosition(), 0);
                glm::vec3 forward_position_aux = glm::normalize(glm::vec3(aux_enemy));
                enemyTanks[i].setForwardPosition(forward_position_aux);

                enemyTanks[i].setAmountRotation(enemyTanks[i].getAmountRotation() - 1);
            }

            if (enemyTanks[i].getAmountRotation() == 0) {
                enemyTanks[i].setAmRotating(false);
                lastTurn = glfwGetTime();
            }
        }
    }

    // check collision
    checkCollisionProjectiles();
    checkCollisionTanks();
    checkCollisionEnemyBetweenEnemy();
}


void Lab5::FrameEnd()
{
    DrawCoordinateSystem(camera->GetViewMatrix(), projectionMatrix);
}


void Lab5::RenderMesh(Mesh * mesh, Shader * shader, const glm::mat4 & modelMatrix)
{
    if (!mesh || !shader || !shader->program)
        return;

    // Render an object using the specified shader and the specified position
    shader->Use();
    glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));
    glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    mesh->Render();
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Lab5::OnInputUpdate(float deltaTime, int mods)
{
    if (window->KeyHold(GLFW_KEY_W)) {
        glm::vec3 dir = glm::normalize(glm::vec3(forward_position.x, 0, forward_position.z));
        tank_position -= dir * deltaTime;
    }

    if (window->KeyHold(GLFW_KEY_S)) {
        glm::vec3 dir = glm::normalize(glm::vec3(forward_position.x, 0, forward_position.z));
        tank_position += dir * deltaTime;
    }
    if (window->KeyHold(GLFW_KEY_A)) {
        tank_rotation += deltaTime;
        glm::vec4 aux = glm::rotate(glm::mat4(1.f), deltaTime, glm::vec3(0, 1, 0)) * glm::vec4(forward_position, 0);
        forward_position = glm::normalize(glm::vec3(aux));
    }
    if (window->KeyHold(GLFW_KEY_D)) {
        tank_rotation -= deltaTime;
        glm::vec4 aux = glm::rotate(glm::mat4(1.f), -deltaTime, glm::vec3(0, 1, 0)) * glm::vec4(forward_position, 0);
        forward_position = glm::normalize(glm::vec3(aux));
    }
}


void Lab5::OnKeyPress(int key, int mods)
{
    // Add key press event
    if (key == GLFW_KEY_SPACE)
    {
        Projectile new_projectile = Projectile(tank_position.x - forward_position.x * 0.5, tank_position.y + 1.3f, tank_position.z - forward_position.z * 0.5);
        new_projectile.setTimeAlive(glfwGetTime());
        new_projectile.setForwardPosition(forward_position);
        projectiles.push_back(new_projectile);
    }
}


void Lab5::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Lab5::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    turret_rotation -= deltaX * 0.001;
}


void Lab5::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
}


void Lab5::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Lab5::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Lab5::OnWindowResize(int width, int height)
{
}
