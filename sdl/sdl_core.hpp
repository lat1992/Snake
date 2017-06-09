/*
// core.hpp for  in /home/tsai_g/rendu/2B/core
// 
// Made by tsai guillaume
// Login   <tsai_g@epitech.net>
// 
// Started on  Wed Mar 19 02:57:48 2014 tsai guillaume
** Last update Sun Apr  6 05:53:47 2014 mauhoi wu
*/

#ifndef SDL_CORE_HPP_
# define SDL_CORE_HPP_

# define BLOCK_SIZE	10

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "igraphic.hpp"

class	SDL_Core : public IGraphic {
protected:
  SDL_Surface		*_screen;
  SDL_Surface		*_body;
  SDL_Surface		*_point;
  TTF_Font		*_font;
  int			_winX;
  int			_winY;

public:
  SDL_Core();
  virtual ~SDL_Core() {};

  virtual void		init(Game *);
  virtual void		displayMap(Game *);
  virtual void		displayPlayer(Game *);
  virtual bool		keyEvent(Game *);
  virtual void		wait(int);
};

#endif /* !SDL_CORE_HPP_ */
