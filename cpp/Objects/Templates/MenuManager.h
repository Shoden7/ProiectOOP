#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <MenuButton.h>
#include <functional>
#include <vector>

using namespace godot;

/**
 * @class MenuManager
 * @brief Manages buttons for navigating between scenes.
 */
class MenuManager : public Node2D {
    GDCLASS(MenuManager, Node2D)

private:
    float button_spacing = 50.0f; ///< Spacing between buttons.
    std::vector<Node *> buttons; ///< Store buttons for layout management.

public:
    /**
     * @brief Creates a button and adds it to the menu.
     * @tparam Func The type of the function to execute.
     * @param label The button label.
     * @param action The action to execute.
     */
    template<typename Func>
    void create_button(const String &label, Func action) {
        auto *button = memnew(MenuButton<Func>(action));
        button->set_text(label);

        size_t button_count = buttons.size();
        button->set_position(Vector2(400.0f, 200.0f + static_cast<float>(button_count) * button_spacing));

        add_child(button);
        buttons.push_back(button);
    }

    /**
     * @brief Initializes the main menu with buttons.
     */
    void setup_main_menu() {
        create_button("Start Game", []() {
            if (auto *tree = dynamic_cast<SceneTree *>(Engine::get_singleton()->get_main_loop())) {
                tree->change_scene_to_file("res://Level1Scene.tscn");
            }
        });
        create_button("Settings", []() {
            if (auto *tree = dynamic_cast<SceneTree *>(Engine::get_singleton()->get_main_loop())) {
                tree->change_scene_to_file("res://SettingsScene.tscn");
            }
        });
        create_button("Quit Game", []() {
            if (auto *tree = dynamic_cast<SceneTree *>(Engine::get_singleton()->get_main_loop())) {
                tree->quit();
            }
        });
    }

    /**
     * @brief Binds methods for use in the Godot editor and scripting.
     */
    static void _bind_methods() {
        // Add any bindings if needed
    }
};

#endif // MENUMANAGER_H
