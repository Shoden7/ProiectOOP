#ifndef INAIRSTATE_H
#define INAIRSTATE_H

#include "PlayerState.h"

/**
 * @class InAirState
 * @brief Represents the state of the player while in the air.
 *
 * This state is triggered when the player leaves the ground, such as during a jump
 * or fall. It handles mid-air behavior and transitions back to IdleState when grounded.
 */
class InAirState : public PlayerState {
    GDCLASS(InAirState, PlayerState)


public:
    /**
     * @brief Called when entering the InAirState.
     *
     * Sets the necessary conditions for the player to be in the air.
     *
     * @param player_instance Pointer to the Player instance.
     */
    void enter(Player *player_instance) override;

    /**
     * @brief Called every frame to update the InAirState.
     *
     * Handles gravity and checks for transitions back to the ground (IdleState)
     * or to DyingState if the player falls out of bounds.
     *
     * @param delta Time elapsed since the last physics frame.
     */
    void _process(float delta) override;
};

#endif // INAIRSTATE_H
