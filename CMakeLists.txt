cmake_minimum_required(VERSION 3.23)
project(Project)

set(CMAKE_CXX_STANDARD 20)

# Find required SDL2 packages
find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_image REQUIRED)

# To download files
include(FetchContent)

# Download nlohmann JSON library
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

# Specify the source directory and the build directory
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR})

add_executable(${PROJECT_NAME} src/main.cpp src/Game.cpp src/Game.h src/InputHandler.cpp src/InputHandler.h src/TTFManager.cpp src/TTFManager.h src/ConfigHelper.cpp src/ConfigHelper.h)

# STATIC stuff for Windows
if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    
    set(BUILD_FOR_WIN TRUE)

    if(MINGW)
        # To detect Windows compilers
        target_link_libraries(${PROJECT_NAME} SDL2::SDL2main SDL2::SDL2 SDL2_ttf::SDL2_ttf SDL2_image::SDL2_image nlohmann_json::nlohmann_json mingw32)
    elseif(WIN32)
        # To detect Windows operating system in general
        target_link_libraries(${PROJECT_NAME} SDL2::SDL2main SDL2::SDL2 SDL2_ttf::SDL2_ttf SDL2_image::SDL2_image nlohmann_json::nlohmann_json)
    endif()

    # Copy SDL2 dlls to build folder
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:${PROJECT_NAME}> $<TARGET_FILE_DIR:${PROJECT_NAME}>
            COMMAND_EXPAND_LISTS
    )

    # Static link libs
    set(CMAKE_EXE_LINKER_FLAGS "-static")
    set(CMAKE_FIND_LIBRARY_SUFFIXES ".a" CONFIG)
    set(BUILD_SHARED_LIBS OFF)

endif()

# Create a custom command to copy the assets folder to the build folder
if(WIN32)
    # To detect Windows operating system in general
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${SOURCE_DIR}/Assets ${BUILD_DIR}/Debug/Assets
    )
else()
    add_custom_command(
            TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${SOURCE_DIR}/Assets ${BUILD_DIR}/Assets
    )

endif()

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    target_link_libraries(${PROJECT_NAME} SDL2::SDL2main SDL2::SDL2 SDL2_ttf::SDL2_ttf SDL2_image::SDL2_image  nlohmann_json::nlohmann_json)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")