#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <godot_cpp/classes/button.hpp>
#include <functional>

using namespace godot;

/**
 * @class MenuButton
 * @brief Template-based button for handling actions.
 *
 * A reusable button class that executes a function when pressed.
 *
 * @tparam Func The type of the action to perform.
 */
template<typename Func>
class MenuButton : public Button {
    GDCLASS(MenuButton, Button)

private:
    Func action; ///< The action to perform when the button is pressed.

public:
    /**
     * @brief Constructor for MenuButton.
     * @param action The action to perform.
     */
    explicit MenuButton(Func action) : action(action) {
    }

    /**
     * @brief Called when the button is pressed.
     */
    void _on_button_pressed() {
        action(); // Execute the action
    }

    /**
     * @brief Binds methods for use in the Godot editor and scripting.
     */
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("_on_button_pressed"), &MenuButton::_on_button_pressed);
    }
};

#endif // MENUBUTTON_H
