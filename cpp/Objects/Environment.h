#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
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
  */
 Environment();

 /**
  * @brief Copy constructor for the Environment class.
  *
  * @param other The Environment instance to copy from.
  */
 Environment(const Environment &other);

 /**
  * @brief Stream insertion operator for the Environment class.
  *
  * @param os The output stream.
  * @param environment The Environment instance to output.
  * @return A reference to the updated output stream.
  */
 friend std::ostream &operator<<(std::ostream &os, const Environment &environment);

 /**
  * @brief Gets the collision state of the environment.
  *
  * @return `true` if the environment is colliding, `false` otherwise.
  */
 bool GetCollision() const;

 /**
  * @brief Sets the collision state of the environment.
  *
  * @param collision The new collision state.
  */
 void SetCollision(bool collision);

 /**
  * @brief Binds methods to Godot for use in the editor or scripts.
  */
 static void _bind_methods();
};

#endif // ENVIRONMENT_H
