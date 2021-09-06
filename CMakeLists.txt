cmake_minimum_required(VERSION 3.20)
project(pipex C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES include/pipex.h
        srcs_man/main.c
        )

include_directories(libft)

add_executable(pipex ${SOURCE_FILES})

add_subdirectory(libft)

target_link_libraries(pipex libft)