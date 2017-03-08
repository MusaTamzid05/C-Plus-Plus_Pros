#ifndef FILE_IO_H
#define FILE_IO_H

#include <string>

namespace IO{

    std::string read_file(const std::string& filename);
    void write_file(const std::string& filename , const std::string& text , bool append = false);

};

#endif
