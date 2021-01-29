cmake_minimum_required(VERSION 3.10)

    project(Deque)

        enable_testing()

            add_executable(DequeDemo DequeDemo.cpp)

                set_property(TARGET DequeDemo PROPERTY CXX_STANDARD 20)

                    set(CMAKE_CXX_FLAGS_RELEASE "/MT")
                        set(CMAKE_CXX_FLAGS_DEBUG "/MTd")

                            add_subdirectory(unit_tests)
                                add_subdirectory(googletest)