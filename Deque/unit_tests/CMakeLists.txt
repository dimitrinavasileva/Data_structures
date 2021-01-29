cmake_minimum_required(VERSION 3.10)

project(DequeUnitTest)

add_executable(DequeUnitTest MainUnitTest.cpp DequeUnitTest.cpp)

set_property(TARGET DequeUnitTest PROPERTY CXX_STANDARD 20)

target_link_libraries(DequeUnitTest gtest gtest_main)

target_include_directories(DequeUnitTest PUBLIC 
    			    ${CMAKE_CURRENT_SOURCE_DIR}/..
    			    ${CMAKE_CURRENT_SOURCE_DIR}/../../../unit_test_framework)