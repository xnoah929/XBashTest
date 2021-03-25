#ifndef __Command_h__
#define __Command_h__

#include <iostream>
#include <vector>

extern "C" {
    #include <unistd.h>
    #include <signal.h>
    // This include is more linux specific.
    #include <sys/prctl.h>    
}

class Command {
    public:
        Command(const std::string &commands);
        virtual bool Execute();
        virtual std::string CommandHelp();
        virtual std::string CommandOutput();

    protected:
        const std::string RunCommand(const std::string &command, char *args[]);
        long ConvertArguments(const std::string &args, std::vector<std::string> &vargs, const char ch);
        const std::string &origCommands;
    
    private:
};

#endif