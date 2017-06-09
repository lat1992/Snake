/*
** point.cpp for point in /home/lat/cpp_nibbler
** 
** Made by mauhoi wu
** Login   <wu_d@epitech.net>
** 
** Started on  Sat Apr  5 19:30:48 2014 mauhoi wu
** Last update Sun Apr  6 04:12:07 2014 mauhoi wu
*/

#include <point.hpp>

Point::Point() : _x(0), _y(0), _exist(false) {
}

Point::~Point() {
}

int		Point::getX() {
  return (this->_x);
}

int		Point::getY() {
  return (this->_y);
}

void		Point::setPoint(int y, int x) {
  this->_x = x;
  this->_y = y;
}

bool		Point::isExist() {
  return (this->_exist);
}

void		Point::turnExist() {
  if (this->_exist)
    this->_exist = false;
  else
    this->_exist = true;
}
