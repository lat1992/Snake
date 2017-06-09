/*
** config.cpp for config in /home/lat/cpp_nibbler
** 
** Made by mauhoi wu
** Login   <wu_d@epitech.net>
** 
** Started on  Tue Mar 25 16:37:07 2014 mauhoi wu
** Last update Thu Apr  3 17:13:02 2014 mauhoi wu
*/

#include "config.hpp"

Config::Config() : _x(0), _y(0), _lib("") {
}

Config::Config(int x, int y, char *lib) : _x(x), _y(y), _lib(lib) {
  check_size();
}

int		Config::getX() const {
  return (this->_x);
}

int		Config::getY() const {
  return (this->_y);
}

std::string	Config::getLib() const {
  return (this->_lib);
}

void		Config::check_size() {
  if (this->_x < MIN || this->_x > MAX_X || this->_y < MIN || this->_y > MAX_Y)
    throw Exception("Bad sizes");
}

Config		*Config::operator=(const Config& other) {
  Config	*tmp;

  tmp = new Config(other);
  return (tmp);
}
