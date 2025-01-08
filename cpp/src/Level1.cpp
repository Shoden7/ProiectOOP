#include "Level1.h"
#include "OutOfBoundsException.h"
#include "NegativeSpeedException.h"
#include "HighSpeedException.h"
#include <godot_cpp/variant/utility_functions.hpp>
#include <memory>


using namespace godot;

/**
 * @file Level1.cpp
 * @brief Implements the functionality for the Level1 gameplay scene, using adapters and exception handling.
 */

void Level1::_ready() {
    UtilityFunctions::print("Level1 is ready!");

    // Correctly initialize adapters with smart pointers
    sand_adapter = std::make_unique<SandAdapter>();
    ice_adapter = std::make_unique<IceAdapter>();
    walls_adapter = std::make_unique<WallsAdapter>();
}


/**
 * @brief Processes the physics for the level.
 *
 * Handles interactions with the environment, including sand, ice, and walls,
 * while also detecting and responding to exceptions.
 *
 * @param delta Time elapsed since the last physics frame.
 */
void Level1::_physics_process(float delta) const {
    try {
        // Check if the player's position is out of bounds
        if (player && player->get_position().y < -1000.0f) {
            throw OutOfBoundsException();
        }

        // Check for invalid speed scenarios
        if (player && player->get_velocity().x < 0.0f) {
            throw NegativeSpeedException("Speed must be greater than zero. ");
        }

        // Interact with sand
        if (sand_adapter->is_player_on_surface(player)) {
            sand_adapter->apply_surface_effect(player, delta);
        }

        // Interact with ice
        if (ice_adapter->is_player_on_surface(player)) {
            ice_adapter->apply_surface_effect(player, delta);
        }

        // Interact with walls
        if (walls_adapter->is_player_colliding(player)) {
            walls_adapter->handle_collision(player);
        }
    } catch (const OutOfBoundsException &e) {
        UtilityFunctions::print(e.what());
        player->set_position(Vector2(0, 0));
        UtilityFunctions::print("Player reset to starting position.");
    } catch (const NegativeSpeedException &e) {
        UtilityFunctions::print(e.what());
        player->set_velocity(Vector2(0, player->get_velocity().y));
        UtilityFunctions::print("Player speed corrected.");
    } catch (const HighSpeedException &e) {
        UtilityFunctions::print(e.what());
        player->set_velocity(Vector2(5000, 5000));
        UtilityFunctions::print("Player speed reset to safe values.");
    }
}

/**
 * @brief Binds methods for use in the Godot editor and scripting.
 */
void Level1::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_physics_process", "delta"), &Level1::_physics_process);
}
