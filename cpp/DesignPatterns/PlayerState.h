#ifndef PLAYERSTATE_H
#define PLAYERSTATE_H

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include "Player.h"

using namespace godot;

/**
 * @class PlayerState
 * @brief Abstract base class for player states, following the State Design Pattern.
 *
 * This class provides a framework for implementing specific player states,
 * such as Idle, Moving, InAir, and Dying. Each derived state overrides the
 * virtual methods to define behavior specific to that state.
 */
class PlayerState : public RefCounted {
 GDCLASS(PlayerState, RefCounted)

protected:
 /**
  * @brief Pointer to the Player instance.
  *
  * This pointer allows each state to interact with the player and
  * control its behavior.
  */
 Player *player;

public:
 /**
  * @brief Called when the state is entered.
  *
  * This method is called when transitioning into this state. It sets
  * the `player` pointer to the current Player instance.
  *
  * @param player_instance Pointer to the Player instance.
  */
 virtual void enter(Player *player_instance);

 /**
  * @brief Handles input specific to the state.
  *
  * This method is called to process input events relevant to this state.
  * Derived classes can override this to implement custom input handling.
  *
  * @param event The input event to process.
  */
 virtual void handle_input(const Ref<InputEvent> &event);

 /**
  * @brief Called every frame to update the state.
  *
  * This method is called during the physics processing phase of the game loop.
  * Derived classes can override this to implement frame-specific behavior.
  *
  * @param delta The time elapsed since the last frame (in seconds).
  */
 virtual void _process(float delta);

 /**
  * @brief Called when the state is exited.
  *
  * This method is called when transitioning out of this state. Derived
  * classes can override this to clean up or reset specific state-related data.
  */
 virtual void exit();
};

#endif // PLAYERSTATE_H
