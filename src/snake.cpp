/*
** snake.cpp for snake in /home/lat/cpp_nibbler/src
** 
** Made by mauhoi wu
** Login   <wu_d@epitech.net>
** 
** Started on  Tue Mar 25 16:57:29 2014 mauhoi wu
** Last update Sun Apr  6 18:18:46 2014 mauhoi wu
*/

#include "snake.hpp"
#include <iostream>

Snake::Snake(int x, int y) : _length(4), _sens(DOWN) {
  Body	body;
  this->_body = new std::list<Body>();
  int	i;

  body._y = y / 2;
  body._x = x / 2 - 3;
  while (body._y >= y / 2 - 3)
    {
      this->_body->push_back(body);
      body._y--;
    }
}

std::list<Body>		*Snake::getBodies() const {
  return (this->_body);
}

void	Snake::setLength(int l) {
  this->_length = l;
}

int	Snake::getLength() const {
  return (this->_length);
}

void	Snake::addLength() {
  this->_length++;
  Body	body;
  std::list<Body>::iterator	i;

  i = this->_body->end();
  body._y = (*i)._y;
  body._x = (*i)._x;
  moveSnake();
  this->_body->push_back(body);
}

void	Snake::resetLength() {
  this->_length = 4;
}

void	Snake::subLength() {
  this->_length--;
}

int	Snake::getX() {
  std::list<Body>::iterator	i;

  i = this->_body->begin();
  return ((*i)._x);
}

int	Snake::getY() {
  std::list<Body>::iterator	i;

  i = this->_body->begin();
  return ((*i)._y);
}

char	Snake::getSens() {
  return (this->_sens);
}

void	Snake::setSens(char s) {
  this->_sens = s;
}

bool	Snake::checkTouchBody() {
  std::list<Body>::iterator	i;
  std::list<Body>::iterator	j;

  i = this->_body->begin();
  j = this->_body->begin();
  j++;
  if (this->_sens == UP)
    {
      while (j != this->_body->end())
	{
	  if ((*i)._y - 1 == (*j)._y && (*i)._x == (*j)._x)
	    return (false);
	  j++;
	}
    }
  else if (this->_sens == DOWN)
    {
      while (j != this->_body->end())
	{
	  if ((*i)._y + 1 == (*j)._y && (*i)._x == (*j)._x)
	    return (false);
	  j++;
	}
    }
  else if (this->_sens == LEFT)
    {
      while (j != this->_body->end())
	{
	  if ((*i)._y == (*j)._y && (*i)._x - 1 == (*j)._x)
	    return (false);
	  j++;
	}
    }
  else if (this->_sens == RIGHT)
    {
      while (j != this->_body->end())
	{
	  if ((*i)._y == (*j)._y && (*i)._x + 1 == (*j)._x)
	    return (false);
	  j++;
	}
    }
  return (true);
}

void	Snake::moveSnake() {
  std::list<Body>::iterator	i;
  Body				tmp;

  i = this->_body->end();
  this->_body->erase(--i);
  i = this->_body->begin();
  if (this->_sens == UP)
    {
      tmp._x = (*i)._x;
      tmp._y = (*i)._y - 1;
      this->_body->push_front(tmp);
    }
  else if (this->_sens == DOWN)
    {
      tmp._x = (*i)._x;
      tmp._y = (*i)._y + 1;
      this->_body->push_front(tmp);
    }
  else if (this->_sens == LEFT)
    {
      tmp._x = (*i)._x - 1;
      tmp._y = (*i)._y;
      this->_body->push_front(tmp);
    }
  else if (this->_sens == RIGHT)
    {
      tmp._x = (*i)._x + 1;
      tmp._y = (*i)._y;
      this->_body->push_front(tmp);
    }
}

Snake	*Snake::operator=(const Snake& other) {
  Snake	*tmp;

  tmp = new Snake(other);
  return (tmp);
}
