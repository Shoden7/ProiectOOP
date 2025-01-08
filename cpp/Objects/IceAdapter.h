#ifndef ICEADAPTER_H
#define ICEADAPTER_H

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/node.hpp>

using namespace godot;

/**
 * @class IceAdapter
 * @brief Adapter for interacting with icy surfaces.
 */
class IceAdapter : public Node {
    GDCLASS(IceAdapter, Node)

private:
    Node2D *ice_surface = nullptr; ///< Pointer to the ice node.

public:
    /**
     * @brief Initializes the adapter with the specified node.
     * @param node The ice node to manage.
     */
    void initialize(Node *node) {
        ice_surface = Object::cast_to<Node2D>(node);
    }

    /**
     * @brief Checks if the player is on the icy surface.
     * @param player Pointer to the player.
     * @return True if the player is on the icy surface.
     */
    bool is_player_on_surface(Player *player);

    /**
     * @brief Applies the icy surface effect to the player.
     * @param player Pointer to the player.
     * @param delta Time elapsed since the last frame.
     */
    void apply_surface_effect(Player *player, float delta);
};

#endif // ICEADAPTER_H
