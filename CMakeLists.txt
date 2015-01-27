cmake_minimum_required(VERSION 2.8)
cmake_policy(VERSION 2.8)
project(yggdrasil)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package(Boost REQUIRED)
find_package(Crypto++ REQUIRED)
find_package(CppSpec REQUIRED)

#Add C++14 Support
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")
endif()

enable_testing()

#TODO: Clang Sanitizer options
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")

#TODO: check whether we are statically or dynamically linking to Boost
add_definitions(-DBOOST_LOG_DYN_LINK)

include_directories(${CMAKE_SOURCE_DIR}/include)
add_subdirectory(src/yggdrasil)
