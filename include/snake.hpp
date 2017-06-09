/*
** snake.hpp for snake in /home/lat/cpp_nibbler/src
** 
** Made by mauhoi wu
** Login   <wu_d@epitech.net>
** 
** Started on  Tue Mar 25 16:53:21 2014 mauhoi wu
** Last update Sun Apr  6 18:16:58 2014 mauhoi wu
*/

#ifndef SNAKE_HPP_
# define SNAKE_HPP_

#include <stdlib.h>
#include <list>
#include "body.hpp"
#include "define.hpp"

class	Snake {
protected:
  std::list<Body>	*_body;
  int		_length;
  char		_sens;

public:
  Snake(int, int);
  virtual ~Snake() {};
  std::list<Body>	*getBodies() const;
  void		setLength(int);
  int		getLength() const;
  void		addLength();
  void		resetLength();
  void		subLength();
  int		getX();
  int		getY();
  bool		checkTouchBody();
  char		getSens();
  void		setSens(char);
  void		moveSnake();
  Snake		*operator=(const Snake&);
};

#endif /* !SNAKE_HPP_ */
