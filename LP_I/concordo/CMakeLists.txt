cmake_minimum_required(VERSION 3.5)

project(concordo VERSION 1.0 LANGUAGES CXX)

include_directories (include)

add_executable( concordo 
                src/main.cpp
                src/user.cpp
                src/server.cpp
                src/system.cpp
                src/message.cpp
                src/channel.cpp              
                src/channelText.cpp
                src/channelVoice.cpp)
set_property(TARGET concordo PROPERTY CXX_STANDARD 20)