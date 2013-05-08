/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/

//The headers
#include "SDL.h"
#include "SDL_image.h"
#include "Background.h"
#include "Player.h"
#include "Enemy.h"
#include "Timer.h"
#include "Llama.h"
#include <string>
#include "Screen.h"
#include<time.h>
#include <iostream>


using namespace std;


int main( int argc, char* args[] )
{
    //Initialize
    Screen game;

    game.init();
    int random;
    srand(time(NULL));

    game.update=new Timer();
    game.update->start();

    SDL_Surface * game_over = IMG_Load( "game_over.png" );


    Background background(game.getScreen());
    background.setNumPantalla(0);
    Player player(game.getScreen());
    Enemy enemy(game.getScreen());
    Llama llama(game.getScreen());
    //background.getScore(game.getScreen());

    SDL_Event event;
    //Quit flag
    bool quit = false;
    while( quit == false )
    {
        //If there's an event to handle
        if( SDL_PollEvent( &event ) )
        {
            //If a key was pressed
            if( event.type == SDL_KEYDOWN )
            {
                //Set the proper message surface
                switch( event.key.keysym.sym )
                {
                    case SDLK_ESCAPE: quit = true; break;
                    case SDLK_1:
                        background.setNumPantalla(1);
                        break;
                    case SDLK_3:
                        background.setNumPantalla(3);
                        quit = true;
                        break;

                    case SDLK_UP:
                        if (! player.isJumping){
                            player.jump(); break;
                        }
                }
            }
            //If the user has Xed out the window
            else if( event.type == SDL_QUIT )
            {
                //Quit the program
                 quit = true;
            }
        }


        background.logic();
        if (background.getNumPantalla() == 1){
            player.logic();
            random = rand() % 2;
            if (random == 0)
                enemy.logic();
            if (random == 1)
                llama.logic();
            player.perdio(enemy.x, enemy.y);
            player.perdio(llama.x, llama.y);
            if (player.murio){
                break;
            }

        }


        background.render();
        if (background.getNumPantalla() == 1)
        {
            player.render();
            if(random == 0)
                enemy.render();
            if (random == 1)
                llama.render();
        }

        game.frameCap();

        //Update the screen
        if( SDL_Flip( game.getScreen() ) == -1 )
        {
            return 1;
        }


    }

    while( quit == false )
    {
        //If there's an event to handle
        if( SDL_PollEvent( &event ) )
        {
            //If a key was pressed
            if( event.type == SDL_KEYDOWN )
            {
                //Set the proper message surface
                switch( event.key.keysym.sym )
                {
                    case SDLK_ESCAPE: quit = true; break;
                    case SDLK_1:
                        background.setNumPantalla(1);
                        break;
                    case SDLK_3:
                        background.setNumPantalla(3);
                        quit = true;
                        break;
                }
            }
            //If the user has Xed out the window
            else if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }

        SDL_Rect offset;
        game.offset.x = 0;
        game.offset.y = 0;


        SDL_BlitSurface( game_over, NULL, game.getScreen(), &game.offset );

        game.frameCap();

//        Update the screen
        if( SDL_Flip( game.getScreen() ) == -1 )
        {
            return 1;
        }
    }

    SDL_Quit();

    return 0;
}
