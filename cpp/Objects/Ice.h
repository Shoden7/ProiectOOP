
//
// Created by Stefan on 11/4/2024.
//

#ifndef ICE_H
#define ICE_H

#include "Environment.h"
#include <iostream>

/**
 * @class Ice
 * @brief Represents an icy surface in the game world that affects the player's speed.
 *
 * The Ice class modifies the player's speed when colliding with it, simulating slippery conditions.
 */
class Ice : public Environment {
    GDCLASS(Ice, Environment); // Godot class registration

private:
    /**
     * @brief The factor by which the player's speed is multiplied when colliding with the ice.
     */
    float speedMultiplier;

public:
    /**
     * @brief Constructor for the Ice class.
     *
     * Initializes the speed multiplier for the ice and its collision state.
     *
     * @param newSpeedMultiplier The multiplier to apply to the player's speed when on the ice.
     */
    Ice(float newSpeedMultiplier = 1.5f)
        : speedMultiplier(newSpeedMultiplier) {
        SetCollision(true); // Ice always has a collision state
    }

    /**
     * @brief Copy constructor for the Ice class.
     *
     * Creates a new Ice instance by copying data from another Ice instance.
     *
     * @param other The Ice instance to copy from.
     */
    Ice(const Ice &other)
        : Environment(other), speedMultiplier(other.speedMultiplier) {
    }

    /**
     * @brief Assignment operator for the Ice class.
     *
     * Assigns the data of one Ice instance to another.
     *
     * @param other The Ice instance to copy data from.
     * @return A reference to the updated Ice instance.
     */
    Ice &operator=(const Ice &other) {
        if (this != &other) {
            // Avoid self-assignment
            Environment::operator=(other);
            speedMultiplier = other.speedMultiplier;
        }
        return *this;
    }

    /**
     * @brief Stream insertion operator for the Ice class.
     *
     * Outputs the ice's speed multiplier and collision state.
     *
     * @param os The output stream.
     * @param ice The Ice instance to output.
     * @return A reference to the updated output stream.
     */
    friend std::ostream &operator<<(std::ostream &os, const Ice &ice) {
        os << "Ice(Speed Multiplier: " << ice.speedMultiplier << ", Collision: "
                << (ice.GetCollision() ? "true" : "false") << ")";
        return os;
    }

    /**
     * @brief Gets the speed multiplier for the ice.
     *
     * @return The multiplier that modifies the player's speed when on the ice.
     */
    float GetSpeedMultiplier() const { return speedMultiplier; }

    /**
     * @brief Sets the speed multiplier for the ice.
     *
     * @param multiplier The new speed multiplier for the ice.
     */
    void SetSpeedMultiplier(float multiplier) { speedMultiplier = multiplier; }

    /**
     * @brief Applies the effect of ice to the player's speed when colliding with it.
     *
     * This function should be called when checking if the player is colliding with the ice. It modifies
     * the player's speed based on the ice's speed multiplier.
     *
     * @param playerSpeed The player's current speed to modify.
     * @return The modified player speed after applying the ice effect.
     */
    Vector2 ApplyIceEffect(Vector2 playerSpeed) const {
        return playerSpeed * speedMultiplier;
    }

    /**
     * @brief Binds methods to Godot for use in the editor or scripts.
     */
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("GetSpeedMultiplier"), &Ice::GetSpeedMultiplier);
        ClassDB::bind_method(D_METHOD("SetSpeedMultiplier", "multiplier"), &Ice::SetSpeedMultiplier);
        ClassDB::bind_method(D_METHOD("ApplyIceEffect", "playerSpeed"), &Ice::ApplyIceEffect);
    }
};

#endif //ICE_H
