CMAKE_MINIMUM_REQUIRED(VERSION 3.12)

PROJECT(sudoku)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")

endif()

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
SET(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")
AUX_SOURCE_DIRECTORY(src DIR_SRCS)

add_executable(sudoku
   ${DIR_SRCS}
)

enable_testing()
add_executable(getErrortest ${PROJECT_SOURCE_DIR}/test/getErrortest.cpp ${PROJECT_SOURCE_DIR}/src/CreateSudoku.h ${PROJECT_SOURCE_DIR}/src/CreateSudoku.cpp ${PROJECT_SOURCE_DIR}/src/Utils.h ${PROJECT_SOURCE_DIR}/src/Utils.cpp)
add_executable(judgetest ${PROJECT_SOURCE_DIR}/test/judgetest.cpp ${PROJECT_SOURCE_DIR}/src/CreateSudoku.h ${PROJECT_SOURCE_DIR}/src/CreateSudoku.cpp ${PROJECT_SOURCE_DIR}/src/Utils.h ${PROJECT_SOURCE_DIR}/src/Utils.cpp)

add_test( NAME getErrortest COMMAND getErrortest)
add_test( NAME judgetest COMMAND judgetest)
