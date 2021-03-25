#ifndef __Commands_h__
#define __Commands_h__

#include <iostream>
#include "CommandFactory.h"
#include "Command.h"

class Commands {
    public:
        Commands(const std::string &commands);
        bool Run(std::string &output);
    
    private:
        const std::string origCommands;
};

#endif