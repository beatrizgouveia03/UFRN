cmake_minimum_required(VERSION 3.5)

project(menu_musicas VERSION 1.0 LANGUAGES CXX)

include_directories (include)

file(GLOB_RECURSE SOURCE_FILES
    "src/*.cpp"
    "src/menus/*.cpp"
)

add_executable( program  ${SOURCE_FILES})

set_property(TARGET program PROPERTY CXX_STANDARD 20)