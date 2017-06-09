/*
** game.cpp for game in /home/lat/cpp_nibbler/src
** 
** Made by mauhoi wu
** Login   <wu_d@epitech.net>
** 
** Started on  Wed Mar 26 02:13:30 2014 mauhoi wu
** Last update Sun Apr  6 18:17:25 2014 mauhoi wu
*/

#include "game.hpp"

Game::Game() {
  this->_config = new Config();
  this->_snake = new Snake(0, 0);
  this->_player = new Player();
  this->_point = new Point();
}

Game::Game(int y, int x, char *lib) {
  srand(time(NULL));
  this->_config = new Config(x, y, lib);
  this->_snake = new Snake(x, y);
  this->_player = new Player();
  this->_point = new Point();
}

Game::Game(int y, int x, char *lib, char *name) {
  srand(time(NULL));
  this->_config = new Config(x, y, lib);
  this->_snake = new Snake(x, y);
  this->_player = new Player(name);
  this->_point = new Point();
}

Game::~Game() {
  delete this->_config;
  delete this->_player;
  delete this->_point;
  delete this->_snake;
}

bool		Game::Run() {
  if (!this->_point->isExist())
    {
      this->_point->setPoint(rand() % this->_config->getY(), rand() % this->_config->getX());
      this->_point->turnExist();
    }
  if (!this->_snake->checkTouchBody())
    {
      std::cout << "body ! " << this->_player->getName() << " have " << this->_player->getScore() << " points." << std::endl;
      return (false);
    }
  this->_snake->moveSnake();
  if (this->_snake->getY() == this->_point->getY() && this->_snake->getX()== this->_point->getX())
    {
      this->_snake->addLength();
      this->_player->addScore();
      this->_point->turnExist();
    }
  if (this->_snake->getX() < 0 || this->_snake->getX() >= this->_config->getX()
      || this->_snake->getY() < 0 || this->_snake->getY() >= this->_config->getY())
    {
      std::cout << "wall ! " << this->_player->getName() << " have " << this->_player->getScore() << " points." << std::endl;
      return (false);
    }
  return (true);
}

const Config	*Game::getConfig() const {
  return (this->_config);
}

const Snake	*Game::getSnake() const {
  return (this->_snake);
}

const Player	*Game::getPlayer() const {
  return (this->_player);
}

Point		*Game::getPoint() const {
  return (this->_point);
}

void		Game::keyLeft() const {
  if (this->_snake->getSens() == UP)
    this->_snake->setSens(LEFT);
  else if (this->_snake->getSens() == DOWN)
    this->_snake->setSens(RIGHT);
  else if (this->_snake->getSens() == LEFT)
    this->_snake->setSens(DOWN);
  else if (this->_snake->getSens() == RIGHT)
    this->_snake->setSens(UP);
}

void		Game::keyRight() const {
  if (this->_snake->getSens() == UP)
    this->_snake->setSens(RIGHT);
  else if (this->_snake->getSens() == DOWN)
    this->_snake->setSens(LEFT);
  else if (this->_snake->getSens() == LEFT)
    this->_snake->setSens(UP);
  else if (this->_snake->getSens() == RIGHT)
    this->_snake->setSens(DOWN);
}
