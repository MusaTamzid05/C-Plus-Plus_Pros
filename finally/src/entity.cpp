#include "entity.h"

#include "includes.h"
#include <iostream>


namespace OpenGL {

    Entity::Entity(float* vertices , const std::string& vertex_filepath ,const std::string& fragment_filepath):
        shader(vertex_filepath , fragment_filepath) {

        this->vertices = vertices;


        init_attributes();
        init_buffer();
        bind();
        enable_attrib_pointer();
        unbind();

        std::cout << "Complete.\n";


    }

    Entity::~Entity() {

        glDeleteVertexArrays(1 , &VAO);
        glDeleteBuffers(1 , &VBO);
    }


    void Entity::bind() {

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER , VBO);
        glBufferData(GL_ARRAY_BUFFER , sizeof(vertices) , vertices , GL_STATIC_DRAW);


    }

    void Entity::enable_attrib_pointer() {

        glVertexAttribPointer( 0 , 3 , GL_FLOAT , GL_FALSE ,3 * sizeof(float) , (void*) 0);
        glEnableVertexAttribArray(0);
    }

    void Entity::draw() {

        shader.use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES , 0 , 3);
    }

    void Entity::init_buffer() {
        
        glGenBuffers(1 , &VBO);
    }

    void Entity::init_attributes() {

        glGenVertexArrays(1 , &VAO);
    }

    void Entity::unbind() {

        glBindBuffer(GL_ARRAY_BUFFER  , 0);
        glBindVertexArray(0);
    }
}
