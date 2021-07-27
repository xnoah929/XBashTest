#include "Commands.h"


Commands::Commands(const std::string &commands) : origCommands(commands) 
{
}

bool Commands::run(std::string &output) 
{
    bool failed = true;
    CommandFactory commandFactory;

    // Command Factory always constructs an object so we don't have to worry about nullptr issues.
    std::unique_ptr<Command> command = commandFactory.createCommand(origCommands);

    if (command->execute()) 
    {        
        failed = true;
    } 
    else 
    {
        failed = false;
    } 

    output = command->commandOutput();
    
    return failed;    
}