/*
** player.cpp for player in /home/lat/cpp_nibbler/src
** 
** Made by mauhoi wu
** Login   <wu_d@epitech.net>
** 
** Started on  Wed Mar 26 02:37:58 2014 mauhoi wu
** Last update Sun Apr  6 06:21:04 2014 mauhoi wu
*/

#include "player.hpp"

Player::Player() : _name("player"), _score(0) {
}

Player::Player(char *name) : _name(name), _score(0) {
}

const std::string	&Player::getName() const {
  return (this->_name);
}

int			Player::getScore() const {
  return (this->_score);
}

void			Player::addScore() {
  this->_score++;
}

void			Player::addScore(int s) {
  this->_score += s;
}

void			Player::setScore(int s) {
  this->_score = s;
}
