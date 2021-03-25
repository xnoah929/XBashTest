include_directories(Help Commands/Command Commands)

add_subdirectory(Commands)

list(APPEND _sources Help/HelpText.cpp Help/HelpText.h)

add_executable(${PROJECT_NAME} main.cpp ${_sources})

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC commands.lib command.lib)