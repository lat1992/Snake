/*
** player.hpp for player in /home/lat/cpp_nibbler/src
** 
** Made by mauhoi wu
** Login   <wu_d@epitech.net>
** 
** Started on  Wed Mar 26 02:31:44 2014 mauhoi wu
** Last update Sun Apr  6 06:21:20 2014 mauhoi wu
*/

#ifndef PLAYER_HPP_
# define PLAYER_HPP_

#include <string>

class		Player {
protected:
  std::string	_name;
  int		_score;

public:
  Player();
  Player(char *);
  virtual ~Player() {};
  const	std::string	&getName() const;
  int			getScore() const;
  void			addScore();
  void			addScore(int);
  void			setScore(int);
};

#endif /* !PLAYER_HPP_ */
