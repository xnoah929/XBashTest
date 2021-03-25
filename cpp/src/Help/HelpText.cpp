#include "HelpText.h"

HelpText::HelpText() {
    // Empty constructor
}

const std::ostringstream& HelpText::TheText() {
    // Here we put all the text we need in the help
    static std::ostringstream text;
    text << "Welcome to the XBash Interface Help." << std::endl
        << "This should be a module itself for --help command in xbash" << std::endl;
    return text;
}

const std::ostringstream& HelpText::GetText() {
    // There is a slight cost of transfering the contents but
    // this will make a static global object for help. Which can 
    // be called in our out of the Object.  Can use the nice ostringstream
    // formated text and I original wrote the help with cout so ostringstream
    // was a nice conversion.  This is one static location for the text and avoids
    // the static initialization order fiasco.
    static const std::ostringstream *helpText = new std::ostringstream(TheText().str());

    return *helpText;
}

std::ostream &operator<<(std::ostream &out, const HelpText &helpText ) {
    out << helpText.GetText().str();
    return out;
}