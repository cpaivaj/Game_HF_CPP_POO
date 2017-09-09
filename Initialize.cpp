//#include "Includes.h"
#include "Initialize.h"
#include <iostream>

#include <SDL.h>
#include "SDL_opengl.h"
#include "SDL_image.h" // x86

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

GLuint Initialize::LoadTexture(const std::string&fileName)
{
    SDL_Surface *image = IMG_Load(fileName.c_str()); // image load

    SDL_DisplayFormatAlpha(image); // display format

	// create texture
	unsigned object(0);

	glGenTextures(1, &object); // texture generator

	glBindTexture(GL_TEXTURE_2D, object);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->w, image->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image->pixels);

	// free image
	SDL_FreeSurface(image);

	return object;
}









