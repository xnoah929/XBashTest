# include "Command.h"

Command::Command(const std::string &commands) : origCommands(commands)
{   
}

bool Command::execute() 
{
    // Creating concrete parent class so fail if forget to implement.
    return true;
}

std::string Command::commandHelp() 
{
    // Creating concrete parent class so message if forget to implement.
    return "Help is not implemented!";
}

std::string Command::commandOutput() 
{
    // Creating concrete parent class so message if forget to implement.
    return "Command Output is not implemented!";
}

const std::string Command::runCommand(const std::string &command, char *args[]) 
{
    int pipefd[2];
    pipe(pipefd);
    std::string response;

    if (fork() == 0) 
    {
        // child fork

        //ask kernel to deliver SIGTERM in case the parent dies
        prctl(PR_SET_PDEATHSIG, SIGTERM);

        // close child end from reading the pipe
        close(pipefd[0]);    

        // redirect stdout to the pipe
        dup2(pipefd[1], 1);
        // redirect stderr to the pipe  
        dup2(pipefd[1], 2);

        execvp(command.c_str(), args );

        // Shouldn't get here but if we do exit.
        exit(1);
    }
    else
    {
        // parent fork
        char buffer[1024];

        // close the parent end from writing to the pipe 
        close(pipefd[1]);

        while (ssize_t bytesRead = read(pipefd[0], buffer, sizeof(buffer)))
        {
            if (bytesRead > 0)
            {
                std::string chunk(buffer, bytesRead);
                // Remove ANSI escape codes using regex
                chunk = std::regex_replace(chunk, std::regex("\x1B\\[[0-9;]*[A-Za-z]"), "");
                // Optionally, filter out non-ASCII characters
                chunk.erase(std::remove_if(chunk.begin(), chunk.end(), [](unsigned char c)
                {
                    // Keep printable ASCII, LF (\n, 10), CR (\r, 13), and NUL (\0)
                    return !( (c >= 32 && c <= 126) || c == 10 || c == 13 || c == 0 );
                }), chunk.end());
                response += chunk;
            }
        }
    }

    return response;
}

long Command::convertArguments(const std::string &args, std::vector<std::string> &vargs, const char ch)
{
    size_t pos = args.find( ch );
    size_t initialPos = 0;
    vargs.clear();

    // Parse the string to vector (tokens)
    while( pos != std::string::npos ) 
    {
        vargs.push_back( args.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;

        pos = args.find( ch, initialPos );
    }

    // Need to get the last item.
    vargs.push_back( args.substr( initialPos, std::min( pos, args.size() ) - initialPos + 1 ) );

    // We use this to get the size of a character array later.
    return vargs.size();
}
