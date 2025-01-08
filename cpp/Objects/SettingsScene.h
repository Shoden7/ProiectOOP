#ifndef SETTINGSSCENE_H
#define SETTINGSSCENE_H

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <MenuManager.h>

using namespace godot;

/**
 * @class SettingsScene
 * @brief Scene for game settings with navigation to the main menu.
 */
class SettingsScene : public Node2D {
    GDCLASS(SettingsScene, Node2D)

protected:
    /**
     * @brief Binds methods for use in the Godot editor and scripting.
     */
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("_ready"), &SettingsScene::_ready);
    }

public:
    /**
     * @brief Initializes the settings scene with navigation buttons.
     */
    void _ready() override {
        auto *menu_manager = memnew(MenuManager);
        add_child(menu_manager);

        menu_manager->create_button("Main Menu", []() {
            if (auto *tree = dynamic_cast<SceneTree *>(Engine::get_singleton()->get_main_loop())) {
                tree->change_scene_to_file("res://MainMenu.tscn");
            }
        });

        menu_manager->create_button("Quit Game", []() {
            if (auto *tree = dynamic_cast<SceneTree *>(Engine::get_singleton()->get_main_loop())) {
                tree->quit();
            }
        });
    }
};

#endif // SETTINGSSCENE_H
