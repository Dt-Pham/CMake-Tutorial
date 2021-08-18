# generate Table.h
add_executable(MakeTable MakeTable.cpp)

add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    DEPENDS MakeTable
    )

add_library(MathFunctions
            mysqrt.cpp
            ${CMAKE_CURRENT_BINARY_DIR}/Table.h
            )

target_include_directories(MathFunctions
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                           PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
                           )

# check if the system have function log() and exp()
include(CheckSymbolExists)
check_symbol_exists(log "math.h" HAVE_LOG)
check_symbol_exists(exp "math.h" HAVE_EXP)
if(NOT (HAVE_LOG AND HAVE_EXP))
    unset(HAVE_LOG CACHE)
    unset(HAVE_EXP CACHE)
    set(CMAKE_REQUIRED_LIBRARIES "m")
    check_symbol_exists(log "math.h" HAVE_LOG)
    check_symbol_exists(exp "math.h" HAVE_EXP)
    if(HAVE_LOG AND HAVE_EXP)
        target_link_libraries(MathFunctions PRIVATE m)
    endif()
endif()

# if available specify HAVE_LOG and HAVE_EXP as PRIVATE compile definitions.
if(HAVE_LOG AND HAVE_EXP)
    target_compile_definitions(MathFunctions
                               PRIVATE "HAVE_LOG" "HAVE_EXP")
endif()                               

# install rules
install(TARGETS MathFunctions DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)

