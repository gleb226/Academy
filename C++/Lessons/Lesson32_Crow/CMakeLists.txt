cmake_minimum_required(VERSION 4.0)
project(Lesson32_Crow)

set(CMAKE_CXX_STANDARD 20)
find_package(Crow CONFIG REQUIRED)


add_executable(Lesson32_Crow main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Crow::Crow asio::asio)