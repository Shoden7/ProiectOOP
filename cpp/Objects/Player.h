#ifndef PLAYER_H
#define PLAYER_H

// Include necessary Godot headers
#include "../../godot/godot-cpp/gen/include/godot_cpp/classes/character_body2d.hpp" // For CharacterBody2D class
#include "../../godot/godot-cpp/gen/include/godot_cpp/classes/input.hpp"           // For Input handling
#include "../../godot/godot-cpp/include/godot_cpp/variant/vector2.hpp"            // For Vector2 class
#include "../../godot/godot-cpp/gen/include/godot_cpp/variant/string_name.hpp"    // For StringName class
#include "../../godot/godot-cpp/include/godot_cpp/core/class_db.hpp"              // For GDCLASS macro
#include <iostream> // For the stream insertion operator

using namespace godot;

/**
 * @class Player
 * @brief Represents the player character in the game, inheriting from CharacterBody2D.
 *
 * This class handles player movement, input processing, and physics behavior
 * such as gravity, jumping, and collision detection using Godot's physics system.
 */
class Player : public CharacterBody2D {
 GDCLASS(Player, CharacterBody2D)

private:
 /**
  * @brief The current movement direction of the player.
  *
  * A 2D vector representing the player's movement in the X and Y axes.
  */
 Vector2 movementDirection;

 /**
  * @brief The player's movement speed.
  *
  * A 2D vector representing the player's speed in the X and Y directions.
  */
 Vector2 movementSpeed;

 /**
  * @brief The gravitational force acting on the player.
  *
  * This constant determines how strongly gravity affects the player's vertical movement.
  */
 const float gravityForce;

 /**
  * @brief Indicates whether the player can jump.
  *
  * This flag is true when the player is grounded and false otherwise.
  */
 bool canJump;

public:
 /**
  * @brief Default constructor for the Player class.
  *
  * Initializes the player's movement direction, speed, gravity, and jump status.
  */
 Player()
  : movementDirection(Vector2(0.0, 0.0)), // Start with no movement
    movementSpeed(Vector2(100.0, 100.0)), // Set base movement speed
    gravityForce(9.8), // Set gravity constant
    canJump(false) // Player starts not being able to jump
 {
 }

 /**
  * @brief Copy constructor for the Player class.
  *
  * Creates a new Player instance by copying the data from another Player instance.
  *
  * @param other The Player instance to copy from.
  */
 Player(const Player &other)
  : movementDirection(other.movementDirection),
    movementSpeed(other.movementSpeed),
    gravityForce(other.gravityForce),
    canJump(other.canJump) {
 }

 /**
  * @brief Assignment operator for the Player class.
  *
  * Assigns the data of one Player instance to another.
  *
  * @param other The Player instance to copy data from.
  * @return A reference to the updated Player instance.
  */
 Player &operator=(const Player &other) {
  if (this != &other) {
   // Avoid self-assignment
   movementDirection = other.movementDirection;
   movementSpeed = other.movementSpeed;
   // gravityForce is const, so no need to reassign
   canJump = other.canJump;
  }
  return *this;
 }

 /**
  * @brief Stream insertion operator for the Player class.
  *
  * Outputs the Player's state (movement direction, speed, gravity, and jump ability)
  * to the given output stream.
  *
  * @param os The output stream.
  * @param player The Player instance to output.
  * @return A reference to the updated output stream.
  */
 friend std::ostream &operator<<(std::ostream &os, const Player &player) {
  os << "Player("
    << "MovementDirection: " << player.movementDirection << ", "
    << "MovementSpeed: " << player.movementSpeed << ", "
    << "GravityForce: " << player.gravityForce << ", "
    << "CanJump: " << (player.canJump ? "true" : "false") << ")";
  return os;
 }

 /**
  * @brief Called when the node is added to the scene tree.
  *
  * This method resets the player's movement direction and performs any necessary setup
  * when the Player node becomes active in the scene.
  */
 void Ready();

 /**
  * @brief Called every physics frame to process player movement and physics.
  *
  * @param delta The time elapsed since the last physics frame.
  *
  * This method applies gravity, processes input for movement and jumping, and updates
  * the player's position using the Godot physics system.
  */
 void PhysicsProcess(float delta);

 /**
  * @brief Binds methods to Godot for use in the editor or scripts.
  *
  * This static method is called to register custom methods with the Godot engine.
  * Currently, no additional methods are bound.
  */
 static void BindMethods();
};

#endif // PLAYER_H
