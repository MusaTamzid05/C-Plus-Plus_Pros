#include "window.h"
#include <iostream>


namespace  Screen {

    Window::Window(const std::string& title , const int width , int height ):width(width) , height(height) , title(title) , m_shader(nullptr) , m_window(nullptr) {

        init_glfw();
        init_window();
        load_opengl_functions();

    }

    Window::~Window() {

        if(m_window != nullptr)
            glfwTerminate();


        if(m_shader != nullptr)
            delete m_shader;

    }

    void Window::init_glfw() {


        if(!glfwInit()) {

            std::cerr << "Could not create glfw window.\n";
            exit(0);
        }


        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        std::cout << "glfw initialize.\n";
    }

    void Window::init_window() {

        std::cout << "Trying to  init window.\n";
        m_window = glfwCreateWindow(width , height , title.c_str() ,nullptr , nullptr);


        if(m_window == nullptr) {

            std::cerr << "Failed to create glfw window.\n";
            exit(1);
        }

        std::cout << "Window is already created.\n";


        glfwMakeContextCurrent(m_window);
        glfwSetFramebufferSizeCallback(m_window , framebuffer_size_callback);
        std::cout << "Context made current.\n";

    }
    
    void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height){


        // make sure the viewport matches the new window dimensions; note that width and 
        // height will be significantly larger than specified on retina displays.
        glViewport(0, 0, width, height);
    }

    void Window::load_opengl_functions() {


        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){

            std::cout << "Failed to initialize GLAD" << std::endl;
            exit(2);
        }

    }
    
    void Window::init_shader(const std::string& vertex_shader_filename, const std::string& fragment_shader_filename) {

        m_shader = new OpenGL::Shader(vertex_shader_filename , fragment_shader_filename);
    }

    void Window::processInput(GLFWwindow* window) {

        if(glfwGetKey(window , GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window , true);
    }

    void Window::run() {

        while(!glfwWindowShouldClose(m_window)) {
            
            processInput(m_window);

            render();
            draw();
            swap_buffers();
            glfwPollEvents();

        }
    }

    void Window::render() {

        glClearColor(0.2f , 0.3f , 0.3f , 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Window::swap_buffers() {

        glfwSwapBuffers(m_window);
    }

};
