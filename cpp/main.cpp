#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <MenuManager.h>
#include <Player.h>
#include <Level1.h>
#include <SettingsScene.h>

using namespace godot;

/**
 * @class MainMenu
 * @brief Main menu with navigation options for the game.
 */
class MainMenu : public Node2D {
    GDCLASS(MainMenu, Node2D)

protected:
    /**
     * @brief Binds methods for use in the Godot editor and scripting.
     */
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("_ready"), &MainMenu::_ready);
    }

public:
    /**
     * @brief Sets up the main menu with buttons for navigation.
     */
    void _ready() override {
        // Prevent functionality from running in the editor
        if (Engine::get_singleton()->is_editor_hint()) {
            return;
        }

        auto *menu_manager = memnew(MenuManager);
        add_child(menu_manager);

        menu_manager->create_button("Start Game", []() {
            if (auto *tree = dynamic_cast<SceneTree *>(Engine::get_singleton()->get_main_loop())) {
                tree->change_scene_to_file("res://Level1.tscn");
            }
        });

        menu_manager->create_button("Settings", []() {
            if (auto *tree = dynamic_cast<SceneTree *>(Engine::get_singleton()->get_main_loop())) {
                tree->change_scene_to_file("res://SettingsScene.tscn");
            }
        });

        menu_manager->create_button("Quit Game", []() {
            if (auto *tree = dynamic_cast<SceneTree *>(Engine::get_singleton()->get_main_loop())) {
                tree->quit();
            }
        });
    }
};

/**
 * @brief Initializes classes during the module initialization process.
 * @param p_level The initialization level.
 */
void initialize_tiny_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }

    GDREGISTER_CLASS(MainMenu);
    GDREGISTER_CLASS(Player);
    GDREGISTER_CLASS(Level1);
    GDREGISTER_CLASS(SettingsScene);
}

/**
 * @brief Cleans up during the module uninitialization process.
 * @param p_level The initialization level.
 */
void uninitialize_tiny_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }
}

extern "C" {
/**
 * @brief Entry point for GDExtension initialization.
 * @param p_get_proc_address The GDExtension procedure address.
 * @param p_library The library pointer.
 * @param r_initialization The initialization object.
 * @return GDExtensionBool True if initialization is successful.
 */
GDExtensionBool GDE_EXPORT tiny_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address,
                                             const GDExtensionClassLibraryPtr p_library,
                                             GDExtensionInitialization *r_initialization) {
    godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

    init_obj.register_initializer(initialize_one_module);
    init_obj.register_terminator(uninitialize_one_module);
    init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

    return init_obj.init();
}
}
