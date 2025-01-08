#ifndef PLAYER_H
#define PLAYER_H

#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/string_name.hpp>
#include <godot_cpp/core/class_db.hpp>
#include "PlayerState.h"

using namespace godot;

/**
 * @class Player
 * @brief Represents the player character in the game, inheriting from CharacterBody2D.
 *
 * This class handles player movement, state transitions, and interactions with the environment.
 */
class Player : public CharacterBody2D {
 GDCLASS(Player, CharacterBody2D)

private:
 bool InAir;
 Ref<PlayerState> current_state;
 Vector2 velocity;
 const float gravityForce = 900.0f;
 bool canJump = true;

public:
 /**
  * @brief Called when the node is added to the scene tree.
  */
 void _ready();

 /**
  * @brief Called every physics frame to process player movement and state logic.
  *
  * @param delta Time elapsed since the last physics frame.
  */
 void _physics_process(float delta);

 /**
  * @brief Sets the player's state to a new state.
  *
  * This method handles exiting the current state, transitioning to the new state,
  * and calling the appropriate state methods.
  *
  * @param new_state Pointer to the new state.
  */
 void set_state(PlayerState *new_state);

 /**
  * @brief Binds methods to Godot for use in the editor or scripts.
  */
 static void _bind_methods();

public:
 /**
  * @brief Gets the player's velocity.
  * @return The current velocity of the player.
  */
 Vector2 get_velocity() const override { return velocity; }

 /**
  * @brief Sets the player's velocity.
  * @param new_velocity The new velocity to assign.
  */
 void set_velocity(const Vector2 &new_velocity) override { velocity = new_velocity; }
};

#endif // PLAYER_H
