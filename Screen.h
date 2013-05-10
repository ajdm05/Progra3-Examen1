#ifndef SCREEN_H
#define SCREEN_H

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "Timer.h"
#include <iostream>
#include <string>

class Screen
{
    public:
        Screen();
        virtual ~Screen();

        const int SCREEN_WIDTH = 1000;
        const int SCREEN_HEIGHT = 500;
        const int SCREEN_BPP = 32;

      //  SDL_Surface* screen = NULL;
        SDL_Surface* getScreen();

        SDL_Rect offset;


        Timer* update;
        bool init();
        void frameCap();

    private:
        SDL_Surface* pantalla;
};

#endif // SCREEN_H
