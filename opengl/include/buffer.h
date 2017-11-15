#ifndef BUFFER_H
#define BUFFER_H


#include "includes.h"
#include <vector>


namespace Buffer {
    void init_buffer(unsigned int& VAO , unsigned int& VBO , const std::vector<float>& vectices);
};


#endif
