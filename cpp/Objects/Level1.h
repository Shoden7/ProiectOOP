#ifndef LEVEL1_H
#define LEVEL1_H

#include <godot_cpp/classes/node2d.hpp>
#include "Player.h"
#include "SandAdapter.h"
#include "IceAdapter.h"
#include "WallsAdapter.h"
#include <memory>

using namespace godot;

/**
 * @class Level1
 * @brief Represents the first level of the game, handling gameplay logic and interactions.
 */
class Level1 : public Node2D {
    GDCLASS(Level1, Node2D)

private:
    Player *player;
    std::unique_ptr<SandAdapter> sand_adapter;
    std::unique_ptr<IceAdapter> ice_adapter;
    std::unique_ptr<WallsAdapter> walls_adapter;

public:
    void _ready() override;

    void _physics_process(float delta) const;

    static void _bind_methods();
};

#endif // LEVEL1_H
