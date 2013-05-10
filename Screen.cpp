#include "Screen.h"

Screen::Screen()
{
    pantalla = NULL;
    //ctor
}

Screen::~Screen()
{
    delete this->pantalla;

}

bool Screen::init()
{
    /*if( TTF_Init() == -1 )
    {
        return false;
    }*/



    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    pantalla = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //Set the window caption
    SDL_WM_SetCaption( "SDL Runner Lab Progra 3", NULL );

    //If everything initialized fine
    return true;
}


void Screen::frameCap()
{
    int frames_per_seccond = 15;
    if(update->get_ticks() < 1000 / frames_per_seccond)
    {
        //Sleep the remaining frame time
        SDL_Delay( ( 1000 / frames_per_seccond ) - update->get_ticks() );
    }
    update->start();
}


SDL_Surface* Screen::getScreen()
{

    return this->pantalla;
}


