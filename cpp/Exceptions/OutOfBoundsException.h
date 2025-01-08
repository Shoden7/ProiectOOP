#ifndef OUTOFBOUNDSEXCEPTION_H
#define OUTOFBOUNDSEXCEPTION_H

#include <exception>

/**
 * @class OutOfBoundsException
 * @brief Exception thrown when the player falls out of bounds.
 */
class OutOfBoundsException : public std::exception {
public:
    /**
     * @brief Returns the exception message.
     * @return A C-string describing the exception.
     */
    const char *what() const noexcept override {
        return "Player fell out of bounds!";
    }
};

#endif // OUTOFBOUNDSEXCEPTION_H
