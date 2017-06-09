/*
// sdl_core.cpp for  in /home/tsai_g/rendu/2B/core
// 
// Made by tsai guillaume
// Login   <tsai_g@epitech.net>
// 
// Started on  Wed Mar 19 03:08:36 2014 tsai guillaume
** Last update Sun Apr  6 18:35:21 2014 mauhoi wu
*/

#include "sdl_core.hpp"

SDL_Core::SDL_Core() {
}

bool		SDL_Core::keyEvent(Game *game) {
  SDL_Event	event;

  SDL_PollEvent(&event);
  if (event.type == SDL_KEYDOWN)
    {
      switch (event.key.keysym.sym)
	{
	case SDLK_ESCAPE:
	  SDL_Quit();
	  //	  TTF_Quit();
	  return (false);
	  break;
	case SDLK_LEFT:
	  game->keyLeft();
	  return (true);
	  break;
	case SDLK_RIGHT:
	  game->keyRight();
	  return (true);
	  break;
	}
    }
  else if (event.type == SDL_QUIT)
    {
      SDL_Quit();
      //      TTF_Quit();
      return (false);
    }
  while (SDL_PollEvent(&event));
  return (true);
}

void		SDL_Core::init(Game *game) {
  _winX = game->getConfig()->getX() * BLOCK_SIZE;
  _winY = game->getConfig()->getY() * BLOCK_SIZE;
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    throw Exception("SDL_Init fail");
  /*  if (TTF_Init() == -1)
      throw Exception("TTF_Init fail");*/
  this->_screen = SDL_SetVideoMode(_winX, _winY,
			    32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  this->_body = SDL_LoadBMP("./sdl/body.bmp");
  this->_point = SDL_LoadBMP("./sdl/point.bmp"); 
  //  this->_font = TTF_OpenFont("./sdl/font.ttf", 5);
  if (this->_screen == NULL)
    throw Exception("SDL_SetVideoMode fail");
  SDL_WM_SetCaption("Nibbler SDL", NULL );
}

void		SDL_Core::displayMap(Game *game) {
  SDL_Rect      pos;
  std::list<Body>::iterator     i = game->getSnake()->getBodies()->begin();

  SDL_FillRect(this->_screen, NULL, SDL_MapRGB(this->_screen->format, 0, 0, 0));
  while (i != game->getSnake()->getBodies()->end())
    {
      pos.x = i->getX() * BLOCK_SIZE;
      pos.y = i->getY() * BLOCK_SIZE;
      SDL_BlitSurface(this->_body, NULL, this->_screen, &pos);
      i++;
    }
  pos.x = game->getPoint()->getX() * BLOCK_SIZE;
  pos.y = game->getPoint()->getY() * BLOCK_SIZE;
  SDL_BlitSurface(this->_point, NULL, this->_screen, &pos);
  if (SDL_Flip(this->_screen) == -1)
    throw Exception("SDL_Flip fail");
}

void		SDL_Core::displayPlayer(Game *game) {
  /*  SDL_Color	color = {255, 255, 255};
  SDL_Surface	*txt = TTF_RenderText_Blended(_font, game->getPlayer()->getName().data(), color);
  SDL_Rect      pos;

  pos.x = 0;
  pos.y = 0;
  SDL_BlitSurface(txt, NULL, this->_screen, &pos);*/
}

void		SDL_Core::wait(int time) {
  SDL_Delay(time / 1000);
}

extern "C" {
  SDL_Core	*load_graphic()
  {
    return new SDL_Core();
  }
}
