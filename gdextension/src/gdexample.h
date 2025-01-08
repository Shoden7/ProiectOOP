#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {
    class ExampleClass : public Sprite2D {
        GDCLASS(ExampleClass, Sprite2D)

    private:
        double time_passed;

    protected:
        static void _bind_methods();

    public:
        ExampleClass();

        ~ExampleClass();

        void _process(double delta) override;
    };
}

#endif
