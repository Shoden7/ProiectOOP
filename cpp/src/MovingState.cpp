#include "MovingState.h"

#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include "IdleState.h"

void MovingState::enter(Player *player_instance) {
    PlayerState::enter(player_instance);
    UtilityFunctions::print("Player entered Moving state.");
}

void MovingState::_process(float delta) {
    player->velocity.x += 1.0f * delta; // Example movement logic
    if (!Input::get_singleton()->is_action_pressed("ui_right") &&
        !Input::get_singleton()->is_action_pressed("ui_left")) {
        player->set_state(memnew(IdleState));
    }
}
