#ifndef __Commands_h__
#define __Commands_h__

#include <iostream>

class Commands {
    public:
        Commands(const std::string &commands);
        bool Run();
    
    private:
        const std::string origCommands;
};

#endif