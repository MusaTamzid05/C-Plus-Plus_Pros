#include "window.h"

#include <GLFW/glfw3.h>



#include <iostream>


namespace OpenGL {


    Window::Window(const std::string& window_name , int width , int height ) {

        m_window = new sf::Window(sf::VideoMode(width , height) , window_name , sf::Style::Default); 
        m_window->setVerticalSyncEnabled(true);

        if(!init_glew()) {

            std::cerr << "glew initialization failed.\n";
            std::terminate();
        }

        std::cout << "glew initialize.\n";
        m_running = true;

    }

    Window::~Window() {

        if(m_window != nullptr)
            delete m_window;
    }


    bool Window::init_glew() {

        bool glew_initialize = false;

        
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


        GLenum success = glewInit();



        if(success == GLEW_OK) 
            glew_initialize = true;


        return glew_initialize;

    }

    void Window::run() {


        while(m_running) {

            handle_event();
            update();
            render();

            
        }


    }

    void Window::update() {


    }


    void Window::handle_event() {

        while(m_window->pollEvent(m_event)) {

            if(m_event.type == sf::Event::Closed)
                m_running = false;

            else if(m_event.type == sf::Event::Resized) {

                glViewport(0 , 0 , m_event.size.width , m_event.size.height);
            }
        }

    }


    void Window::clear_window() {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0 , 0.2 , .5 , 1.0);
    }

    void Window::render() {

        clear_window();
        draw();
        m_window->display();


    }
};
