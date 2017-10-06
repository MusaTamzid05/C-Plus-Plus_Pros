#include "normal_window.h"

#include <iostream>

namespace Play {

    Normal_Window::Normal_Window():OpenGL::Window() {

        float  vertices[] = { -1.0 , 0.0 , 0.0 ,
                             0.0 , 1.0 , 0.0 , 
                             1.0 , 0.0 , 0.0
        };

        entity = std::make_unique<OpenGL::Entity>(vertices , "./shaders/vertex_shader.vs" , "./shaders/fragment_shader.fs");

    }

    void Normal_Window::draw() {

        entity->draw();
    }
};
