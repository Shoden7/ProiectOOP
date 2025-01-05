#include <../Objects/Environment.h>

// Default constructor
Environment::Environment() : isColliding(false) {
}

// Copy constructor
Environment::Environment(const Environment &other) : isColliding(other.isColliding) {
}

// Stream insertion operator
std::ostream &operator<<(std::ostream &os, const Environment &environment) {
    os << "Environment(Collision: " << (environment.isColliding ? "true" : "false") << ")";
    return os;
}

// GetCollision
bool Environment::GetCollision() const {
    return isColliding;
}

// SetCollision
void Environment::SetCollision(bool collision) {
    isColliding = collision;
}

// Bind methods to Godot
void Environment::_bind_methods() {
    ClassDB::bind_method(D_METHOD("GetCollision"), &Environment::GetCollision);
    ClassDB::bind_method(D_METHOD("SetCollision", "collision"), &Environment::SetCollision);
}
