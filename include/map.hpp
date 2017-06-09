/*
** map.hpp for map in /home/lat/cpp_nibbler/src
** 
** Made by mauhoi wu
** Login   <wu_d@epitech.net>
** 
** Started on  Wed Mar 26 02:45:49 2014 mauhoi wu
** Last update Sat Apr  5 19:05:26 2014 mauhoi wu
*/

#ifndef MAP_HPP_
# define MAP_HPP_

#include <string>
#include <map>
#include <utility>
#include <stdlib.h>
#include "exception.hpp"
#include "define.hpp"
#include "snake.hpp"

class	Map {
protected:
  std::map<std::pair<int, int>, char>	_map;

public:
  Map();
  Map(int, int);
  virtual ~Map() {};
  std::map<std::pair<int, int>, char>	getMap() const;
  bool					setElem(int, int, char);
  bool					setVoid(int, int);
  bool					checkElemInMap(int, int, char);
  void					choseSens(char *o, char s);
  void					dump(int, int);
  bool					buffMap(int, int, const Snake *);
};

#endif /* !MAP_HPP_ */
