/*
** body.cpp for body in /home/lat/cpp_nibbler
** 
** Made by mauhoi wu
** Login   <wu_d@epitech.net>
** 
** Started on  Sat Apr  5 23:07:35 2014 mauhoi wu
** Last update Sun Apr  6 00:29:41 2014 mauhoi wu
*/

#include "body.hpp"

Body::Body() : _x(0), _y(0) {
}

Body::~Body() {
}

void	Body::setXY(int y, int x) {
  this->_y = y;
  this->_x = x;
}

int	Body::getX() {
  return (this->_x);
}

int	Body::getY() {
  return (this->_y);
}

Body&	Body::operator=(const Body &rhs) {
  this->_x = rhs._x;
  this->_y = rhs._y;
  return (*this);
}
