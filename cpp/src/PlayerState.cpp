/**
* @file PlayerState.cpp
 * @brief Implementation of the PlayerState base class.
 */

#include "PlayerState.h"

/**
 * @brief Default implementation for the `enter` method.
 *
 * Sets the player pointer for the current state.
 *
 * @param player_instance Pointer to the Player instance.
 */
void PlayerState::enter(Player *player_instance) {
 player = player_instance;
}

/**
 * @brief Default implementation for the `handle_input` method.
 *
 * Does nothing by default. Can be overridden by derived classes.
 *
 * @param event The input event to process.
 */
void PlayerState::handle_input(const Ref<InputEvent> &event) {
}

/**
 * @brief Default implementation for the `_process` method.
 *
 * Does nothing by default. Can be overridden by derived classes.
 *
 * @param delta Time elapsed since the last physics frame.
 */
void PlayerState::_process(float delta) {
}

/**
 * @brief Default implementation for the `exit` method.
 *
 * Does nothing by default. Can be overridden by derived classes.
 */
void PlayerState::exit() {
}
