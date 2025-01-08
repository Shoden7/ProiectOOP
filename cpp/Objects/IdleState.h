#ifndef IDLESTATE_H
#define IDLESTATE_H

#include "PlayerState.h"

/**
 * @class IdleState
 * @brief Represents the Idle state of the player.
 */
class IdleState : public PlayerState {
    GDCLASS(IdleState, PlayerState)

public:
    void enter(Player *player_instance) override;
    void handle_input(const Ref<InputEvent> &event) override;
};

#endif // IDLESTATE_H
