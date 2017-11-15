#ifndef WINDOW_H
#define WINDOW_H


#include <string>
#include "includes.h"
#include "shader.h"

namespace Screen {

    class Window {

        public:

            Window(const std::string& title = "Window" , const int width = 800 , int height = 640);
            virtual ~Window();

            void init_shader(const std::string& vetex_shader_filename, const std::string& fragment_shader_filename);

            void run();

        protected:

            void init_glfw();
            void init_window();
            void load_opengl_functions();

        


            GLFWwindow* m_window;
            OpenGL::Shader* m_shader;

            static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
            static void processInput(GLFWwindow* window);


            void render();
            virtual void draw(){}


            void swap_buffers();

            int width;
            int height;
            std::string title;



    };
};

#endif
