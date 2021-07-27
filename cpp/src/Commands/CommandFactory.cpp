#include "CommandFactory.h"

CommandFactory::CommandFactory() 
{

}

std::unique_ptr<Command> CommandFactory::createCommand(const std::string &commandLine) 
{
    // Using the internal hashing map to speed up command matching.
    supportedCommands_.insert( {
        {"Missing", CommandType::MISSING},
        {CreateDirectory::createDirectoryCommand(), CommandType::CREATE_DIRECTORY},
        {"salt", CommandType::SALT}} ); 

    // Assuming one command per call.
    std::unique_ptr<Command> commandPtr;
    CommandType hash = CommandType::MISSING;
    const std::string command = parseCommand(commandLine);
    try 
    {
        hash = supportedCommands_.at(command);
    } 
    catch(const std::out_of_range &e) 
    {
        // Not going to do anything here for error.
    }

    switch(hash) 
    {
        case CommandType::CREATE_DIRECTORY: 
            commandPtr = std::make_unique<CreateDirectory>(commandLine);
            break;
        
        case CommandType::SALT:
            //something
            break;
    }
    
    // Something happened and we didn't get a command.
    if (CommandType::MISSING == hash || nullptr == commandPtr) 
    {
        // return a base class to message the problem.
        commandPtr = std::make_unique<Command>(command);
    }

   return std::move(commandPtr); 
}

const std::string CommandFactory::parseCommand( const std::string &commandLine) 
{
    // Remove leading whitespace
    std::size_t location = commandLine.find_first_not_of(" \n\r\t\f\v");
    std::string temp = (std::string::npos == location) ? commandLine : commandLine.substr(location);

    // remove arguments and leave only the command.
    location = temp.find_first_of(' ');
    temp = (std::string::npos == location) ? temp : temp.substr(0,location);

    return temp;
}