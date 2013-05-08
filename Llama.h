#ifndef LLAMA_H
#define LLAMA_H

#include "SDL.h"
#include "SDL_image.h"
#include <string>

class Llama
{
    public:
        int x;
        int y;
        int velocity;
        int acceleration;
        int current_frame;
        SDL_Surface *images[3];
        SDL_Surface *screen;

        Llama(SDL_Surface *screen);
        void logic();
        void render();
        void jump();
        virtual ~Llama();
    protected:
    private:


};

#endif // LLAMA_H
