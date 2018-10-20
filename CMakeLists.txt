cmake_minimum_required(VERSION 3.12)
project(CMakeTuto)

set(CMAKE_CXX_STANDARD 17)

set(CMakeTuto_VERSION_Major 1)
set(CMakeTuto_VERSION_Minor 0)

option(USE_MYMATH
        "Use my math implementation" ON)

configure_file(
        "${PROJECT_SOURCE_DIR}/CMakeTutoConfig.h.in"
        "${PROJECT_BINARY_DIR}/CMakeTutoConfig.h"
        )

include_directories("${PROJECT_BINARY_DIR}")
if(USE_MYMATH)
    include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
    add_subdirectory(MathFunctions)
    set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif(USE_MYMATH)

add_executable(CMakeTuto main.cpp CMakeTutoConfig.h.in)
target_link_libraries(CMakeTuto ${EXTRA_LIBS})

# add the install targets
install (TARGETS CMakeTuto DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/CMakeTutoConfig.h"
        DESTINATION include)

include(CTest)

# does the application run
add_test (TutorialRuns CMakeTuto 25)
# does it sqrt of 25
add_test (TutorialComp25 CMakeTuto 25)
set_tests_properties (TutorialComp25 PROPERTIES PASS_REGULAR_EXPRESSION "25 is 5")
# does it handle negative numbers
add_test (TutorialNegative CMakeTuto -25)
set_tests_properties (TutorialNegative PROPERTIES PASS_REGULAR_EXPRESSION "-25 is 0")
# does it handle small numbers
add_test (TutorialSmall CMakeTuto 0.0001)
set_tests_properties (TutorialSmall PROPERTIES PASS_REGULAR_EXPRESSION "0.0001 is 0.01")
# does the usage message work?
add_test (TutorialUsage CMakeTuto)
set_tests_properties (TutorialUsage PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number")