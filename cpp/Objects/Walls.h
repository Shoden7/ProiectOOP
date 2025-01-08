#ifndef WALLS_H
#define WALLS_H

#include <Environment.h>

/**
 * @class Walls
 * @brief Represents a set of walls in the environment.
 *
 * Walls block the player's movement and provide boundaries in the game world.
 */
class Walls : public Environment {
 GDCLASS(Walls, Environment)

private:
 /**
  * @brief Coordinates defining the position of the walls.
  */
 std::array<int, 4> coordinates;

public:
 /**
  * @brief Default constructor.
  *
  * Initializes the wall coordinates to default values.
  */
 Walls();

 /**
  * @brief Parameterized constructor.
  *
  * Initializes the wall coordinates with custom values.
  * @param coords The array of coordinates for the walls.
  */
 Walls(const std::array<int, 4> &coords);

 /**
  * @brief Applies wall effects to the player.
  *
  * Stops the player's movement upon collision.
  * @param player The player instance to affect.
  * @param delta The frame's delta time for time-based effects.
  */
 void apply_effects(Player &player, float delta) const override;

 /**
  * @brief Clones the walls environment.
  *
  * Creates a copy of the walls instance.
  * @return A pointer to a dynamically allocated copy of the walls instance.
  */
 Walls *clone() const override;

 /**
  * @brief Displays information about the walls.
  */
 void display() const override;

 /**
  * @brief Binds methods for use in Godot scripts and the editor.
  */
 static void _bind_methods();
};

#endif // WALLS_H
