#ifndef __HelpText_h__
#define __HelpText_h__

#include <iostream>
#include <sstream> 

class HelpText {
    public:
        HelpText();
        static const std::ostringstream& GetText(); 
        friend std::ostream &operator<<(std::ostream &out, const HelpText &helpText );
    
    private:
        static const std::ostringstream& TheText();
};

#endif