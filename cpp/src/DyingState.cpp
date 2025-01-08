/**
* @file DyingState.cpp
 * @brief Implements the DyingState class, handling the player's behavior when falling out of bounds.
 */

#include "DyingState.h"
#include "IdleState.h"
#include <godot_cpp/variant/utility_functions.hpp>

/**
 * @brief Called when entering the Dying state.
 *
 * Handles the player's respawn logic, resetting their position and state.
 * Uses the OutOfBoundsException to confirm that the player is out of bounds.
 *
 * @param player_instance Pointer to the Player instance.
 */
void DyingState::enter(Player *player_instance) {
    PlayerState::enter(player_instance);
    UtilityFunctions::print("Player entered Dying state.");

    try {
        // Check if the player is truly out of bounds
        if (player->get_position().y < -1000.0f) {
            throw OutOfBoundsException();
        }
    } catch (const OutOfBoundsException &e) {
        UtilityFunctions::print(e.what());
        player->set_position(Vector2(0, 0)); // Respawn position
        player->set_state(memnew(IdleState)); // Transition back to IdleState
        player->move_and_slide(); // Reset player's movement
    }
}
