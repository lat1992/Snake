/*
** config.hpp for config in /home/lat/cpp_nibbler
** 
** Made by mauhoi wu
** Login   <wu_d@epitech.net>
** 
** Started on  Tue Mar 25 16:28:49 2014 mauhoi wu
** Last update Thu Apr  3 10:48:30 2014 mauhoi wu
*/

#ifndef CONFIG_HPP_
# define CONFIG_HPP_

#include <dlfcn.h>
#include <iostream>
#include <string>
#include <cstring>
#include "exception.hpp"

# define MIN 40
# define MAX_X 1280 / 10
# define MAX_Y 720 / 10

class		Config {
protected:
  int		_x;
  int		_y;
  std::string	_lib;

public:
  Config();
  Config(int, int, char *);
  virtual ~Config() {};

  int		getX() const;
  int		getY() const;
  std::string	getLib() const;
  void		check_size();
  Config	*operator=(const Config&);
};

#endif /* !CONFIG_HPP_ */
