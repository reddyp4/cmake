// A simple program 
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

#include "Config.h"

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        //Report version
        /*std::cout << argv[0] << " Version " << Main_VERSION_MAJOR << "."
                  << Main_VERSION_MINOR << std::endl;
        std::cout << "Usage " << argv[0] << "number" << std::endl;*/
        return 1;
    }
    // convert input to double
    const double inputValue = atof(argv[1]);

    //calculate square root
    const double outputValue = sqrt(inputValue);
    std::cout << "Square root of " << inputValue << " is " << outputValue << std::endl;
    
    std::cout << "Entering main " << std::endl;
    return 0;
}