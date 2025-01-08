#include <Ice.h>

/**
 * @brief Constructor for the Ice class.
 *
 * Initializes the speed multiplier for the ice.
 * @param multiplier The speed multiplier for the ice effect.
 */
Ice::Ice(float multiplier) : speedMultiplier(multiplier) {
}

/**
 * @brief Applies ice effects to the player.
 *
 * Increases the player's speed when interacting with ice.
 * @param player The player instance to affect.
 * @param delta The frame's delta time.
 */
void Ice::apply_effects(Player &player, float delta) const {
    Vector2 velocity = player.get_velocity();
    velocity *= speedMultiplier;
    player.set_velocity(velocity);
}

/**
 * @brief Clones the ice environment.
 * @return A dynamically allocated copy of the Ice instance.
 */
Ice *Ice::clone() const {
    return new Ice(*this);
}

/**
 * @brief Displays the speed multiplier of the ice environment.
 */
void Ice::display() const {
    std::cout << "Ice: Speed Multiplier = " << speedMultiplier << std::endl;
}

/**
 * @brief Binds methods for use in the Godot editor and scripting.
 */
void Ice::_bind_methods() {
    ClassDB::bind_method(D_METHOD("apply_effects", "player:Player", "delta"), &Ice::apply_effects);
}
