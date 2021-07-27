#ifndef __CommandFactory_h__
#define __CommandFactory_h__

#include <iostream>
#include <sstream> 
#include <unordered_map>
#include <cstddef>
#include <stdexcept>
#include <memory>
#include "Command.h"
#include "CreateDirectory.h"

enum class CommandType{MISSING, CREATE_DIRECTORY, SALT};

class CommandFactory 
{
    public:
        CommandFactory();
        std::unique_ptr<Command> createCommand(const std::string &commandLine);
    
    private:
        const std::string origCommand_;
        std::unordered_map<std::string, CommandType> supportedCommands_;
        const std::string parseCommand( const std::string &commandLine);
};

#endif