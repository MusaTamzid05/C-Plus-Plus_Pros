cmake_minimum_required(VERSION 2.8)

project(testas)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


file(GLOB SOURCES "src/*cpp")
add_executable(testas ${SOURCES})

# add the package here ..Example..
#find_package(OpenGL REQUIRED)
#find_package(GLUT REQUIRED)
#find_package(GLEW REQUIRED)

# add your include dir here
include_directories(include common_include )

# add the lib here ..Example

#target_link_libraries(testas ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} GL GLU GLEW glfw dl )


target_link_libraries(testas )
