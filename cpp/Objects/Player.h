#ifndef PLAYER_H
#define PLAYER_H

// Include necessary Godot headers
#include <godot_cpp/classes/character_body2d.hpp> // For CharacterBody2D class
#include <godot_cpp/classes/input.hpp>           // For Input handling
#include <godot_cpp/variant/vector2.hpp>         // For Vector2 class
#include <godot_cpp/variant/string_name.hpp>     // For StringName class
#include <godot_cpp/core/class_db.hpp>           // For GDCLASS macro

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

 /**
  * @brief The velocity of the player used for movement and physics.
  *
  * This vector holds the player's velocity, used in calculations for movement and jumping.
  */
 Vector2 velocity;

public:
 /**
  * @brief Default constructor for the Player class.
  *
  * Initializes the player's movement direction, speed, gravity, and jump status.
  */
 Player();

 /**
  * @brief Copy constructor for the Player class.
  *
  * Creates a new Player instance by copying the data from another Player instance.
  *
  * @param other The Player instance to copy from.
  */
 Player(const Player &other);

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
 friend std::ostream &operator<<(std::ostream &os, const Player &player);

 /**
  * @brief Called when the node is added to the scene tree.
  *
  * This method resets the player's movement direction and performs any necessary setup
  * when the Player node becomes active in the scene.
  */
 void _ready();

 /**
  * @brief Called every physics frame to process player movement and physics.
  *
  * This method applies gravity, processes input for movement and jumping, and updates
  * the player's position using the Godot physics system.
  *
  * @param delta The time elapsed since the last physics frame.
  */
 void _physics_process(float delta);

 /**
  * @brief Binds methods to Godot for use in the editor or scripts.
  *
  * This static method is called to register custom methods with the Godot engine,
  * making them available to scripts and the Godot editor.
  */
 static void _bind_methods();
};

#endif // PLAYER_H
