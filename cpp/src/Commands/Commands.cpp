#include "Commands.h"


Commands::Commands(const std::string &commands) : origCommands(commands) {
}

bool Commands::Run(std::string &output) {
    bool failed = true;
    CommandFactory commandFactory;
    Command *command = commandFactory.CreateCommand(origCommands);
    if (command->Execute()) {        
        failed = true;
    } else {
        failed = false;
    } 
    output = command->CommandOutput();
    
    // Factory created pointer and we must handle it here.
    delete command;
    return failed;    
}