# include "Command.h"

Command::Command(const std::string &commands) : origCommands(commands){   
}

bool Command::Execute() {
    // Creating concrete parent class so fail if forget to implement.
    return true;
}

std::string Command::CommandHelp() {
    // Creating concrete parent class so message if forget to implement.
    return "Help is not implemented!";
}

std::string Command::CommandOutput() {
    // Creating concrete parent class so message if forget to implement.
    return "Command Output is not implemented!";
}

const std::string Command::RunCommand(const std::string &command, char *args[]) {
    int pipefd[2];
    pipe(pipefd);
    std::string response;

    if (fork() == 0) {
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

        while (read(pipefd[0], buffer, sizeof(buffer)) != 0)
        {
            response += buffer;
        }
    }

    return response;
}

long Command::ConvertArguments(const std::string &args, std::vector<std::string> &vargs, const char ch)
{
    size_t pos = args.find( ch );
    size_t initialPos = 0;
    vargs.clear();

    // Parse the string to vector (tokens)
    while( pos != std::string::npos ) {
        vargs.push_back( args.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;

        pos = args.find( ch, initialPos );
    }

    // Need to get the last item.
    vargs.push_back( args.substr( initialPos, std::min( pos, args.size() ) - initialPos + 1 ) );

    // We use this to get the size of a character array later.
    return vargs.size();
}