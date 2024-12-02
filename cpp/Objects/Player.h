//
// Created by Stefan on 11/4/2024.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

class Player {
private:
    std::vector<float> direction;
    std::vector<float> speed;
    const float gravity;
    bool canJump, isColliding;

public:
    // Constructor
    explicit Player(const std::vector<float>& Direction = {0.0, 0.0},
                    const std::vector<float>& Speed = {100.0, 100.0},
                    const float Gravity = 9.8,
                    bool canJump = false,
                    bool isColliding = false)
        : direction(Direction), speed(Speed), gravity(Gravity), canJump(false), isColliding(false) {
    }

    // Getters
    [[nodiscard]] std::vector<float> getDirection() const {
        return direction;
    }

    [[nodiscard]] std::vector<float> getSpeed() const {
        return speed;
    }


    // Functions
    float gravityUpdate() const {
        return gravity;
    }

    void movement(float xInput, float yInput) {
        direction[0] += xInput;
        direction[1] += yInput;
    }
};

#endif // PLAYER_H