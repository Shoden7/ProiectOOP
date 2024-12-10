#include "Player.h"

/**
 * @brief Default constructor for the Player class.
 *
 * Initializes the player's movement direction, speed, gravity, and jump status.
 */
Player::Player()
    : CharacterBody2D(),
      movementDirection(Vector2(0.0, 0.0)),
      movementSpeed(Vector2(100.0, 100.0)),
      gravityForce(9.8),
      canJump(false),
      velocity(Vector2(0.0, 0.0)) {
} // Initialize velocity

/**
 * @brief Called when the node is added to the scene tree.
 *
 * This method resets the player's movement direction and performs any necessary setup
 * when the Player node becomes active in the scene. It is called once the node enters the scene.
 */
void Player::_ready() {
    movementDirection = Vector2(0.0, 0.0); // Reset movement direction
    canJump = true; // Player is ready to jump once the scene starts
}

/**
 * @brief Called every physics frame to process player movement and physics.
 *
 * This method applies gravity, processes input for movement and jumping, and updates
 * the player's position using the Godot physics system.
 *
 * @param delta The time elapsed since the last physics frame.
 */
void Player::_physics_process(float delta) {
    // Apply gravity if the player is not on the floor
    if (!is_on_floor()) {
        velocity.y += gravityForce * delta; // Apply gravity over time
    } else {
        velocity.y = 0; // Stop vertical velocity when grounded

        // Handle jumping when the player is grounded and the jump button is pressed
        if (canJump && Input::get_singleton()->is_action_just_pressed("ui_up")) {
            velocity.y = -300.0f; // Current jump power
            canJump = false; // Prevent double jump
        }
    }

    // Horizontal movement input
    if (Input::get_singleton()->is_action_pressed("ui_right")) {
        velocity.x = movementSpeed.x; // Move right
    } else if (Input::get_singleton()->is_action_pressed("ui_left")) {
        velocity.x = -movementSpeed.x; // Move left
    } else {
        velocity.x = 0.0f; // No horizontal movement
    }

    // Set the velocity directly and move the player
    this->velocity = velocity; // Update the velocity property
    move_and_slide(); // No need to pass velocity, as it's already set
}

/**
 * @brief Stream insertion operator for the Player class.
 *
 * Outputs the Player's state (movement direction, speed, gravity, and jump ability)
 * to the given output stream.
 *
 * @param os The output stream.
 * @param player The Player instance to output.
 * @return A reference to the updated output stream.
 */
std::ostream &operator<<(std::ostream &os, const Player &player) {
    os << "Player("
            << "MovementDirection: (" << player.movementDirection.x << ", " << player.movementDirection.y << "), "
            << "MovementSpeed: (" << player.movementSpeed.x << ", " << player.movementSpeed.y << "), "
            << "GravityForce: " << player.gravityForce << ", "
            << "CanJump: " << (player.canJump ? "true" : "false") << ")";
    return os;
}

/**
 * @brief Binds methods to Godot for use in the editor or scripts.
 *
 * This static method is called to register custom methods with the Godot engine,
 * making them available to scripts and the Godot editor.
 */
void Player::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_ready"), &Player::_ready);
    ClassDB::bind_method(D_METHOD("_physics_process", "delta"), &Player::_physics_process);
}
