#include <iostream>
#include <vector>
#include <string>

#include "tutorial02.h"

using namespace std;

int main(void)
{
    /*vector<string>msg = {"Print", "using","cmake","with","c++ from Tutorial01"};

    for (const string& word : msg)
    {
        std::cout << word << " ";
    }*/
    std::cout << "Print using cmake with c++ from Tutorial01" << std::endl;

    //Run function tutorial02
    tutorial02();
    return 0;
}