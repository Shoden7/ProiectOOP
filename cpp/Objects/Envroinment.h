//
// Created by Stefan on 11/4/2024.
//

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "../../godot/godot-cpp/include/godot_cpp/core/class_db.hpp"
#include "../../godot/godot-cpp/gen/include/godot_cpp/variant/utility_functions.hpp"
#include <iostream>

using namespace godot;

/**
 * @class Environment
 * @brief Represents an individual environment element in the game world.
 *
 * This class manages collision states and interacts with Godot's systems for environmental features.
 */
class Environment : public Object {
    GDCLASS(Environment, Object) // Godot class registration

private:
    /**
     * @brief Indicates whether the environment is currently colliding.
     */
    bool isColliding;

public:
    /**
     * @brief Default constructor for the Environment class.
     *
     * Initializes the `isColliding` flag to `false`.
     */
    Environment() : isColliding(false) {
    }

    /**
     * @brief Copy constructor for the Environment class.
     *
     * Creates a new Environment instance by copying data from another Environment instance.
     *
     * @param other The Environment instance to copy from.
     */
    Environment(const Environment &other) : isColliding(other.isColliding) {
    }

    /**
     * @brief Assignment operator for the Environment class.
     *
     * Assigns the data of one Environment instance to another.
     *
     * @param other The Environment instance to copy data from.
     * @return A reference to the updated Environment instance.
     */
    Environment &operator=(const Environment &other) {
        if (this != &other) {
            // Avoid self-assignment
            isColliding = other.isColliding;
        }
        return *this;
    }

    /**
     * @brief Stream insertion operator for the Environment class.
     *
     * Outputs the collision state of the Environment instance.
     *
     * @param os The output stream.
     * @param environment The Environment instance to output.
     * @return A reference to the updated output stream.
     */
    friend std::ostream &operator<<(std::ostream &os, const Environment &environment) {
        os << "Environment(Collision: " << (environment.isColliding ? "true" : "false") << ")";
        return os;
    }

    /**
     * @brief Gets the collision state of the environment.
     *
     * @return `true` if the environment is colliding, `false` otherwise.
     */
    bool GetCollision() const { return isColliding; }

    /**
     * @brief Sets the collision state of the environment.
     *
     * @param collision The new collision state.
     */
    void SetCollision(bool collision) { isColliding = collision; }

    /**
     * @brief Binds methods to Godot for use in the editor or scripts.
     */
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("GetCollision"), &Environment::GetCollision);
        ClassDB::bind_method(D_METHOD("SetCollision", "collision"), &Environment::SetCollision);
    }
};

#endif // ENVIRONMENT_H
