/*
// opengl_core.cpp for  in /home/kramp_a/rendu/cpp_nibbler
// 
// Made by godwin
// Login   <kramp_a@epitech.net>
// 
// Started on  Sun Apr  6 13:27:30 2014 godwin
** Last update Sun Apr  6 18:36:20 2014 mauhoi wu
//
*/

#include "opengl_core.hpp"

Opengl_Core::Opengl_Core()
{
}

Opengl_Core::~Opengl_Core()
{
}

void		Opengl_Core::init_OpenGL()
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    throw Exception("SDL_Init failed.");
  SDL_WM_SetCaption("Nibbler OpenGL", NULL);

  if ((this->screen = SDL_SetVideoMode(this->_winX * BLOCK_SIZE,
				       this->_winY * BLOCK_SIZE,
				       32, SDL_OPENGL)) == NULL)
    throw Exception("SDL_SetVideoMode failed.");
}

void		Opengl_Core::initAff()
{
  glClearColor(0, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  glViewport(0, 0, this->_winX * BLOCK_SIZE,
  	     this->_winY * BLOCK_SIZE);
  glOrtho(0, this->_winX, this->_winY, 0, -1, 1);
}

void		Opengl_Core::init(Game *game)
{
  this->_winX = game->getConfig()->getX();
  this->_winY = game->getConfig()->getY();
  this->init_OpenGL();
  this->initAff();
  SDL_GL_SwapBuffers();
}

void		Opengl_Core::drawSquare(int pos_x, int pos_y,
					float red, float green, float blue)
{
  glColor3f(red, green, blue);
  glBegin(GL_POLYGON);
  if (glGetError() != GL_NO_ERROR)
    throw Exception("glBegin failed.");
  glVertex2f(pos_x, pos_y);
  glVertex2f(pos_x + 0.9, pos_y);
  glVertex2f(pos_x + 0.9, pos_y + 0.9);
  glVertex2f(pos_x, pos_y + 0.9);
  glEnd();
  if (glGetError() != GL_INVALID_OPERATION)
    throw Exception("glEnd failed.");
}

void		Opengl_Core::displayMap(Game *game)
{
  std::list<Body>::iterator     i = game->getSnake()->getBodies()->begin();

  glClearColor(0, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  this->drawSquare(game->getPoint()->getX(), game->getPoint()->getY(),
		   0, 1, 0);
  while (i != game->getSnake()->getBodies()->end())
    {
      this->drawSquare(i->getX(), i->getY(), 1, 0, 0);
      i++;
    }
  SDL_GL_SwapBuffers();
}

void		Opengl_Core::displayPlayer(Game *game)
{
}

void		Opengl_Core::wait(int wait)
{
  usleep(wait);
}

bool		Opengl_Core::keyEvent(Game *game)
{
  SDL_Event     event;

  SDL_PollEvent(&event);
  if (event.type == SDL_KEYDOWN)
    {
      switch (event.key.keysym.sym)
        {
        case SDLK_ESCAPE:
	  SDL_Quit();
	  return (false);
          break;
        case SDLK_LEFT:
          game->keyLeft();
	  return (true);
          break;
        case SDLK_RIGHT:
          game->keyRight();
	  return (true);
          break;
        }
    }
  while (SDL_PollEvent(&event));
  return (true);
}

extern "C" {
  Opengl_Core	*load_graphic()
  {
    return new Opengl_Core();
  }
}
