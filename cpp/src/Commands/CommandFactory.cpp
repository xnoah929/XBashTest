#include "CommandFactory.h"

CommandFactory::CommandFactory() {

}

Command* CommandFactory::CreateCommand(const std::string &commandLine) {
    // Using the internal hashing map to speed up command matching.
    supportedCommands.insert( {
        {"Missing", 0},
        {CreateDirectory::CreateDirectoryCommand(), 1},
        {"salt", 2}} ); 

    // Assuming one command per call.
    Command *commandptr = nullptr;
    int hash = 0;
    const std::string command = ParseCommand(commandLine);
    try {
        hash = supportedCommands.at(command);
    } catch(const std::out_of_range &e) {
        // Not going to do anything here for error.
    }

    switch(hash) {
        case 1: 
            commandptr = new CreateDirectory(commandLine);
            break;
        
        case 2:
            //something
            break;
    }
    
    // Something happened and we didn't get a command.
    if (hash == 0 || commandptr == nullptr) {
        // return a base class to message the problem.
        commandptr = new Command(command);
    }

   return commandptr; 
}

const std::string CommandFactory::ParseCommand( const std::string &commandLine) {
    // Remove leading whitespace
    std::size_t location = commandLine.find_first_not_of(" \n\r\t\f\v");
    std::string temp = (location == std::string::npos) ? commandLine : commandLine.substr(location);

    // remove arguments and leave only the command.
    location = temp.find_first_of(' ');
    temp = (location == std::string::npos) ? temp : temp.substr(0,location);

    return temp;
}