#include <iostream>
#include <fstream>
#include "HelpText.h"
#include "Commands.h"


int main(int argc, char *argv[]) 
{
    std::string inputCommand;
    std::string outputCommand;
    HelpText helpText;
    // Exit state for processing commands.
    bool notDone = true;
    // If someone runs this program with any input
    // we want to put up the help information.
    if (argc > 1) 
    {
        std::cout << helpText
        << "argc = " << argc << "argv = " << *argv[0] << std::endl << helpText;
        return 0;
    }

    // Now we start getting some input.
    while (notDone) 
    {
        std::cout << ">>$ ";
        std::getline(std::cin, inputCommand);
        
        // Just end if exit
        if (inputCommand == "exit") 
        {
            break;
        }

        Commands commands(inputCommand);
        
        if (commands.run(outputCommand)) 
        {
            std::cout << "Command Line Failed " << inputCommand << std::endl;
            std::cout << "More information " << outputCommand << std::endl;
        } 
        else 
        {
            std::cout << outputCommand << std::endl;
        }

    }

    return 0;
}