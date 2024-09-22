cmake_minimum_required(VERSION 3.28)
project(PlaneGame LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

# Create a resource file
set(RESOURCE_FILE "${CMAKE_CURRENT_SOURCE_DIR}/resources/resources.rc")

# Add the resource file to the project
add_custom_command(OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/resources.res"
    COMMAND windres "${RESOURCE_FILE}" -o "${CMAKE_CURRENT_BINARY_DIR}/resources.o"
    DEPENDS "${RESOURCE_FILE}"
    COMMENT "Generating resource file"
)

# Create the main executable target for the project
add_executable(PlaneGame src/main.cpp ${RESOURCE_FILE})

target_link_libraries(PlaneGame PRIVATE sfml-graphics sfml-audio sfml-network sfml-system sfml-window)

target_compile_features(PlaneGame PRIVATE cxx_std_17)

target_include_directories(PlaneGame PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(WIN32)
    add_custom_command(
        TARGET PlaneGame
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:PlaneGame>
        VERBATIM)
endif()
