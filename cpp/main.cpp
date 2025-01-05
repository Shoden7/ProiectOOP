#include <iostream>

#include <Helper.h>
#include <Player.h>
#include <Environment.h>
#include <Sand.h>
#include <NegativeSpeedException.h>
using namespace godot;

void _physics_process(float delta) {
    const Sand sand(0.5f, 0.8f); // Sand slows movement by 50% and jump by 20%

    // Simulate player entering sand
    try {
        Player player;
        // Apply the sand effects to the player (slow down movement and reduce jump)
        sand.apply_effects(player, delta); // Pass delta for consistency
    } catch (const godot::NegativeSpeedException &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}


int main() {
    Helper helper;
    helper.help();

    return 0;
}
