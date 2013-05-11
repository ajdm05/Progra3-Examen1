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

std::string toString(int number)
{
    if (number == 0)
        return "0";
    std::string temp="";
    std::string returnvalue="";
    while (number>0)
    {
        temp+=number%10+48;
        number/=10;
    }
    for (int i=0;i<(int)temp.length();i++)
        returnvalue+=temp[temp.length()-i-1];
    return returnvalue;
}

bool init()
{
    //Initialize SDL_mixer
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;
    }

    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;
    }

    //If everything initialized fine
    return true;
}

int main( int argc, char* args[] )
{
    //Initialize
    init();
    Screen game;
    int score = 0;
    game.init();
    int random;
    srand(time(NULL));

    game.update=new Timer();
    game.update->start();
    Mix_Chunk *pantalla = Mix_LoadWAV( "pantalla.wav" );

    TTF_Font *font = TTF_OpenFont( "letra.ttf", 35 );
    SDL_Color textColor = { 0, 0, 0 };
    SDL_Surface * score_surface = NULL;


    SDL_Surface * game_over = IMG_Load( "game_over.png" );


    Background background(game.getScreen());
    background.setNumPantalla(0);
    Player player(game.getScreen());
    Enemy enemy(game.getScreen());
    Llama llama(game.getScreen());


    SDL_Event event;
    Mix_PlayChannel( -1, pantalla, 5 );
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
                    case SDLK_0:
                        background.setNumPantalla(0);
                        break;
                    case SDLK_1:
                        background.setNumPantalla(1);
                        break;
                    case SDLK_2:
                        background.setNumPantalla(2);
                        break;
                    case SDLK_3:
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


        background.logic();
        player.isJump();
        if (background.getNumPantalla() == 1){

            game.update;
            player.logic();
            player.isJump();
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

        SDL_Surface * score_surface = TTF_RenderText_Solid( font, toString(score+=5).c_str(), textColor );
        SDL_BlitSurface( score_surface, NULL, game.getScreen(), &game.offset );
        SDL_Flip(game.getScreen());
        //SDL_FreeSurface( score_surface );

        background.render();
        player.isJump();
        if (background.getNumPantalla() == 1)
        {
            player.isJump();
            player.render();
                enemy.render();
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
                    case SDLK_0:
                        background.setNumPantalla(0);
                        break;
                    case SDLK_3:

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
