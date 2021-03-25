add_library(command.lib STATIC CreateDirectory.cpp CreateDirectory.h Command.cpp Command.h)
target_include_directories(command.lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})