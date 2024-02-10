#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace object2D
{
    // don t touch it
    Mesh* CreateSquare(const std::string &name, glm::vec3 corner, float length, glm::vec3 color, bool fill = false);

    Mesh* CreateSenile(const std::string& name, float length, glm::vec3 color);

    Mesh* CreateCorpTanc(const std::string& name, float length, glm::vec3 color);

    Mesh* CreateTopTanc(const std::string& name, float length, glm::vec3 color);

    Mesh* CreateCircle(const std::string& name, float length, glm::vec3 color);

    Mesh* CreateCub(const std::string& name, float length, glm::vec3 color);
}
