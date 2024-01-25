cmake_minimum_required(VERSION 3.27)
project(calculator)

set(CMAKE_CXX_STANDARD 20)

add_executable(calculator src/main.cpp
        src/math/smath.cpp
        src/menu/Menu.cpp
        src/menu/Menu.h
        src/menu/Option.cpp
        src/menu/Option.h
        src/utils/colors.h
        src/evaluator/Evaluator.cpp
        src/evaluator/Evaluator.h)
