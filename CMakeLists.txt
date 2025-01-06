cmake_minimum_required(VERSION 3.10)
project(pets_project)

# Debug messages
message(STATUS "Starting CMake configuration...")
message(STATUS "Project source dir: ${CMAKE_CURRENT_SOURCE_DIR}")

if(GITHUB_ACTIONS)
    message(STATUS "Building on GitHub Actions")
    message(STATUS "CMake Current Source Dir: ${CMAKE_CURRENT_SOURCE_DIR}")
    message(STATUS "CMake Include Dir: ${CMAKE_CURRENT_SOURCE_DIR}/include")
endif()

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create executable first
add_executable(pets_project 
    src/main.cpp
    src/Pet.cpp
    src/Customer.cpp
    src/Cashier.cpp
    src/Manager.cpp
    src/PetShop.cpp
    src/CustomException.cpp
)

message(STATUS "Executable target created")

# Then add include directories
target_include_directories(pets_project PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

message(STATUS "Include directories added")
