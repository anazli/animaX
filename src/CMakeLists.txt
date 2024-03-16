cmake_minimum_required(VERSION 3.22)
project(animation VERSION 0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(RUN_DIR ${CMAKE_BINARY_DIR}/bin)
set(EXE animaX)
set(CMAKE_DEBUG_POSTFIX d)

find_package(glad REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

set(SOURCES main.cpp
            application/application.cpp
            application/application.h
            window/window.cpp
            window/window.h
)
#if(UNIX)
#set(SOURCES ${SOURCES}
#    	    platform/linux_main.cpp
#    	    platform/linux_main.h
#)
#else()
#set(SOURCES ${SOURCES}
#    	    platform/win32_main.cpp
#    	    platform/win32_main.h
#)
#endif()

add_executable(${EXE} ${SOURCES})
target_include_directories(${EXE} PRIVATE ${PROJECT_SOURCE_DIR}
                                          ${glad_INCLUDE_DIRS}
                                          ${glfw_INCLUDE_DIRS}
)
set_target_properties(${EXE} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${RUN_DIR}
                                        DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
target_compile_options(${EXE} PRIVATE "-g")
target_link_options(${EXE} PRIVATE $<$<PLATFORM_ID:Windows>:/SUBSYSTEM:CONSOLE>)
endif()

target_link_libraries(${EXE} PRIVATE
                    $<$<PLATFORM_ID:Linux>:OpenGL::GL>
                    $<$<PLATFORM_ID:Windows>:opengl32.lib>
                    glad::glad
		    glfw
)
