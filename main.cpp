#include <iostream>

#include <Helper.h>

#include "Objects/Player.h"
#include "Objects/Envroinment.h"

int main() {
    Player const player;

    /// Afiseaza direction
    std::cout << "Player direction: (";
    for (size_t i = 0; i < player.getDirection().size(); ++i) {
        std::cout << player.getDirection()[i];
        if (i < player.getDirection().size() - 1) std::cout << ", ";
    }
    std::cout << ")" << std::endl;

    /// Afiseaza speed
    std::cout << "Player speed: (";
    for (size_t i = 0; i < player.getSpeed().size(); ++i) {
        std::cout << player.getSpeed()[i];
        if (i < player.getSpeed().size() - 1) std::cout << ", ";
    }
    std::cout << ")" << std::endl;

    /// Afiseaza gravity
    std::cout << "Player gravity: " << player.getGravity() << std::endl;

    Helper helper;
    helper.help();

    return 0;
}
