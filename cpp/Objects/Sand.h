#ifndef SAND_H
#define SAND_H

#include <Environment.h>
#include <Player.h>

namespace godot {
 /**
  * @class Sand
  * @brief Represents a sand environment that slows the player's movement and jump velocity.
  */
 class Sand : public Environment {
  GDCLASS(Sand, Environment)

 private:
  /**
   * @brief Factor by which the player's horizontal velocity is reduced.
   */
  float slowFactor;

  /**
   * @brief Factor by which the player's jump velocity is reduced.
   */
  float jumpFactor;

 public:
  /**
   * @brief Default constructor.
   *
   * Initializes the slow and jump factors to default values.
   */
  Sand();

  /**
   * @brief Parameterized constructor.
   *
   * Initializes the slow and jump factors with custom values.
   * @param slow The slow factor for horizontal movement.
   * @param jump The jump factor for vertical movement.
   */
  Sand(float slow, float jump);

  /**
   * @brief Applies sand effects to the player.
   *
   * Reduces the player's horizontal and jump velocities when interacting with sand.
   * @param player The player instance to affect.
   * @param delta The frame's delta time for time-based effects.
   */
  void apply_effects(Player &player, float delta) const override;

  /**
   * @brief Clones the sand environment.
   *
   * Creates a copy of the sand instance.
   * @return A pointer to a dynamically allocated copy of the sand instance.
   */
  Sand *clone() const override;

  /**
   * @brief Displays information about the sand environment.
   */
  void display() const override;

  /**
  * @brief Binds methods for use in Godot scripts and the editor.
  */
  static void _bind_methods();
 };
} // namespace godot

#endif // SAND_H
