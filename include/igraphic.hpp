/*
** igraphic.hpp for igraphic in /home/lat/cpp_nibbler/src
** 
** Made by mauhoi wu
** Login   <wu_d@epitech.net>
** 
** Started on  Wed Mar 26 02:43:05 2014 mauhoi wu
// Last update Sun Apr  6 04:33:34 2014 tsai guillaume
*/

#ifndef IGRAPHIC_HPP_
# define IGRAPHIC_HPP_

#include <iostream>
#include "game.hpp"

class	IGraphic {
public:
  virtual ~IGraphic() {};
  virtual void	init(Game *) = 0;
  virtual void	displayMap(Game *) = 0;
  virtual void	displayPlayer(Game *) = 0;
  virtual void	wait(int) = 0;
  virtual bool	keyEvent(Game *) = 0;
};

typedef IGraphic	*(*maker_lib)();

#endif /* !IGRAPHIC_HPP_ */
