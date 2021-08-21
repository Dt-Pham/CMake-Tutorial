cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(USE_MYMATH "Use tutorial provided math implementation" ON)

# configure header file
configure_file(TutorialConfig.h.in TutorialConfig.h)

# add the MathFunctions library
if(USE_MYMATH)
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)
endif()

# add executable
add_executable(Tutorial square_root.cpp)

target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})

# add directories to list of paths to search for include files
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

# install rules
install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
        DESTINATION include
        )

# enable dashboard scripting
include(CTest)

# does the application run
add_test(NAME Runs COMMAND Tutorial 25)

# does the usage message work?
add_test(NAME Usage COMMAND Tutorial)
set_tests_properties(Usage
                     PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
                     )

# define a function to simplify adding tests
function(do_test target arg result)
    add_test(NAME Comp${arg} COMMAND ${target} ${arg})
    set_tests_properties(Comp${arg}
                         PROPERTIES PASS_REGULAR_EXPRESSION ${result}
                         )
endfunction(do_test)

# do a bunch of result based tests
do_test(Tutorial 4 ".*sqrt\\(4\\) = 2")
do_test(Tutorial 9 ".*sqrt\\(9\\) = 3")
do_test(Tutorial 5 ".*sqrt\\(5\\) = 2.236")
do_test(Tutorial 7 ".*sqrt\\(7\\) = 2.645")
do_test(Tutorial 25 ".*sqrt\\(25\\) = 5")
do_test(Tutorial -25 ".*sqrt\\(4\\) = [-nan|nan|0]")
do_test(Tutorial 0.0001 ".*sqrt\\(0.0001\\) = 0.01")

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
include(CPack)

