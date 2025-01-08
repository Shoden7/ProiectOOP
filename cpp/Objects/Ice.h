#ifndef ICE_H
#define ICE_H

#include <Environment.h>
#include <Player.h>

/**
 * @class Ice
 * @brief Represents an icy environment that increases the player's speed.
 */
class Ice : public Environment {
 GDCLASS(Ice, Environment)

private:
 /**
  * @brief Factor by which the player's speed is multiplied.
  */
 float speedMultiplier;

public:
 /**
  * @brief Constructor for the Ice class.
  *
  * @param multiplier The speed multiplier for the ice effect.
  */
 Ice(float multiplier = 1.5f);

 /**
  * @brief Applies ice effects to the player.
  *
  * Increases the player's movement speed when interacting with ice.
  * @param player The player instance to affect.
  * @param delta The frame's delta time for time-based effects.
  */
 void apply_effects(Player &player, float delta) const override;

 /**
  * @brief Clones the ice environment.
  *
  * Creates a copy of the ice instance.
  * @return A pointer to a dynamically allocated copy of the ice instance.
  */
 Ice *clone() const override;

 /**
  * @brief Displays information about the ice environment.
  */
 void display() const override;

 /**
  * @brief Binds methods for use in Godot scripts and the editor.
  */
 static void _bind_methods();
};

#endif // ICE_H
