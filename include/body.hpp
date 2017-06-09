/*
** body.hpp for body in /home/lat/cpp_nibbler
** 
** Made by mauhoi wu
** Login   <wu_d@epitech.net>
** 
** Started on  Sat Apr  5 23:04:51 2014 mauhoi wu
** Last update Sun Apr  6 00:29:55 2014 mauhoi wu
*/

#ifndef BODY_HPP_
# define BODY_HPP_

class	Body {
public:
  int	_x;
  int	_y;

public:
  Body();
  virtual ~Body();
  void	setXY(int, int);
  int	getX();
  int	getY();
  Body&	operator=(const Body&);
};

#endif /* !BODY_HPP_ */
