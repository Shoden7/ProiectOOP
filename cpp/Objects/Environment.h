#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <godot_cpp/core/class_db.hpp>
#include <Player.h>

using namespace godot;

/**
 * @class Environment
 * @brief Base class for environmental effects in the game.
 *
 * This abstract class provides a framework for creating different types of environmental
 * effects like Sand, Walls, and Ice. It supports dynamic polymorphism through pure virtual functions.
 */
class Environment : public Object {
 GDCLASS(Environment, Object)

private:
 /**
  * @brief Indicates whether the environment is currently colliding with the player.
  */
 bool isColliding;

public:
 /**
  * @brief Default constructor.
  *
  * Initializes the environment with no collision state.
  */
 Environment();

 /**
  * @brief Copy constructor.
  *
  * Creates a copy of an existing Environment instance.
  * @param other The Environment instance to copy.
  */
 Environment(const Environment &other);

 /**
  * @brief Virtual destructor for proper cleanup in derived classes.
  */
 ~Environment() override = default;

 /**
  * @brief Applies environmental effects to the player.
  *
  * Pure virtual function that must be overridden by derived classes to implement
  * specific effects like slowing down or modifying speed.
  * @param player The player instance to affect.
  * @param delta The frame's delta time for time-based effects.
  */
 virtual void apply_effects(Player &player, float delta) const = 0;

 /**
  * @brief Clones the environment.
  *
  * Virtual constructor for polymorphic duplication.
  * @return A pointer to a dynamically allocated copy of the environment.
  */
 virtual Environment *clone() const = 0;

 /**
  * @brief Displays information about the environment.
  *
  * Virtual function to output environment-specific details.
  */
 virtual void display() const;

 /**
  * @brief Interacts with the player if a collision is detected.
  *
  * Non-virtual interface that ensures unified access to the `apply_effects` function.
  * @param player The player instance to interact with.
  * @param delta The frame's delta time for time-based effects.
  */
 bool interact(Player &player, float delta) const;

 /**
  * @brief Gets the collision state of the environment.
  * @return `true` if the environment is colliding, `false` otherwise.
  */
 bool GetCollision() const;

 /**
  * @brief Sets the collision state of the environment.
  * @param collision The new collision state.
  */
 void SetCollision(bool collision);

 /**
  * @brief Binds methods for use in Godot scripts and the editor.
  */
 static void _bind_methods();
};

#endif // ENVIRONMENT_H
