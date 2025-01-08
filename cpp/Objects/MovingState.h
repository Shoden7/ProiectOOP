#ifndef MOVINGSTATE_H
#define MOVINGSTATE_H

#include "PlayerState.h"

/**
 * @class MovingState
 * @brief Represents the Moving state of the player.
 */
class MovingState : public PlayerState {
    GDCLASS(MovingState, PlayerState)

public:
    void enter(Player *player_instance) override;

    void _process(float delta) override;
};

#endif // MOVINGSTATE_H
