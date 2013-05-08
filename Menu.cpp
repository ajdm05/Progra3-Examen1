#include "Menu.h"

Menu::Menu(SDL_Surface *screen)
{
    this->screen = screen;
    this->images[0] = IMG_Load( "menu/todo.png" );
    this->images[1] = IMG_Load( "menu/selec.png" );
    this->x = 0;
}

Menu::~Menu()
{
    SDL_FreeSurface( images[0] );
    SDL_FreeSurface( images[1] );
}

void Menu::render()
{
    /*SDL_Rect offset;

    if(x<-images[0]->w)
        x=0;
    offset.x = x;
    offset.y = 0;

    SDL_BlitSurface( images[0], NULL, screen, &offset );

    offset.x = x+images[0]->w;
    offset.y = 0;*/

    SDL_Rect offset;

    offset.x = 0;
    offset.y = 0;
    SDL_BlitSurface( images[0], NULL, screen, &offset );
}

void Menu::logic()
{
    x--;
}
