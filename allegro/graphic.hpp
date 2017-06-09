/*
** graphic.hpp for graphic in /home/lat/cpp_nibbler/allegro
** 
** Made by mauhoi wu
** Login   <wu_d@epitech.net>
** 
** Started on  Wed Apr  2 14:41:11 2014 mauhoi wu
** Last update Sun Apr  6 06:20:36 2014 mauhoi wu
*/

#ifndef GRAPHIC_HPP_
# define GRAPHIC_HPP_

#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "igraphic.hpp"
#include "game.hpp"
#include "exception.hpp"

# define BLOCK	10

class	Graphic : public IGraphic {
protected:
  ALLEGRO_DISPLAY	*display;
  ALLEGRO_COLOR		_whiteColor;
  ALLEGRO_COLOR		_pointColor;
  ALLEGRO_EVENT_QUEUE	*_eventQueue;
  ALLEGRO_EVENT_QUEUE	*_eventTimerQueue;
  ALLEGRO_TIMER		*_timer;
  ALLEGRO_FONT		*_font;

public:
  Graphic();
  virtual ~Graphic();
  virtual void	init(Game *);
  virtual void	displayMap(Game *);
  virtual void	displayPlayer(Game *);
  virtual void	wait(int);
  virtual bool	keyEvent(Game *);
};

#endif /* !GRAPHIC_HPP_ */
