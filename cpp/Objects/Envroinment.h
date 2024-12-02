//
// Created by Stefan on 11/4/2024.
//

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <array>


class Environment {
private:
    bool isColliding;

public:
    // Constructor
    Environment() = default;

    // Getter
    bool GetCollision() const { return isColliding; };
};


class Walls {
private:
    std::array<Environment, 4> coordinates;
    std::array<Environment, 4> dimensions;

public:
    // Constructor
    Walls(const std::array<Environment, 4> &newCoordinates,
          const std::array<Environment, 4> &newDimensions) : coordinates(newCoordinates), dimensions(newDimensions) {
    }

    // Getter
    std::array<Environment, 4> GetCoordinates() const { return coordinates; }
    std::array<Environment, 4> GetDimensions() const { return dimensions; }
};


#endif //ENVIRONMENT_H
