cmake_minimum_required(VERSION 3.26)

# Set the project name
project(oop)

# Set the C++ standard and related settings
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define paths for the Godot C++ bindings
set(CPP_DIR "${CMAKE_SOURCE_DIR}/cpp")
set(GODOT_CPP_DIR "${CMAKE_SOURCE_DIR}/gdextension/godot-cpp")
set(GODOT_CPP_GEN_INCLUDE "${GODOT_CPP_DIR}/gen/include")
set(GODOT_CPP_INCLUDE "${GODOT_CPP_DIR}/include")
set(GODOT_CPP_BIN "${GODOT_CPP_DIR}/bin")
set(GDEXTENSION_INCLUDE "${CMAKE_SOURCE_DIR}/gdextension/godot-cpp/gdextension")

# Add the executable and source files
add_executable(${PROJECT_NAME}
        cpp/Objects/Player.h
        cpp/Objects/Ice.h
        cpp/Objects/Walls.h
        cpp/Objects/Environment.h
        cpp/Objects/Sand.h

        cpp/src/Player.cpp
        cpp/src/Sand.cpp
        cpp/src/Environment.cpp
        cpp/main.cpp

        cpp/Exceptions/NegativeSpeedException.h

        gdextension/src/gdexample.h
        gdextension/src/gdexample.cpp
        gdextension/src/register_types.cpp
        gdextension/src/register_types.h

        cpp/src/Walls.cpp
        cpp/src/Ice.cpp
        cpp/Objects/Templates/MenuButton.h
        cpp/src/Level1.cpp
        cpp/Objects/Level1.h
        cpp/DesignPatterns/EnvironmentAdapter.h
        cpp/Objects/WallsAdapter.h
        cpp/Objects/IceAdapter.h
        cpp/Objects/SandAdapter.h
        cpp/Objects/Templates/MenuManager.h
        cpp/Objects/SettingsScene.h
        cpp/include/Helper.h
        cpp/DesignPatterns/PlayerState.h
        cpp/Exceptions/OutOfBoundsException.h
        cpp/src/PlayerState.cpp
        cpp/Objects/IdleState.h
        cpp/src/IdleState.cpp
        cpp/Objects/MovingState.h
        cpp/src/MovingState.cpp
        cpp/Objects/InAirState.h
        cpp/Objects/DyingState.h
        cpp/src/InAirState.cpp
        cpp/src/DyingState.cpp
        cpp/Exceptions/HighSpeedException.h


)

# Add include directories for your project
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE
        ${CPP_DIR}/include
        ${CPP_DIR}/Exceptions
        ${CPP_DIR}/Objects
        ${CPP_DIR}/Objects/Templates
        ${CPP_DIR}/src
        ${CPP_DIR}
        ${CPP_DIR}/DesignPatterns
        cpp/include
)

# Add include directories for the Godot C++ library
target_include_directories(${PROJECT_NAME} PUBLIC
        ${GODOT_CPP_GEN_INCLUDE}
        ${GODOT_CPP_INCLUDE}
        ${GODOT_CPP_INCLUDE}/godot_cpp
        ${GODOT_CPP_INCLUDE}/godot_cpp/classes
        ${GODOT_CPP_INCLUDE}/godot_cpp/core
        ${GODOT_CPP_INCLUDE}/godot_cpp/templates
        ${GODOT_CPP_INCLUDE}/godot_cpp/variant
        ${GDEXTENSION_INCLUDE}
)

# Link the precompiled library from godot-cpp
target_link_libraries(${PROJECT_NAME} PRIVATE
        ${GODOT_CPP_BIN}/libgodot-cpp.windows.template_debug.x86_64.lib  # Adjust this path if needed
)

# Output directory for the shared library
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

# Copy built binaries to the "bin" folder
install(TARGETS ${PROJECT_NAME} DESTINATION ${DESTINATION_DIR})
if (APPLE)
    install(FILES launcher.command DESTINATION ${DESTINATION_DIR})
endif ()

# Debugging information
message(STATUS "Godot C++ Bindings: ${GODOT_CPP_DIR}")
message(STATUS "Output Directory: ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")

# Ensure the library has correct platform-specific suffixes
if (WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".dll")
elseif (APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".dylib")
else ()
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".so")
endif ()

# Enable warnings and debugging for development
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -g)
endif ()

# Copy additional files needed for runtime
include(cmake/CopyHelper.cmake)
