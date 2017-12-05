cmake_minimum_required(VERSION 3.0)
project(libgeneric VERSION 0.0.1 DESCRIPTION "A collection of useful generic data structures.")
include(GNUInstallDirs)

add_library(libgeneric SHARED
    src/slice.c)

set_target_properties(libgeneric PROPERTIES 
    VERSION ${PROJECT_VERSION}
    PUBLIC_HEADER include/slice.h)

target_include_directories(libgeneric PRIVATE include)
target_include_directories(libgeneric PRIVATE src)

install(TARGETS libgeneric
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})


enable_testing()

add_executable(slice_test test/slice_test.c)
target_include_directories(slice_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(slice_test libgeneric)
add_test (NAME SliceTest COMMAND slice_test "slice_test")