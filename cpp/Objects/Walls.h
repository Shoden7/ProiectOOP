//
// Created by Stefan on 11/4/2024.
//

#ifndef WALLS_H
#define WALLS_H

#include "Environment.h"
#include <array>
#include <iostream>

/**
 * @class Walls
 * @brief Represents a collection of environmental elements forming walls.
 *
 * This class manages the dimensions and coordinates of walls in the game world.
 */
class Walls : public Environment {
    GDCLASS(Walls, Environment) // Godot class registration

private:
    /**
     * @brief Array of coordinates defining the positions of the walls.
     */
    std::array<Environment, 4> coordinates;

    /**
     * @brief Array of dimensions defining the sizes of the walls.
     */
    std::array<Environment, 4> dimensions;

public:
    /**
     * @brief Constructor for the Walls class.
     *
     * Initializes the walls with the provided coordinates and dimensions.
     *
     * @param newCoordinates The array of coordinates for the walls.
     * @param newDimensions The array of dimensions for the walls.
     */
    Walls(const std::array<Environment, 4> &newCoordinates,
          const std::array<Environment, 4> &newDimensions)
        : coordinates(newCoordinates), dimensions(newDimensions) {
    }

    /**
     * @brief Copy constructor for the Walls class.
     *
     * Creates a new Walls instance by copying data from another Walls instance.
     *
     * @param other The Walls instance to copy from.
     */
    Walls(const Walls &other)
        : Environment(other), coordinates(other.coordinates), dimensions(other.dimensions) {
    }

    /**
     * @brief Assignment operator for the Walls class.
     *
     * Assigns the data of one Walls instance to another.
     *
     * @param other The Walls instance to copy data from.
     * @return A reference to the updated Walls instance.
     */
    Walls &operator=(const Walls &other) {
        if (this != &other) {
            // Avoid self-assignment
            Environment::operator=(other);
            coordinates = other.coordinates;
            dimensions = other.dimensions;
        }
        return *this;
    }

    /**
     * @brief Stream insertion operator for the Walls class.
     *
     * Outputs the coordinates and dimensions of the Walls instance.
     *
     * @param os The output stream.
     * @param walls The Walls instance to output.
     * @return A reference to the updated output stream.
     */
    friend std::ostream &operator<<(std::ostream &os, const Walls &walls) {
        os << "Walls(Coordinates: [";
        for (const auto &coord: walls.coordinates) {
            os << coord << ", ";
        }
        os << "], Dimensions: [";
        for (const auto &dim: walls.dimensions) {
            os << dim << ", ";
        }
        os << "])";
        return os;
    }

    /**
     * @brief Gets the coordinates of the walls.
     *
     * @return An array of Environment instances representing the wall coordinates.
     */
    std::array<Environment, 4> GetCoordinates() const { return coordinates; }

    /**
     * @brief Gets the dimensions of the walls.
     *
     * @return An array of Environment instances representing the wall dimensions.
     */
    std::array<Environment, 4> GetDimensions() const { return dimensions; }

    /**
     * @brief Binds methods to Godot for use in the editor or scripts.
     */
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("GetCoordinates"), &Walls::GetCoordinates);
        ClassDB::bind_method(D_METHOD("GetDimensions"), &Walls::GetDimensions);
    }
};

#endif // WALLS_H
