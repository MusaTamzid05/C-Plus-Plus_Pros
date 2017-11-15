#ifndef OPENGL_H
#define OPENGL_H

#include <string>
#include "includes.h"

namespace OpenGL {

    void glfw_init();
    GLFWwindow* init_window(int width = 800 , int height = 640 , const std::string& title = "Learning  OpenGL");

    void load_opengl_functions();


    // all the callbacks ..
    void framebuffer_size_callback(GLFWwindow* window , int width , int height);
    void processInput(GLFWwindow* window);



};

#endif
