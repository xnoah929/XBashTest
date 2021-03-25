#include <iostream>
#include <fstream>
#include "HelpText.h"
#include "CommandFactory.h"

int main(int argc, char *argv[]) {
    std::string inputCommand;
    HelpText helpText;
    // Exit state for processing commands.
    bool notDone = true;
    // If someone runs this program with any input
    // we want to put up the help information.
    CommandFactory commandFactory;
    if (argc > 1) {
        std::cout << helpText
        << "argc = " << argc << "argv = " << *argv[0] << std::endl << helpText;
        return 0;
    }

    // Now we start getting some input.
    while(notDone) {
        std::cout << ">>$ ";
        std::getline(std::cin, inputCommand);
        
        // Just end if exit
        if (inputCommand == "exit") {
            break;
        }

        Command *command = commandFactory.CreateCommand(inputCommand);
        if (!command->Execute()) {
            std::cout << "Command Line Failed " << inputCommand << std::endl;
            std::cout << "More information " << command->CommandOutput() << std::endl;
        } else {
            std::cout << command->CommandOutput() << std::endl;
        }
    }

    return 0;
}