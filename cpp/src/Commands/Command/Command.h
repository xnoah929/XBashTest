#ifndef __Command_h__
#define __Command_h__

#include <iostream>
#include <vector>

extern "C" 
{
    #include <unistd.h>
    #include <signal.h>
    // This include is more linux specific.
    #include <sys/prctl.h>    
}

class Command 
{
    public:
        Command(const std::string &commands);
        virtual bool execute();
        virtual std::string commandHelp();
        virtual std::string commandOutput();

    protected:
        const std::string runCommand(const std::string &command, char *args[]);
        long convertArguments(const std::string &args, std::vector<std::string> &vargs, const char ch);
        const std::string &origCommands;
    
    private:
};

#endif