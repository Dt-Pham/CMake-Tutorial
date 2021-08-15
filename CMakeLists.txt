cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial VERSION 1.0)

# configure header file
configure_file(TutorialConfig.h.in TutorialConfig.h)

# add executable
add_executable(Tutorial square_root.cpp)

# add directories to list of paths to search for include files
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
