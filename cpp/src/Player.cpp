/**
 * @file Player.cpp
 * @brief Implementation of the Player class, including movement, state management, and physics processing.
 */

#include "Player.h"
#include "IdleState.h"
#include "MovingState.h"
#include "InAirState.h"
#include "DyingState.h"
#include "HighSpeedException.h"
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

/**
 * @brief Called when the Player node is added to the scene tree.
 *
 * Initializes the player and sets the initial state to IdleState.
 */
void Player::_ready() {
    UtilityFunctions::print("Player is ready!");
    set_state(memnew(IdleState)); // Set the initial state to IdleState
}

/**
 * @brief Called every physics frame to process player movement and state logic.
 *
 * Handles input, applies gravity, and delegates processing to the current state.
 *
 * @param delta Time elapsed since the last physics frame.
 */
void Player::_physics_process(float delta) {
    velocity.y += gravityForce * delta;


    if (current_state.is_valid()) {
        current_state->_process(delta);
    }
    if (velocity.length() > 6000.0f) {
        throw HighSpeedException();
    }
    // Check if the player is on the floor
    if (is_on_floor()) {
        canJump = true;
    }
}

/**
 * @brief Sets the player's state to a new state.
 *
 * Exits the current state (if any), transitions to the new state, and calls its `enter` method.
 * Uses dynamic_cast to log the new state type.
 *
 * @param new_state Pointer to the new state.
 */
void Player::set_state(PlayerState *new_state) {
    if (current_state.is_valid()) {
        current_state->exit();
    }

    // Log state transition
    if (dynamic_cast<IdleState *>(new_state)) {
        UtilityFunctions::print("Transitioning to IdleState.");
    } else if (dynamic_cast<MovingState *>(new_state)) {
        UtilityFunctions::print("Transitioning to MovingState.");
    } else if (dynamic_cast<InAirState *>(new_state)) {
        UtilityFunctions::print("Transitioning to InAirState.");
    } else if (dynamic_cast<DyingState *>(new_state)) {
        UtilityFunctions::print("Transitioning to DyingState.");
    }

    // Assign and enter the new state
    current_state = Ref<PlayerState>(new_state);
    current_state->enter(this);
}

/**
 * @brief Binds methods to Godot for use in the editor or scripts.
 *
 * Registers the _physics_process method with the Godot engine.
 */
void Player::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_physics_process", "delta"), &Player::_physics_process);
}
