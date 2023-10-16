cmake_minimum_required(VERSION 3.22)
project(animation VERSION 0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(RUN_DIR ${CMAKE_BINARY_DIR}/bin)
set(EXE Animation)
set(CMAKE_DEBUG_POSTFIX d)

find_package(glad REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLFW3 REQUIRED)

set(SOURCES main.cpp
            application.h)

add_executable(${EXE} ${SOURCES})
target_include_directories(${EXE} PRIVATE ${PROJECT_SOURCE_DIR})
set_target_properties(${EXE} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${RUN_DIR}
                                        DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
target_compile_options(${EXE} PRIVATE "-g")
endif()

target_link_libraries(${EXE} PRIVATE
                    OpenGL::GL
                    glad::glad
                    glfw
)
