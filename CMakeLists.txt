cmake_minimum_required(VERSION 3.20)
project(pipex C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES include/pipex_bonus.h
        srcs_bonus/main_bonus.c
        srcs_bonus/pipex_bonus.c
        srcs_bonus/utils_bonus.c
        )

include_directories(libft)

add_executable(pipex ${SOURCE_FILES})

add_subdirectory(libft)

target_link_libraries(pipex libft)