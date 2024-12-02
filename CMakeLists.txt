cmake_minimum_required(VERSION 3.26)

# Set the project name and executable name
project(oop)

# Set the C++ standard and related settings
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include additional configuration options
include(cmake/Options.cmake)

# Add the executable and source files
add_executable(${PROJECT_NAME}
        cpp/main.cpp
        cpp/src/Helper.cpp
)

# Add include directories for your project
# SYSTEM is used to suppress warnings from external libraries
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE
        cpp/include
)

# Add include directories for the godot-cpp library
target_include_directories(${PROJECT_NAME} PUBLIC
        ${PROJECT_SOURCE_DIR}/godot-cpp/include/godot_cpp/classes
        ${PROJECT_SOURCE_DIR}/godot-cpp/include/godot_cpp/core
        ${PROJECT_SOURCE_DIR}/godot-cpp/include/godot_cpp/templates
        ${PROJECT_SOURCE_DIR}/godot-cpp/include/godot_cpp/variant
        ${PROJECT_SOURCE_DIR}/godot-cpp/include/godot_cpp
)

# Link the precompiled library from godot-cpp (if it exists)
target_link_libraries(${PROJECT_NAME} PRIVATE
        ${PROJECT_SOURCE_DIR}/godot-cpp/bin/GodotLibrariesInCpp.lib
)

# Set additional compiler flags
include(cmake/CompilerFlags.cmake)

# Copy built binaries to the "bin" folder; these are uploaded as artifacts on each release
# DESTINATION_DIR is set as "bin" in cmake/Options.cmake:6
install(TARGETS ${PROJECT_NAME} DESTINATION ${DESTINATION_DIR})
if (APPLE)
    install(FILES launcher.command DESTINATION ${DESTINATION_DIR})
endif ()

# Copy additional files needed for runtime
include(cmake/CopyHelper.cmake)