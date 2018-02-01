#include "Initialize.h"
#include <iostream>

using namespace std;

int main()
{
    bool isRunning = true;

    // Class
    Initialize init;

    // Call functions
    init.SDLInit();

    // Principal loop
    while(isRunning)
    {

    }

    init.SDLQuit();

    return 0;
}
