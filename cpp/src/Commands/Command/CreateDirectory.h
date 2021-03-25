#ifndef __CreateDirectory_h__
#define __CreateDirectory_h__

#include <iostream>
#include <new> 
#include "Command.h"
#include <cstring>

class CreateDirectory : public Command {
    public:
        CreateDirectory(const std::string &commandLine);
        virtual bool Execute();
        virtual std::string CommandHelp();
        virtual std::string CommandOutput();
        static const std::string& CreateDirectoryCommand();

    private:
        bool failed;
        std::string commandOutput;
};

#endif