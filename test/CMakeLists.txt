set (test_SOURCES
    test_datastream.cpp
    main.cpp
)

find_package(CppSpec REQUIRED)

add_executable(yggdrasil_tester ${test_SOURCES})
add_dependencies(yggdrasil_tester cppspec)
target_link_libraries(yggdrasil_tester CppSpec ${BOOST_SYSTEM_LIBRARY})

add_test(yggdrasil_test yggdrasil_tester)