cmake_minimum_required(VERSION 3.12)
project(Homework_26_9_1)

add_executable(HW_26_9_1 main.cpp)

set_target_properties(HW_26_9_1 
        PROPERTIES
            CXX_STANDARD 17
            CXX_STANDARD_REQUIRED YES
            CXX_EXTENSIONS YES
            C_STANDARD 17
            C_STANDARD_REQUIRED YES
            C_EXTENSIONS YES
)