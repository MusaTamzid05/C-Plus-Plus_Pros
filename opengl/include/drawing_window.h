#ifndef DRAWING_WWINDOW_H
#define DRAWING_WWINDOW_H

#include "window.h"
#include <vector>


namespace Play {

    class Drawing_Window : public Screen::Window {

        public:

            Drawing_Window(const std::vector<float>& vertices);
            virtual ~Drawing_Window();


            virtual void draw();


        private:

            unsigned int VAO;
            unsigned int VBO;

            std::vector<float> vertices;

    };
};

#endif
