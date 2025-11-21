cmake_minimum_required(VERSION 3.20)
project(ContactManager VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")

find_package(nlohmann_json CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

message(STATUS "=================================")
message(STATUS "  ${PROJECT_NAME} v${PROJECT_VERSION}")
message(STATUS "=================================")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "=================================")

add_library(ContactManagerLib
        src/contact.cpp
        src/storage.cpp
)

target_include_directories(ContactManagerLib
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(ContactManagerLib
        PUBLIC
        nlohmann_json::nlohmann_json
        fmt::fmt
)

add_executable(ContactManager src/main.cpp)

target_link_libraries(ContactManager
        PRIVATE
        ContactManagerLib
)

if(MSVC)
    target_compile_options(ContactManagerLib PRIVATE /W4)
    target_compile_options(ContactManager PRIVATE /W4)
else()
    target_compile_options(ContactManagerLib PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(ContactManager PRIVATE -Wall -Wextra -Wpedantic)
endif()