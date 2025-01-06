cmake_minimum_required(VERSION 3.26)
set(MAIN_PROJECT_NAME "pets_project")
set(MAIN_EXECUTABLE_NAME "${MAIN_PROJECT_NAME}")
project(${MAIN_PROJECT_NAME})

# Setăm standardul C++ la 23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Specifică explicit calea către directorul include
target_include_directories(${MAIN_PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Adaugă toate sursele
add_executable(${MAIN_EXECUTABLE_NAME}
    main.cpp
    src/Pet.cpp
    src/Customer.cpp
    src/Cashier.cpp
    src/Manager.cpp
    src/PetShop.cpp
    src/CustomException.cpp)

# Include directoare suplimentare pentru fișiere externe
include(cmake/CompilerFlags.cmake)

# Instalarea executabilului
install(TARGETS ${MAIN_EXECUTABLE_NAME} DESTINATION ${DESTINATION_DIR})

if(APPLE)
    install(FILES launcher.command DESTINATION ${DESTINATION_DIR})
endif()
