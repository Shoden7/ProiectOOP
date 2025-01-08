#include <Sand.h>
#include <Player.h>
#include <NegativeSpeedException.h>

namespace godot {
    /**
     * @brief Default constructor for the Sand class.
     *
     * Initializes the slow and jump factors to default values.
     */
    Sand::Sand() : slowFactor(0.5f), jumpFactor(0.7f) {
    }

    /**
     * @brief Parameterized constructor for the Sand class.
     *
     * Initializes the slow and jump factors with custom values.
     * Throws a NegativeSpeedException if any factor is non-positive.
     * @param slow_factor The slow factor for horizontal movement.
     * @param jump_factor The jump factor for vertical movement.
     */
    Sand::Sand(float slow_factor, float jump_factor)
        : slowFactor(slow_factor), jumpFactor(jump_factor) {
        if (slowFactor <= 0 || jumpFactor <= 0) {
            throw NegativeSpeedException("Slow factor and jump factor must be positive values.");
        }
    }

    /**
     * @brief Applies sand effects to the player.
     *
     * Slows horizontal movement and reduces jump velocity when interacting with sand.
     * @param player The player instance to affect.
     * @param delta The frame's delta time.
     */
    void Sand::apply_effects(Player &player, float delta) const {
        Vector2 velocity = player.get_velocity();
        velocity.x *= slowFactor;

        if (player.is_on_floor() && velocity.y < 0) {
            velocity.y *= jumpFactor;
        }

        player.set_velocity(velocity);
        player.move_and_slide();
    }

    /**
     * @brief Clones the sand environment.
     * @return A dynamically allocated copy of the Sand instance.
     */
    Sand *Sand::clone() const {
        return new Sand(*this);
    }

    /**
     * @brief Displays the slow and jump factors of the sand environment.
     */
    void Sand::display() const {
        std::cout << "Sand: Slow Factor = " << slowFactor << ", Jump Factor = " << jumpFactor << std::endl;
    }

    /**
     * @brief Binds methods for use in the Godot editor and scripting.
     */
    void Sand::_bind_methods() {
        ADD_SIGNAL(MethodInfo("error_occurred", PropertyInfo(Variant::STRING, "message")));
        ClassDB::bind_method(D_METHOD("apply_effects", "player:Player", "delta"), &Sand::apply_effects);
    }
} // namespace godot
