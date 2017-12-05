cmake_minimum_required(VERSION 3.0)
project(libgeneric VERSION 0.0.1 DESCRIPTION "A collection of useful generic data structures.")
include(GNUInstallDirs)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
add_library(libgeneric SHARED
    src/slice.c
    src/arraylist.c
    src/linkedlist.c)

set_target_properties(libgeneric PROPERTIES 
    VERSION ${PROJECT_VERSION}
    PUBLIC_HEADER include/*)

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

add_executable(arraylist_test test/arraylist_test.c)
target_include_directories(arraylist_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(arraylist_test libgeneric)
add_test (NAME ArraylistTest COMMAND arraylist_test "arraylist_test")

add_executable(linkedlist_test test/linkedlist_test.c)
target_include_directories(linkedlist_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(linkedlist_test libgeneric)
add_test (NAME LinkedlistTest COMMAND linkedlist_test "linkedlist_test")