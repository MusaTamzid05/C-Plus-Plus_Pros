#ifndef WINDOW_H
#define WINDOW_H


#include <string>


#include <SFML/Window.hpp>
#include "includes.h"



namespace OpenGL {

    class Window {

        public:

            Window(const std::string& window_name = "Game" , int width = 800 , int height = 640);

            virtual ~Window();

            void run();
            
        protected:

            bool init_glew();


            virtual void update();

            void clear_window();
            virtual void draw(){  /* this is the function to should be overide */ }
            virtual void render();

            virtual void handle_event();


            sf::Window* m_window;
            sf::Event m_event;

            bool m_running;


    };
};


#endif
