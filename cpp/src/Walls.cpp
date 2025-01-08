#include <Walls.h>

/**
 * @brief Default constructor for the Walls class.
 *
 * Initializes the wall coordinates to default values.
 */
Walls::Walls() : coordinates({0, 0, 0, 0}) {
}

/**
 * @brief Parameterized constructor for the Walls class.
 *
 * Initializes the wall coordinates with custom values.
 * @param coords The array of coordinates for the walls.
 */
Walls::Walls(const std::array<int, 4> &coords) : coordinates(coords) {
}

/**
 * @brief Applies wall effects to the player.
 *
 * Stops the player's movement upon collision.
 * @param player The player instance to affect.
 * @param delta The frame's delta time.
 */
void Walls::apply_effects(Player &player, float delta) const {
    std::cout << "Player collided with a wall. Stopping movement." << std::endl;
    player.set_velocity(Vector2(0, 0));
}

/**
 * @brief Clones the walls environment.
 * @return A dynamically allocated copy of the Walls instance.
 */
Walls *Walls::clone() const {
    return new Walls(*this);
}

/**
 * @brief Displays the coordinates of the walls.
 */
void Walls::display() const {
    std::cout << "Walls: Coordinates = [";
    for (int coord: coordinates) {
        std::cout << coord << " ";
    }
    std::cout << "]" << std::endl;
}

/**
 * @brief Binds methods for use in the Godot editor and scripting.
 */
void Walls::_bind_methods() {
    ClassDB::bind_method(D_METHOD("apply_effects", "player:Player", "delta"), &Walls::apply_effects);
}
