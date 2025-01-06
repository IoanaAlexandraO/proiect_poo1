cmake_minimum_required(VERSION 3.26)

# Setăm numele proiectului
set(MAIN_PROJECT_NAME "pets_project")
set(MAIN_EXECUTABLE_NAME "${MAIN_PROJECT_NAME}")

project(${MAIN_PROJECT_NAME})

# Setăm standardul C++ la 23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include directoarele pentru fișiere header
include_directories(include)

# Creăm executabilul cu sursele din "src"
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

# Dacă este nevoie, include directoare pentru fișiere suplimentare
target_include_directories(${MAIN_EXECUTABLE_NAME} SYSTEM PRIVATE generated/include)

###############################################################################
# Instalarea executabilului
install(TARGETS ${MAIN_EXECUTABLE_NAME} DESTINATION ${DESTINATION_DIR})

# Dacă e pe macOS, instalează și fișiere suplimentare
if(APPLE)
    install(FILES launcher.command DESTINATION ${DESTINATION_DIR})
endif()
