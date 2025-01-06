cmake_minimum_required(VERSION 3.10)
project(pets_project)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set sources
set(SOURCES
    src/main.cpp
    src/Pet.cpp
    src/Customer.cpp
    src/Cashier.cpp
    src/Manager.cpp
    src/PetShop.cpp
    src/CustomException.cpp
)

# Set headers
set(HEADERS
    include/AbstractEntity.h
    include/Pet.h
    include/Customer.h
    include/Employee.h
    include/Cashier.h
    include/Manager.h
    include/PetShop.h
    include/CustomException.h
)

# IMPORTANT: First create the executable
add_executable(pets_project ${SOURCES} ${HEADERS})

# THEN add include directories
target_include_directories(pets_project PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Add compiler warnings
if(MSVC)
    target_compile_options(pets_project PRIVATE /W4)
else()
    target_compile_options(pets_project PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Enable testing (optional)
enable_testing()

# Installation rules
install(TARGETS pets_project
    RUNTIME DESTINATION bin
)
