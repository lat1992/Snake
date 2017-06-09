/*
** game.hpp for game in /home/lat/cpp_nibbler/src
** 
** Made by mauhoi wu
** Login   <wu_d@epitech.net>
** 
** Started on  Wed Mar 26 02:13:38 2014 mauhoi wu
** Last update Sun Apr  6 04:13:32 2014 mauhoi wu
*/

#ifndef GAME_HPP_
# define GAME_HPP_

#include <stdlib.h>
#include <unistd.h>
#include "igame.hpp"
#include "config.hpp"
#include "player.hpp"
#include "body.hpp"
#include "point.hpp"
#include "exception.hpp"
#include "define.hpp"

class	Game : public IGame {
protected:
  Config	*_config;
  Snake		*_snake;
  Player	*_player;
  Point		*_point;

public:
  Game();
  Game(int, int, char *);
  Game(int, int, char *, char *);
  virtual ~Game();

  virtual bool		Run();
  virtual const Config	*getConfig() const;
  virtual const Snake	*getSnake() const;
  virtual const Player	*getPlayer() const;
  virtual Point		*getPoint() const;
  virtual void		keyLeft() const;
  virtual void		keyRight() const;
};

#endif /* !GAME_HPP_ */
