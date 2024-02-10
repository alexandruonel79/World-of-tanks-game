#include "object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"

Mesh* object2D::CreateSquare(
    const std::string& name,
    glm::vec3 corner,
    float length,
    glm::vec3 color,
    bool fill)
{

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(glm::vec3(0, 0, -1), color),
        VertexFormat(glm::vec3(-length, length, -1), color),
        VertexFormat(glm::vec3(length, length, -1), color),
        VertexFormat(glm::vec3(length, -length, -1), color),
        VertexFormat(glm::vec3(-length, -length, -1), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = {
                                          1, 0, 2,
                                          2, 0, 3,
                                          3, 0, 4,
                                          4, 0, 1
    };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}
Mesh* object2D::CreateSenile(
    const std::string& name,
    float length,
    glm::vec3 color)
{

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(glm::vec3(0, 0, 0), color), // 0
        VertexFormat(glm::vec3(0.1, 0, 0.5), color), // 1
        VertexFormat(glm::vec3(-0.1, 0, 0.5), color), // 2
        VertexFormat(glm::vec3(0.1, 0.1, 0.7), color), // 3
        VertexFormat(glm::vec3(-0.1, 0.1, 0.7), color), // 4
        VertexFormat(glm::vec3(0.1, 0.2, 0.7), color), // 5
        VertexFormat(glm::vec3(-0.1, 0.2, 0.7), color), // 6
        VertexFormat(glm::vec3(0.1, 0.5, 0.1), color), // 7
        VertexFormat(glm::vec3(-0.1, 0.5, 0.1), color), // 8
        /// aici fac partea de jos
        VertexFormat(glm::vec3(0.1, 0, -0.5), color), // 9
        VertexFormat(glm::vec3(-0.1, 0, -0.5), color), // 10
        // senile partea in oglinda
        VertexFormat(glm::vec3(0.1, 0.1, -0.7), color), // 11
        VertexFormat(glm::vec3(-0.1, 0.1, -0.7), color), // 12
        VertexFormat(glm::vec3(0.1, 0.2, -0.7), color), // 13
        VertexFormat(glm::vec3(-0.1, 0.2, -0.7), color), // 14
        VertexFormat(glm::vec3(0.1, 0.5, -0.1), color), // 15
        VertexFormat(glm::vec3(-0.1, 0.5, -0.1), color) // 16
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = {
                                          2, 1, 3,
                                          4, 2, 3,
                                          4, 5, 3,
                                          6, 5, 4,
                                          7, 6, 5,
                                          6, 7, 8,
                                          // aici e partea de jos
                                          1, 0, 2,
                                          0, 9, 10,
                                          2, 0, 10,
                                          9, 0, 1,
                                          10, 9, 11,
                                          12, 10, 11,
                                          12, 13, 11,
                                          14, 13, 12,
                                          15, 14, 13,
                                          14, 15, 16,
                                          // cover lateral
                                          13, 11, 9,
                                          13, 9, 1,
                                          13, 5, 1,
                                          5, 3, 1,
                                          /// cover lateral 
                                          14, 12, 10,
                                          14, 10, 2,
                                          14, 6, 2,
                                          6, 4, 2,
                                          // extra ala de sus umplut
                                          7, 5, 13,
                                          8, 6, 14,
                                         // 7, 15, 14
                                          15, 13, 5,
                                          16, 14, 6
                       
    };

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::CreateCorpTanc(
    const std::string& name,
    float length,
    glm::vec3 color)
{

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(glm::vec3(0, 0.6, 0), color), // 0
        VertexFormat(glm::vec3(0.6, 0.6, 1), color), // 1
        VertexFormat(glm::vec3(-0.6, 0.6, 1), color), // 2
        VertexFormat(glm::vec3(-0.6, 0, 1.5), color), // 3
        VertexFormat(glm::vec3(0.6, 0, 1.5), color), // 4
        // mirror ul
        VertexFormat(glm::vec3(0.6, 0.6, -1), color), // 5
        VertexFormat(glm::vec3(-0.6, 0.6, -1), color), // 6
        VertexFormat(glm::vec3(-0.6, 0, -1.5), color), // 7
        VertexFormat(glm::vec3(0.6, 0, -1.5), color), // 8
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = {
                                          0, 1, 2,
                                          3, 1, 2,
                                          3, 4, 1,
                                          // mirror ul
                                          0, 6, 5,
                                          0, 6, 2,
                                          0, 5, 1,
                                          7, 5, 6,
                                          7, 8, 5,
                                          // lateralele 
                                     /*     7, 5, 3,
                                          1, 5, 3,
                                          8, 2, 6,
                                          4, 8, 2*/
                                          2, 3, 7,
                                          6, 7, 2,
                                          1, 5, 8,
                                          1, 8, 4
    };

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::CreateTopTanc(
    const std::string& name,
    float length,
    glm::vec3 color)
{

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(glm::vec3(0, 0.6, 0), color), // 0

        VertexFormat(glm::vec3(0.7, 0.6, -0.6), color), // 1
        VertexFormat(glm::vec3(0.7, 0.6, 0.45), color), // 2

        VertexFormat(glm::vec3(0.5, 0.9, -0.3), color), // 3
        VertexFormat(glm::vec3(0.5, 0.9, 0.3), color), // 4

        VertexFormat(glm::vec3(-0.7, 0.6, -0.6), color), // 5
        VertexFormat(glm::vec3(-0.7, 0.6, 0.45), color), // 6

        VertexFormat(glm::vec3(-0.5, 0.9, -0.3), color), // 7 
        VertexFormat(glm::vec3(-0.5, 0.9, 0.3), color), // 8
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = {
                                       // deasupra
                                       7, 8, 4,
                                       7, 3, 4,
                                       // lateralele
                                       3, 2, 1,
                                       3, 2, 4,
                                       7, 6, 5,
                                       7, 6, 8,
                                       // fata
                                       7, 1, 5,
                                       7, 1, 3,
                                       // spatele
                                       6, 2, 4,
                                       6, 4, 8

    };

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::CreateCircle(
    const std::string& name,
    float length,
    glm::vec3 color)
{

    std::vector<VertexFormat> vertices =
    {
        // primul cerc
        VertexFormat(glm::vec3(0, 0.5, -2), color), // 0
        VertexFormat(glm::vec3(0, 0.25, -2), color), // 1
        VertexFormat(glm::vec3(0.17, 0.32, -2), color), // 2
        VertexFormat(glm::vec3(0.25, 0.5, -2), color), // 3
        VertexFormat(glm::vec3(0.17, 0.68, -2), color), // 4
        VertexFormat(glm::vec3(0, 0.75, -2), color), // 5
        VertexFormat(glm::vec3(-0.17, 0.68, -2), color), // 6
        VertexFormat(glm::vec3(-0.25, 0.5, -2), color), // 7
        VertexFormat(glm::vec3(-0.17, 0.32, -2), color), // 8

        // al doilea cerc
        VertexFormat(glm::vec3(0, 0.5, -0.2), color), // 9
        VertexFormat(glm::vec3(0, 0.25, -0.2), color), // 10
        VertexFormat(glm::vec3(0.17, 0.32, -0.2), color), // 11
        VertexFormat(glm::vec3(0.25, 0.5, -0.2), color), // 12
        VertexFormat(glm::vec3(0.17, 0.68, -0.2), color), // 13
        VertexFormat(glm::vec3(0, 0.75, -0.2), color), // 14
        VertexFormat(glm::vec3(-0.17, 0.68, -0.2), color), // 15
        VertexFormat(glm::vec3(-0.25, 0.5, -0.2), color), // 16
        VertexFormat(glm::vec3(-0.17, 0.32, -0.2), color), // 17
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = {
        // primul cerc
        0, 1, 2,
        0, 2, 3,
        0, 3, 4,
        0, 4, 5,
        0, 5, 6,
        0, 6, 7,
        0, 7, 8,
        0, 8, 1,
        // al doilea cerc
        9, 10, 11,
        9, 11, 12,
        9, 12, 13,
        9, 13, 14,
        9, 14, 15,
        9, 15, 16,
        9, 16, 17,
        9, 17, 10,
        // unirea cercurilor
        1, 10, 11,
        2, 11, 12,
        3, 12, 13,
        4, 13, 14,
        5, 14, 15,
        6, 15, 16,
        7, 16, 17,
        8, 17, 10,
        // invers
        10, 1, 2,
        11, 2, 3,
        12, 3, 4,
        13, 4, 5,
        14, 5, 6,
        15, 6, 7,
        16, 7, 8,
        17, 8, 1,
        // extra
        11, 1, 2,
        12, 2, 3,
        13, 3, 4,
        14, 4, 5,
        15, 5, 6,
        16, 6, 7,
        17, 7, 8,
        10, 8, 1


    };

    square->InitFromData(vertices, indices);
    return square;
}
Mesh* object2D::CreateCub(
    const std::string& name,
    float length,
    glm::vec3 color)
{

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(glm::vec3(0, 0, -1), color), // 0
        VertexFormat(glm::vec3(0, 0, 0), color), // 1
        VertexFormat(glm::vec3(1, 0, 0), color), // 2
        VertexFormat(glm::vec3(1, 0, -1), color), // 3
        VertexFormat(glm::vec3(0, 1, -1), color), // 4
        VertexFormat(glm::vec3(0, 1, 0), color), // 5
        VertexFormat(glm::vec3(1, 1, 0), color), // 6
        VertexFormat(glm::vec3(1, 1, -1), color), // 7
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = {
        // primul cerc
        0, 1, 2,
        0, 2, 3,

        4, 7, 6,
        4, 6, 5,

        4, 5, 0,
        5, 0, 1,

        5, 1, 2,
        2, 6, 5,

        3, 7, 6,
        2, 3, 6,

        3, 0, 7,
        4, 7, 0



    };

    square->InitFromData(vertices, indices);
    return square;
}
