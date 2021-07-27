#ifndef __Commands_h__
#define __Commands_h__

#include <iostream>
#include <memory>
#include "CommandFactory.h"
#include "Command.h"

class Commands 
{
    public:
        Commands(const std::string &commands);
        bool run(std::string &output);
    
    private:
        const std::string origCommands;
};

#endif