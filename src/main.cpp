/*
// main.cpp for  in /home/tsai_g/tsai/nibbler/src
// 
// Made by tsai guillaume
// Login   <tsai_g@epitech.net>
// 
// Started on  Mon Mar 17 14:10:44 2014 tsai guillaume
** Last update Sun Apr  6 04:46:53 2014 mauhoi wu
*/

#include <iostream>
#include <sstream>
#include <string>
#include <dlfcn.h>
#include "game.hpp"
#include "exception.hpp"
#include "igraphic.hpp"

int			my_atoi(const std::string& String)
{
  int			i;
  std::stringstream	ss(String);

  ss >> i;
  return (i);
}

void			execute(Game *game)
{
  void			*handle;
  maker_lib		pMaker;

  handle = dlopen(game->getConfig()->getLib().data(), RTLD_LAZY);
  std::cout << game->getConfig()->getLib().data() << std::endl;
  if (handle)
    {
      void *mkr = dlsym(handle, "load_graphic");
      if (mkr)
        {
          pMaker = (maker_lib)mkr;
          IGraphic  *graphic = pMaker();
	  graphic->init(game);
	  while (42)
	    {
	      if (!game->Run())
		return ;
	      graphic->displayMap(game);
	      graphic->displayPlayer(game);
	      if (graphic->keyEvent(game) == false)
		{
		  std::cout << "rage quit !" << std::endl;
		  return ;
		}
	      graphic->wait(50000);
	    }
        }
    }
  throw Exception(dlerror());
}

int			main(int ac, char **av, char **env)
{
  Game			*game;

  try
    {
      if (ac == 4 && env[0])
	game = new Game(my_atoi(av[1]), my_atoi(av[2]), av[3]);
      else if (ac == 5 && env[0])
	game = new Game(my_atoi(av[1]), my_atoi(av[2]), av[3], av[4]);
      else
	throw Exception("Usage : ./nibbler size_x size_y ./lib [user name]");
      execute(game);
    }
  catch (const Exception &e)
    {
      std::cout << "Une erreur est survenue :" << std::endl;
      std::cout << e.what() << std::endl;
    }
  return (0);
}
