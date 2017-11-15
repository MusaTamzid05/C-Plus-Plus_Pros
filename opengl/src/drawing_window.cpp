#include "drawing_window.h"

#include "buffer.h"
#include <iostream>


namespace Play {

    Drawing_Window::Drawing_Window(const std::vector<float>& vertices):Window() ,
    vertices(vertices) {

        Buffer::init_buffer(VAO , VBO , vertices);

    }

    Drawing_Window::~Drawing_Window() {

        glDeleteVertexArrays(1 , &VAO);
        glDeleteBuffers(1 , &VBO);

    }

    void Drawing_Window::draw() {

        if(m_shader == nullptr) 
            std::cerr << "Shader not set !!\n";
        else
            m_shader->use();

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES , 0 , 3);

        
    }
}
