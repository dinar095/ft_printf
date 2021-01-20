cmake_minimum_required(VERSION 3.17)
project(desausag C)

set(CMAKE_C_STANDARD 99)
add_library(lib STATIC libft/ft_strchr.c)

add_executable(desausag ft_printf.c ft_printf.h libfiles.c libft/libft.h libft/ft_strchr.c libft/ft_atoi.c libft/ft_calloc.c libft/ft_bzero.c)

