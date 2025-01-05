#include <Sand.h>
#include <Player.h>
#include <NegativeSpeedException.h>

namespace godot {
    // Sand Default Constructor
    Sand::Sand() : slowFactor(0.5f), jumpFactor(0.7f) {
    }

    // Sand Parameterized Constructor
    Sand::Sand(float slow_factor, float jump_factor)
        : slowFactor(slow_factor), jumpFactor(jump_factor) {
        if (slowFactor <= 0 || jumpFactor <= 0) {
            throw NegativeSpeedException("Slow factor and jump factor must be positive values.");
        }
    }

    // Apply effects to the Player (without using getter/setter)
    void Sand::apply_effects(Player &player, float delta) const {
        try {
            Vector2 velocity = player.get_velocity(); // Directly access velocity from Player

            // Slow horizontal movement
            velocity.x *= slowFactor;

            // Reduce jump velocity
            if (player.is_on_floor() && velocity.y < 0) {
                // Only reduce upward (jump) velocity
                velocity.y *= jumpFactor;
            }

            // Check for invalid velocities
            if (velocity.x < 0 || velocity.y < 0) {
                throw NegativeSpeedException("Player's velocity cannot be negative in sand.");
            }

            // Update the player velocity by calling move_and_slide() with modified velocity
            player.move_and_slide(); // Apply new velocity directly to the movement
        } catch (const NegativeSpeedException &e) {
            // Log the exception
            std::cerr << "Sand Error: " << e.what() << std::endl;

            // Rethrow the exception for higher-level handling if necessary
            throw;
        }
    }

    // Bind methods to Godot
    void Sand::_bind_methods() {
        ClassDB::bind_method(D_METHOD("apply_effects", "player", "delta"), &Sand::apply_effects);
    }
} // namespace godot
