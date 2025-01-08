#ifndef ENVIRONMENTADAPTER_H
#define ENVIRONMENTADAPTER_H

#include <godot_cpp/classes/node2d.hpp>
#include <Player.h>

using namespace godot;

/**
 * @class EnvironmentAdapter
 * @brief Abstract interface for adapting different environment types to Node2D.
 */
class EnvironmentAdapter : public Node2D {
    GDCLASS(EnvironmentAdapter, Node2D)

public:
    /**
     * @brief Applies the environmental effects to the player.
     * @param player The player instance to apply the effects to.
     * @param delta The frame's delta time for time-based effects.
     */
    virtual void apply_effects(Player &player, float delta) = 0;

    /**
     * @brief Displays information about the environment.
     */
    virtual void display() const = 0;

    static void _bind_methods() {
    }
};

#endif // ENVIRONMENTADAPTER_H
