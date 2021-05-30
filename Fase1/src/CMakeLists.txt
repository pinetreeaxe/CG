
cmake_minimum_required(VERSION 3.9)

PROJECT(engine)

add_executable(${PROJECT_NAME} engine.cpp point.cpp vector.cpp tinyxml2.cpp models.cpp sphericalpoint.cpp transformation.cpp lights.cpp)
add_executable(generator generator.cpp point.cpp plane.cpp box.cpp vector.cpp sphere.cpp sphericalpoint.cpp cone.cpp torus.cpp patches.cpp normalTexPoint.cpp)

find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})

find_package(DevIL REQUIRED)
include_directories(${IL_INCLUDE_DIR})
link_libraries(${IL_LIBRARIES})

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARIES} ${IL_LIBRARIES})