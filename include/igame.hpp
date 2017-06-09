/*
** igame.hpp for igame in /home/lat/nibbler/src
** 
** Made by mauhoi wu
** Login   <wu_d@epitech.net>
** 
** Started on  Wed Mar  5 15:55:04 2014 mauhoi wu
** Last update Sun Apr  6 00:08:35 2014 mauhoi wu
*/

#ifndef IGAME_HPP_
# define IGAME_HPP_

#include "config.hpp"
#include "snake.hpp"
#include "player.hpp"
#include "body.hpp"
#include "point.hpp"
#include "exception.hpp"

class	IGame {
public:
  virtual ~IGame() {};
  virtual bool		Run() = 0;
  virtual const Config	*getConfig() const = 0;
  virtual const Snake	*getSnake() const = 0;
  virtual const Player	*getPlayer() const = 0;
  virtual const Point	*getPoint() const = 0;
  virtual void		keyLeft() const = 0;
  virtual void		keyRight() const = 0;
};

#endif /* !IGAME_HPP_ */
