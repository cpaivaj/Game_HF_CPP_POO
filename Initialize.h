#ifndef INITIALIZE_H_INCLUDED
#define INITIALIZE_H_INCLUDED

// this is the header, contains attributes and methods
// private attributes, public methods
#include "SDL_opengl.h"
#include <string>

#define WIDTH 600
#define HEIGHT 400

class Initialize
{
    public:
        void InitSDL();
        GLuint LoadTexture(const std::string&fileName);
};

#endif // INITIALIZE_H_INCLUDED
