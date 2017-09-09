//#include "Includes.h"
#include "Initialize.h"
#include <iostream>

#include <SDL.h>
#include "SDL_opengl.h"

using namespace std;

void Initialize::InitSDL()
{
    SDL_Init(SDL_INIT_EVERYTHING);

    // Memory usage
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// name window
	SDL_WM_SetCaption(" My first window ", NULL);

	// dimensions
	SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_OPENGL); // SDL_OPENGL, SDL_FULLSCREEN

	// clear screen RGB
	glClearColor(1,1,1,1);

	// screen visibility
	glViewport(0,0,WIDTH, HEIGHT);

	// shadow
	glShadeModel(GL_SMOOTH);

	// 2D rendering
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glDisable(GL_DEPTH_TEST);

	// blend
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    cout << "SDL Initialized!" << endl;
}
