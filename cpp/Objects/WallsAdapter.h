#ifndef WALLSADAPTER_H
#define WALLSADAPTER_H

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/node.hpp>

using namespace godot;

/**
 * @class WallsAdapter
 * @brief Adapter for interacting with wall obstacles.
 */
class WallsAdapter : public Node {
    GDCLASS(WallsAdapter, Node)

private:
    Node2D *walls = nullptr; ///< Pointer to the walls node.

public:
    /**
     * @brief Initializes the adapter with the specified node.
     * @param node The walls node to manage.
     */
    void SandAdapter::initialize(Node *node) {
        walls = Object::cast_to<Node2D>(node);
    }

    /**
     * @brief Checks if the player is colliding with a wall.
     * @param player Pointer to the player.
     * @return True if the player is colliding with a wall.
     */
    bool is_player_colliding(Player *player);

    /**
     * @brief Handles collision with the player.
     * @param player Pointer to the player.
     */
    void handle_collision(Player *player);
};

#endif // WALLSADAPTER_H
