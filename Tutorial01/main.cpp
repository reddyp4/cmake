#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    vector<string> msg {"Print", "using","cmake","with","c++ from Tutorial01"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}