#ifndef __CreateDirectory_h__
#define __CreateDirectory_h__

#include <iostream>
#include <new> 
#include "Command.h"
#include <cstring>

class CreateDirectory : public Command {
    public:
        CreateDirectory(const std::string &commandLine);
        virtual bool execute() override;
        virtual std::string commandHelp() override;
        virtual std::string commandOutput() override;
        static const std::string& createDirectoryCommand();

    private:
        bool failed_;
        std::string commandOutput_;
};

#endif