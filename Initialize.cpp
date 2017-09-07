//#include "Includes.h"
#include "Initialize.h"
#include <iostream>

#include "SDL.h"

using namespace std;

void Initialize::InitSDL()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    cout << "SDL Initialized!" << endl;
}
