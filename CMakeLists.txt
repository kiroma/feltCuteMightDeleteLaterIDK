cmake_minimum_required(VERSION 3.8.2)
project(Animation)

find_package(SFML COMPONENTS graphics REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main
./Invaders.cpp
./Main.cpp
./Animation.cpp)

target_link_libraries(main PRIVATE sfml-graphics)
file(COPY images/ DESTINATION ${CMAKE_BINARY_DIR}/images)
