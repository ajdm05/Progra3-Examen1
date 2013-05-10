#include "Background.h"
#include <string>

Background::Background(SDL_Surface *screen)
{
    this->screen = screen;
    this->image[0] = IMG_Load( "menu/todo.png" );
    this->image[1] = IMG_Load( "background.png" );
    this->image[2] = IMG_Load( "menu/menuInfo.png" );
    this->x = 0;
    this->numPantalla = 0;
    this->score = 0;
}

Background::~Background()
{
    SDL_FreeSurface( image[0] );
    SDL_FreeSurface( image[1] );
    SDL_FreeSurface( image[2] );
}

void Background::logic()
{
        x--;
}

void Background::render()
{
    SDL_Rect offset;

    if (this->getNumPantalla() == 0){

        x = -1000;
        if(x<-image[0]->w)
        x=0;
        offset.x = x;
        offset.y = 0;


        SDL_BlitSurface( image[0], NULL, screen, &offset );

        offset.x = x+image[0]->w;
        offset.y = 0;

        SDL_BlitSurface( image[0], NULL, screen, &offset );
    }

    if (this->getNumPantalla() == 1)
    {
        x = -1000;
        if(x<-image[1]->w)
            x=0;
        offset.x = x;
        offset.y = 0;

        SDL_BlitSurface( image[1], NULL, screen, &offset );

        offset.x = x+image[1]->w;
        offset.y = 0;

        SDL_BlitSurface( image[1], NULL, screen, &offset );

    }
    if (this->getNumPantalla() == 2)
    {
        x = -1000;
        if(x<-image[2]->w)
            x=0;
        offset.x = x;
        offset.y = 0;

        SDL_BlitSurface( image[2], NULL, screen, &offset );

        offset.x = x+image[2]->w;
        offset.y = 0;

        SDL_BlitSurface( image[2], NULL, screen, &offset );
    }

}

void Background::setNumPantalla(int p)
{
    this->numPantalla = p;
}

int Background::getNumPantalla()
{

    return this->numPantalla;
}


bool Background::init()
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
}



