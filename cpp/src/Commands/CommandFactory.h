#ifndef __CommandFactory_h__
#define __CommandFactory_h__

#include <iostream>
#include <sstream> 
#include <unordered_map>
#include <cstddef>
#include <stdexcept>
#include "Command.h"
#include "CreateDirectory.h"

class CommandFactory {
    public:
        CommandFactory();
        Command* CreateCommand(const std::string &commandLine);
    
    private:
        const std::string origCommand;
        std::unordered_map<std::string, int> supportedCommands;
        const std::string ParseCommand( const std::string &commandLine);
};

#endif