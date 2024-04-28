cmake_minimum_required(VERSION 3.26)
project(LibraryManagement C)

set(CMAKE_C_STANDARD 11)

add_executable(LibraryManagement main.c
        reader.h
        reader.c
        library.c
        library.h
        book.c
        book.h
        borrow_return.c
        borrow_return.h
        statistics.c
        statistics.h)
