#include "CreateDirectory.h"

CreateDirectory::CreateDirectory(const std::string &commandLine) : Command(commandLine) {    
}

bool CreateDirectory::Execute(){
    // Will assume we have failed with standard Unix 0 is ok and anything else is failed.
    // Need to implement more rigging in the base implementation to tell if the command worked.
    failed = false;

    // Need to parse and transform arguments because Unix/Linux is not written in C++.
    std::vector<std::string> vargs;
    
    // Convert to somethings we can work with easier (vectors) 
    long numArgs = ConvertArguments(origCommands, vargs, ' ');

    // Just in case protect against silly input aka overflow.
    if (numArgs < 0) {
       // Maybe do some messaging here but shouldn't happen.
    } else {
        // Create an argument list in char *[] form.
        // In summary it is a pointer to array of pointers to array of characters.
        char **pVargs = new char * [numArgs + 1];
        for (long ct = 1, index = 0; ct < numArgs; ct++, index++) {
            pVargs[index] = new char[vargs[ct].length() + 1];
            strcpy(pVargs[index], vargs[ct].c_str());
        }  

        // last item in the char *[] has to be null
        pVargs[numArgs] = nullptr;
        commandOutput = RunCommand(CreateDirectory::CreateDirectoryCommand(), pVargs);

         // 99% of the time when you new something you have to also delete it.  We do the delete here.
         for (long ct = 0; ct < numArgs; ct++) {
             delete pVargs[ct];
         }
         delete [] pVargs;
    }

    return failed;
}
 

std::string CreateDirectory::CommandHelp() {
    static char thisCommand[] = "--help";
    static char endNull[] = "\0";
    static char *args[] = {thisCommand, endNull};
    static std::string help = RunCommand(CreateDirectory::CreateDirectoryCommand(), args);
    return help;
}

std::string CreateDirectory::CommandOutput() {
    if (failed == false) {
        return commandOutput;
    } else {
        return "Creating a Directory Failed.  I am really sorry about that.";
    }
}

const std::string& CreateDirectory::CreateDirectoryCommand() {
    static const std::string *thisCommand = new std::string("mkdir");
    return *thisCommand;
}