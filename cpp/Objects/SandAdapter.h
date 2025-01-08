#ifndef SANDADAPTER_H
#define SANDADAPTER_H

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/node.hpp>

using namespace godot;

/**
 * @class SandAdapter
 * @brief Adapter for interacting with sand surfaces.
 */
class SandAdapter : public Node {
    GDCLASS(SandAdapter, Node)

private:
    Node2D *sand_surface = nullptr; ///< Pointer to the sand node.

public:
    /**
     * @brief Initializes the adapter with the specified node.
     * @param node The sand node to manage.
     */
    void initialize(Node *node) {
        sand_surface = Object::cast_to<Node2D>(node);
    }

    /**
     * @brief Checks if the player is on the sand surface.
     * @param player Pointer to the player.
     * @return True if the player is on the sand surface.
     */
    bool is_player_on_surface(Player *player);

    /**
     * @brief Applies the sand surface effect to the player.
     * @param player Pointer to the player.
     * @param delta Time elapsed since the last frame.
     */
    void apply_surface_effect(Player *player, float delta);
};

#endif // SANDADAPTER_H
