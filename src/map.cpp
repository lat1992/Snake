/*
** map.cpp for map in /home/lat/cpp_nibbler/src
** 
** Made by mauhoi wu
** Login   <wu_d@epitech.net>
** 
** Started on  Wed Mar 26 02:52:30 2014 mauhoi wu
** Last update Sat Apr  5 19:05:13 2014 mauhoi wu
*/

#include "map.hpp"
#include <iostream>

Map::Map() {
}

Map::Map(int y, int x) {
  int	i;
  int	j;

  j = 0;
  while (j < y)
    {
      i = 0;
      while (i < x)
	{
	  this->_map[P(j, i)] = VOID;
	  i++;
	}
      j++;
    }
}

std::map<std::pair<int, int>, char>	Map::getMap() const {
  return (this->_map);
}

bool				Map::setElem(int y, int x, char elem) {
  if (this->_map[P(y, x)] == VOID)
    {
      this->_map[P(y, x)] = elem;
      return (true);
    }
  return (false);
}

bool				Map::setVoid(int y, int x) {
  if (this->_map[P(y, x)])
    {
      this->_map[P(y, x)] = VOID;
      return (true);
    }
  return (false);
}

bool				Map::checkElemInMap(int y, int x, char elem) {
  int				i;
  int				j;

  j = 0;
  while (j < y)
    {
      i = 0;
      while (i < x)
	{
	  if (this->_map[P(j, i)] == elem)
	    return (true);
	  i++;
	}
      j++;
    }
  return (false);
}

void				Map::dump(int y, int x) {
  int				j;
  int				i;

  j = 0;
  while (j < y)
    {
      i = 0;
      while (i < x)
	{
	  std::cout << this->_map[P(j, i)];
	  i++;
	}
      std::cout << std::endl;
      j++;
    }
}

void				Map::choseSens(char *o, char s) {
  if (s == UP)
    *o = DOWN;
  else if (s == DOWN)
    *o = UP;
  else if (s == LEFT)
    *o = RIGHT;
  else if (s == RIGHT)
    *o = LEFT;
  return ;
}

bool				Map::buffMap(int y, int x, const Snake *snake) {
  int				i;
  int				j;
  int				l;
  char				sens;

  j = snake->getY();
  i = snake->getX();
  l = 0;
  choseSens(&sens, snake->getSens());
  while (l < snake->getLength())
    {
      if (sens == UP)
	j--;
      else if (sens == DOWN)
	j++;
      else if (sens == LEFT)
	i--;
      else if (sens == RIGHT)
	i++;
      choseSens(&sens, this->_map[P(j, i)]);
      if (this->_map[P(j, i)] == VOID)
	this->_map[P(j, i)] = SNAKE;
      l++;
    }
  if (this->_map[P(y - 1, i)] != VOID && this->_map[P(j - 1, i)] != POINT)
    this->_map[P(j - 1, i)] = VOID;
  else if (this->_map[P(j, i - 1)] != VOID && this->_map[P(j, i - 1)] != POINT)
    this->_map[P(j, i - 1)] = VOID;
  else if (this->_map[P(j + 1, i)] != VOID && this->_map[P(j + 1, i)] != POINT && j + 1 < y)
    this->_map[P(j + 1, i)] = VOID;
  else if (this->_map[P(j, i + 1)] != VOID && this->_map[P(j, i + 1)] != POINT && i + 1 < x)
    this->_map[P(j, i + 1)] = VOID;
  return (true);
}
