//
// Created by Stefan on 05/01/2025.
//

#ifndef NEGATIVESPEEDEXCEPTION_H
#define NEGATIVESPEEDEXCEPTION_H

#include <godot_cpp/variant/string.hpp>

using namespace godot;

/**
 * @class NegativeSpeedException
 * @brief Exception thrown when an invalid (negative) speed is applied to the player.
 *
 * This exception is used to handle situations where the player's speed
 * becomes negative due to invalid operations, ensuring that such cases
 * are handled gracefully in the game logic.
 */
class NegativeSpeedException : public std::exception {
private:
    /**
     * @brief Message describing the cause of the exception.
     */
    godot::String message;

public:
    /**
     * @brief Constructs a NegativeSpeedException with a given error message.
     *
     * @param msg The error message describing the cause of the exception.
     */
    explicit NegativeSpeedException(String msg) : message(std::move(msg)) {
    }

    /**
     * @brief Retrieves the error message associated with the exception.
     *
     * This method overrides the `what()` method of the `std::exception` class
     * and returns the error message as a C-style string.
     *
     * @return A pointer to a C-style string containing the error message.
     */
    const char *what() const noexcept override {
        return message.utf8().get_data();
    }
};

#endif // NEGATIVESPEEDEXCEPTION_H
