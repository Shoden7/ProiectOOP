#ifndef DYINGSTATE_H
#define DYINGSTATE_H

#include "PlayerState.h"
#include "OutOfBoundsException.h"

/**
 * @class DyingState
 * @brief Represents the state of the player when falling out of bounds.
 *
 * This state handles scenarios where the player leaves the playable area,
 * such as falling below a certain threshold, and resets their position.
 */
class DyingState : public PlayerState {
    GDCLASS(DyingState, PlayerState)

public:
    /**
     * @brief Called when entering the DyingState.
     *
     * Handles the player's respawn logic and resets their state.
     *
     * @param player_instance Pointer to the Player instance.
     */
    void enter(Player *player_instance) override;
};

#endif // DYINGSTATE_H
