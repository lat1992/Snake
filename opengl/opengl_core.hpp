/*
// opengl_core.hpp for  in /home/kramp_a/rendu/cpp_nibbler/opengl
// 
// Made by godwin
// Login   <kramp_a@epitech.net>
// 
// Started on  Wed Apr  2 22:02:34 2014 godwin
// Last update Sun Apr  6 17:55:19 2014 godwin
*/

#ifndef OPENGL_CORE_HPP_
# define OPENGL_CORE_HPP_

# define WIN_X	        500
# define WIN_Y	        500
# define BLOCK_SIZE	10

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <map>
#include "igraphic.hpp"

class	Opengl_Core : public IGraphic
{
private:
  SDL_Surface           *screen;
  int			size_x;
  int			size_y;

  void			init_OpenGL();
  void			initAff();
  void		        drawSquare(int pos_x, int pos_y,
				   float red, float green, float blue);

protected:
  int			_winX;
  int			_winY;

public:
  Opengl_Core();
  ~Opengl_Core();
  virtual void  init(Game *);
  virtual void  displayMap(Game *);
  virtual void  displayPlayer(Game *);
  virtual bool  keyEvent(Game *);
  virtual void  wait(int);
};

#endif /* !OPENGL_CORE_HPP_ */
