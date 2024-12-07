# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(MyCProject LANGUAGES C)

# Set C standard (optional)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Enable debug symbols by default if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Add source files (you can also use GLOB to include all .c files in a directory)
set(SOURCES
    main.c       # Replace with your main file
)

# Add executable target
add_executable(${PROJECT_NAME} ${SOURCES})

# Include directories (optional, if you have custom headers)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Link libraries (optional, if your project uses any external libraries)
# target_link_libraries(${PROJECT_NAME} m) # Example for linking the math library
