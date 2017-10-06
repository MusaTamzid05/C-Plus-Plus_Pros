#ifndef NORMAL_WINDOW_H
#define NORMAL_WINDOW_H

#include "window.h"
#include <memory>
#include "entity.h"

namespace Play {

    class Normal_Window : public OpenGL::Window {

        public:

            Normal_Window();
            virtual ~Normal_Window() {}
            virtual void draw();

        private:

            std::unique_ptr<OpenGL::Entity> entity;

    };
};

#endif
