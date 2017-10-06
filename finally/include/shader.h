#ifndef SHADER_H
#define SHADER_H


#include <string>
#include "includes.h"

namespace OpenGL{


    class Shader {


        public:


            Shader(const std::string& vertex_file , const std::string& fragment_file);
            virtual ~Shader();

            void use();

        private:

            enum class Compile_Type {
                Shader ,
                Link
            };


            int program_id;

            bool compile_shader(GLuint shader_type , const std::string& shader_code , GLuint& shader_index);
            bool is_shader_compiled(int compile_result , GLuint index , const Compile_Type& type);
            
            bool link_shaders(GLuint vertex_shader_id , GLuint fragment_shader_id);



    };
};

#endif
