# make sure the version of CMake is sufficient for the features we use
cmake_minimum_required(VERSION 3.13)

#project name and programming language
project(gtest-demo LANGUAGES CXX)

# set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# place binaries and libraries according to GNU standards
include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

# the actual code is in src/, include the
# CMakeLists.txt file there
add_subdirectory(src)

# add the 'make test' target and enable 'ctest'
enable_testing()

# in the test/CMakeLists.txt file,
# GoogleTest is installed and the tests are compiled and linked
# into an executable called unit_tests
add_subdirectory(test)
