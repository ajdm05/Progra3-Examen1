#include "Background.h"
#include <string>

Background::Background(SDL_Surface *screen)
{
    this->screen = screen;
    this->image[0] = IMG_Load( "menu/todo.png" );
    this->image[1] = IMG_Load( "background.png" );
    this->x = 0;
    this->numPantalla = 0;
    this->score = 0;
}

Background::~Background()
{
    SDL_FreeSurface( image[0] );
    SDL_FreeSurface( image[1] );
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
    } else if (this->getNumPantalla() == 1)
    {

        if(x<-image[1]->w)
            x=0;
        offset.x = x;
        offset.y = 0;

        SDL_BlitSurface( image[1], NULL, screen, &offset );

        offset.x = x+image[1]->w;
        offset.y = 0;

        SDL_BlitSurface( image[1], NULL, screen, &offset );

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

/*void Background::getScore(SDL_Surface *screen)
{

    TTF_Font *font = TTF_OpenFont( "lazy.ttf", 35 );
    SDL_Color textColor = { 0, 0, 0 };
    //SDL_Surface * score_surface = NULL;

    SDL_Surface * score_surface = TTF_RenderText_Solid( font, toString(score+=5).c_str(), textColor );
    SDL_BlitSurface( score_surface, NULL, screen, &offset );
    SDL_Flip(screen);
    SDL_FreeSurface( score_surface );

}

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
}*/
