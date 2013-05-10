#ifndef PLAYER_H
#define PLAYER_H

#include "SDL.h"
#include "SDL_image.h"
#include "Llama.h"
#include "Enemy.h"
#include "SDL_mixer.h"

#include <string>

class Player
{
public:
    int x;
    int y;
    int velocity;
    int acceleration;
    int current_frame;
    bool murio;
    bool isJumping;
    void isJump();
    void perdio(int x, int y);
    SDL_Surface *images[10];
    SDL_Surface *screen;
    Mix_Chunk *jumper;

    Player(SDL_Surface *screen);
    void logic();
    void render();
    void jump();
    void perder();
    virtual ~Player();
};

#endif // PLAYER_H
