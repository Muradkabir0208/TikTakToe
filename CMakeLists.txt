cmake_minimum_required(VERSION 3.13)
project(TikTakToe)

set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif()

if (${CMAKE_BUILD_TYPE} STREQUAL Release)
    add_definitions("-DRELEASE_BUILD")

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
    
    if (WIN32)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows")
    endif ()
else()
    add_definitions("-DDEBUG_BUILD")
endif()

message("Building ${PROJECT_NAME} in ${CMAKE_BUILD_TYPE} mode")

file(GLOB PROJECT_HEADERS src/*.h)
file(GLOB PROJECT_SOURCE src/*.cpp)
file(GLOB SCENES_HEADERS src/scenes/*.h)
file(GLOB SCENES_SOURCE src/scenes/*.cpp)
file(GLOB SCENES_UI_HEADERS src/scenes/ui/*.h)
file(GLOB SCENES_UI_SOURCE src/scenes/ui/*.cpp)

add_executable(TikTakToe ${PROJECT_HEADERS} ${PROJECT_SOURCE} ${SCENES_HEADERS} ${SCENES_SOURCE} 
                ${SCENES_UI_HEADERS} ${SCENES_UI_SOURCE})

# Check if SFML is already installed
find_package(SFML 2.5 COMPONENTS system graphics network QUIET)

# If SFML is not found, clone it from GitHub
if(NOT SFML_FOUND)
    message(STATUS "SFML not found, cloning from Github")
    include(FetchContent)
    FetchContent_Declare(SFML GIT_REPOSITORY https://github.com/SFML/SFML GIT_TAG 2.5.x)
    FetchContent_MakeAvailable(SFML)
endif()

target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

ADD_CUSTOM_COMMAND(TARGET TikTakToe POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_SOURCE_DIR}/res" "${CMAKE_CURRENT_BINARY_DIR}/res")
if(NOT SFML_FOUND)
  add_custom_command(TARGET TikTakToe POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_BINARY_DIR}/_deps/sfml-build/lib" "${CMAKE_CURRENT_BINARY_DIR}"
  )
endif()	