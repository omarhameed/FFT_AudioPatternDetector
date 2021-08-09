cmake_minimum_required(VERSION 3.19)
project(Plagiarised_Music_app)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Plagiarised_Music_app
        data.cpp
        data.h
        edit.cpp
        edit.h
        header.h
        main.cpp
        Signture.cpp
        Signture.h)
