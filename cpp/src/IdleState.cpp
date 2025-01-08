#include "IdleState.h"
#include <godot_cpp/classes/input.hpp>
#include "MovingState.h"
#include <godot_cpp/variant/utility_functions.hpp>

void IdleState::enter(Player *player_instance) {
    PlayerState::enter(player_instance);
    UtilityFunctions::print("Player entered Idle state.");
}

void IdleState::handle_input(const Ref<InputEvent> &event) {
    if (Input::get_singleton()->is_action_pressed("ui_right") ||
        Input::get_singleton()->is_action_pressed("ui_left")) {
        player->set_state(memnew(MovingState));
    }
}
