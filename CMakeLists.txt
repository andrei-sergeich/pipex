cmake_minimum_required(VERSION 3.20)
project(pipex C)

set(CMAKE_C_STANDARD 99)

set(SRC_MAN include/pipex.h
        srcs_man/main.c
        srcs_man/pipex.c
        srcs_man/utils.c
        )

set(SRC_BONUS include/pipex_bonus.h
        srcs_bonus/main_bonus.c
        srcs_bonus/pipex_bonus.c
        srcs_bonus/utils_bonus.c
        )

include_directories(libft)

add_subdirectory(libft)

add_executable(pipex ${SRC_MAN})

target_link_libraries(pipex libft)

add_executable(pipex_bonus ${SRC_BONUS})

target_link_libraries(pipex_bonus libft)