#include "opengl.h"


#include <iostream>


namespace OpenGL {

    void glfw_init() {

        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR  , 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR  , 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE , GLFW_OPENGL_CORE_PROFILE);

        std::cout << "glew has been initializer.\n";

    }


    GLFWwindow* init_window( int width , int height , const std::string& title) {

        GLFWwindow* window = glfwCreateWindow(width , height , title.c_str() , nullptr , nullptr);


        if(window == nullptr) {

            std::cerr << "Failed to create a GLFW window.\n";
            glfwTerminate();
            exit(1);
        }


        glfwMakeContextCurrent(window);

        std::cout << "Window is initialize.\n";

        return window;
    }

    void set_window_view_cordinates(int x , int y , int width , int height) {

        glViewport(x , y , width , height);
    }


    void framebuffer_size_callback(GLFWwindow* window , int width , int height) {

        glViewport( 0 , 0 , width , height );
    }


    void processInput(GLFWwindow* window) {

        if(glfwGetKey(window , GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window , true);

    }

    void load_opengl_functions() {

        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {

            std::cerr << "Failed to initialize GLAD.\n";
            exit(2);
        }

        std::cout << "All opengl function are loaded.\n";
    }


};
