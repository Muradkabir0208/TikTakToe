cmake_minimum_required(VERSION 3.13)
project(TikTakToe)

set(CMAKE_CXX_STANDARD 17)

if (${CMAKE_BUILD_TYPE} Release)
    add_definitions("-DRELEASE_BUILD")

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
    
    if (WIN32)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows")
    endif ()
endif()

message("Building ${PROJECT_NAME} in ${CMAKE_BUILD_TYPE} mode")

file(GLOB PROJECT_HEADERS src/*.h)
file(GLOB PROJECT_SOURCE src/*.cpp)

add_executable(TikTakToe ${PROJECT_HEADERS} ${PROJECT_SOURCE})

find_package(SFML 2.5 COMPONENTS system graphics network REQUIRED)
target_link_libraries(${PROJECT_NAME} sfml-system sfml-graphics sfml-network)

ADD_CUSTOM_COMMAND(TARGET TikTakToe POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_SOURCE_DIR}/res" "${CMAKE_CURRENT_BINARY_DIR}/res")