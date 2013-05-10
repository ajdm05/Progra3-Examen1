#ifndef BACKGROUND_H
#define BACKGROUND_H


#include "SDL.h"
#include "SDL_image.h"
#include <string>
#include "SDL_mixer.h"
#include "SDL_ttf.h"


class Background
{
    public:
        int score;
        Background(SDL_Surface * screen);
        void logic();
        void render();
        bool init();
        void getScore(SDL_Surface *screen);
        void setNumPantalla(int p);
        int getNumPantalla();

        virtual ~Background();

    protected:
    private:
    int x;
    int numPantalla;
    SDL_Surface *image[3];
    SDL_Surface *screen;
};

#endif // BACKGROUND_H
