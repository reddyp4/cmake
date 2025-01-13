// A simple program 
#include <cmath>
#include <iostream>
#include <string>

//#include "MathFunctions.h"
#include "tutorial02.h"
//#include "Config.h"

void tutorial02(void) //int argc, char* argv[])
{
    std::cout << "Printing from Tutorial02 " << std::endl;

#if 0
    if(argc < 2)
    {
        //Report version
        /*
        std::cout << argv[0] << " Version " << Main_VERSION_MAJOR << "."
                  << Main_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << "number" << std::endl;*/
        return 1;
    }
    // convert input to double
    const double inputValue = atof(argv[1]);

    //calculate square root with internal function
    const double outputValue = mathfunctions::sqrt(inputValue);
    std::cout << "Square root of " << inputValue << " is " << outputValue << std::endl;
    
    std::cout << "Finished main " << std::endl;
#endif
    //return 0;
}