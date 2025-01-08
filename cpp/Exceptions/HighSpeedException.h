#ifndef HIGHSPEEDEXCEPTION_H
#define HIGHSPEEDEXCEPTION_H

#include <exception>

/**
 * @class HighSpeedException
 * @brief Exception thrown when the player's speed exceeds the maximum allowed limit.
 */
class HighSpeedException : public std::exception {
public:
    /**
     * @brief Returns the exception message.
     * @return A C-string describing the exception.
     */
    [[nodiscard]] const char *what() const noexcept override {
        return "Player's speed exceeds the maximum limit!";
    }
};

#endif // HIGHSPEEDEXCEPTION_H
