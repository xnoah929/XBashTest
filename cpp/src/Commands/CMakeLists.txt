add_subdirectory(Command)
add_library(commands.lib STATIC CommandFactory.cpp CommandFactory.h Commands.cpp Commands.h)
target_link_libraries(commands.lib  command.lib)
target_include_directories(commands.lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})