#include <Environment.h>

/**
 * @brief Default constructor for the Environment class.
 *
 * Initializes the collision state to `false`.
 */
Environment::Environment() : isColliding(false) {
}

/**
 * @brief Copy constructor for the Environment class.
 *
 * Copies the collision state from another Environment instance.
 * @param other The Environment instance to copy from.
 */
Environment::Environment(const Environment &other) : isColliding(other.isColliding) {
}

/**
 * @brief Gets the collision state of the environment.
 * @return `true` if the environment is colliding, `false` otherwise.
 */
bool Environment::GetCollision() const {
    return isColliding;
}

/**
 * @brief Sets the collision state of the environment.
 * @param collision The new collision state.
 */
void Environment::SetCollision(bool collision) {
    isColliding = collision;
}

/**
 * @brief Displays the collision state of the environment.
 */
void Environment::display() const {
    std::cout << "Environment: Collision = " << (isColliding ? "true" : "false") << std::endl;
}

/**
 * @brief Applies environmental effects to the player if a collision is detected.
 *
 * This is a non-virtual interface that ensures a unified interaction mechanism for
 * derived classes.
 * @param player The player instance to interact with.
 * @param delta The frame's delta time for time-based effects.
 */
bool Environment::interact(Player &player, float delta) const {
    if (isColliding) {
        apply_effects(player, delta);
    }
    return isColliding;
}

/**
 * @brief Binds methods for use in the Godot editor and scripting.
 */
void Environment::_bind_methods() {
    ClassDB::bind_method(D_METHOD("GetCollision"), &Environment::GetCollision);
    ClassDB::bind_method(D_METHOD("SetCollision", "collision"), &Environment::SetCollision);
}

/**
 * @brief Stream insertion operator for the Environment class.
 *
 * Outputs the collision state of the environment.
 * @param os The output stream.
 * @param environment The Environment instance to output.
 * @param player
 * @param delta
 * @return A reference to the updated output stream.
 */
std::ostream &operator<<(std::ostream &os, const Environment &environment, Player &player, float delta) {
    os << "Environment(Collision: " << (environment.interact(player, delta) ? "true" : "false") << ")";
    return os;
}
