#include "shader.h"
#include "util.h"
#include <vector>
#include <iostream>


namespace OpenGL {

    
    Shader::Shader(const std::string& vertex_file , const std::string& fragment_file):program_id(-1) {

        std::string vertex_shader_code = Util::read(vertex_file);
        std::string  fragment_shader_code = Util::read(fragment_file);


        if(vertex_shader_code == "" || fragment_shader_code == "")
            exit(1);


        std::cout << "file loaded.\n";

        GLuint vertex_shader_id;
        GLuint fragment_shader_id;


        if(!compile_shader(GL_VERTEX_SHADER , vertex_shader_code , vertex_shader_id ))
            exit(2);

        if(!compile_shader(GL_FRAGMENT_SHADER , fragment_shader_code , fragment_shader_id ))
            exit(3);


        if(!link_shaders(vertex_shader_id , fragment_shader_id))
            exit(4);



    }

    Shader::~Shader() {

        if(program_id)
            glDeleteProgram(program_id);

    }


    bool Shader::compile_shader(GLuint shader_type , const std::string& shader_code , GLuint &shader_index){

        int compile_result = 0;


        shader_index = glCreateShader(shader_type);
        const char* shader_code_ptr = shader_code.c_str();
        const int shader_code_size = shader_code.size();


        glShaderSource(shader_index , 1 , &shader_code_ptr , &shader_code_size);

        glCompileShader(shader_index);
        glGetShaderiv(shader_index , GL_COMPILE_STATUS , &compile_result);

        bool shader_compiled =  is_shader_compiled(compile_result , shader_index , Compile_Type::Shader);
        std::string shader_name = shader_type == GL_VERTEX_SHADER ? "Vertex Shader" : "Fragment Shader";

        if(!shader_compiled) {

            std::cerr << "Could not compile " << shader_name << "\n";
            return false;
        }

        std::cout << shader_name << " is compiled.\n";
        return true;


    }


    bool Shader::is_shader_compiled(int compile_result , GLuint index, const Compile_Type& type) {

        if(compile_result != GL_FALSE) 
            return true;


        int info_log_length = 0;
        
        if(type == Compile_Type::Shader) {

            glGetShaderiv(index, GL_INFO_LOG_LENGTH , &info_log_length);
            std::vector<char> shader_log(info_log_length);
            glGetShaderInfoLog(index, info_log_length , nullptr , &shader_log[0]);

            std::cerr << "Shader Error : " <<  &shader_log[0] << "\n";

        }else {

            // Checking the prgram link Error
            //

            glGetProgramiv(index , GL_INFO_LOG_LENGTH , &info_log_length);
            std::vector<char> program_log(info_log_length);
            glGetProgramInfoLog(index , info_log_length , nullptr , &program_log[0]);

            std::cerr << "Program Error :" << &program_log[0] << "\n";
        }

        return false;


    }


    bool Shader::link_shaders(GLuint vertex_shader_id , GLuint fragment_shader_id) {


        int link_result;

        program_id = glCreateProgram();
        glAttachShader(program_id , vertex_shader_id);
        glAttachShader(program_id , fragment_shader_id);

        glLinkProgram(program_id);
        glGetProgramiv(program_id , GL_LINK_STATUS , &link_result);

        if(!is_shader_compiled(link_result , program_id , Compile_Type::Link)) {

            std::cerr << "Error Linking the shaders!!\n";
            return false;
        }

        std::cout << "Shader linking success.\n";

        return true;
    }

    void Shader::use() {

        glUseProgram(program_id);
    }

};
