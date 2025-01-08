/**
* @file InAirState.cpp
 * @brief Implements the InAirState class, handling the player's behavior while in the air.
 */

#include "InAirState.h"
#include "IdleState.h"
#include "DyingState.h"
#include <godot_cpp/variant/utility_functions.hpp>

/**
 * @brief Called when entering the InAir state.
 *
 * Logs the transition to the InAir state and initializes relevant conditions.
 *
 * @param player_instance Pointer to the Player instance.
 */
void InAirState::enter(Player *player_instance) {
    PlayerState::enter(player_instance);
    UtilityFunctions::print("Player entered InAir state.");
}

/**
 * @brief Processes the InAir state.
 *
 * Applies gravity to the player, checks for landing on the ground (transition to IdleState),
 * and handles falling out of bounds (transition to DyingState).
 *
 * @param delta Time elapsed since the last physics frame.
 */
void InAirState::_process(float delta) {
    // Update player's velocity with gravity
    Vector2 current_velocity = player->get_velocity();
    player->_physics_process(delta);
    player->set_velocity(current_velocity);

    // Check if the player is grounded
    if (player->is_on_floor()) {
        player->set_state(memnew(IdleState));
        return;
    }

    // Check if the player is falling out of bounds
    if (player->get_position().y < -1000.0f) {
        player->set_state(memnew(DyingState));
    }
}
