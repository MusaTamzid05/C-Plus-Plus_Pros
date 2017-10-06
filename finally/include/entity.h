#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include "shader.h"

namespace OpenGL {

    class Entity {


        public:

            Entity(float* vertices , const std::string& vertex_filepath ,
                    const std::string& fragment_filepath);
            virtual ~Entity();

            virtual void draw();

        protected:

            float* vertices;
            unsigned int VBO;
            unsigned int VAO;

            void init_buffer();
            void init_attributes();
            void bind();
            void enable_attrib_pointer();
            void unbind();


            Shader shader;
    };


};
#endif
