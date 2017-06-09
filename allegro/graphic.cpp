/*
** graphic.cpp for graphic in /home/lat/cpp_nibbler/allegro
** 
** Made by mauhoi wu
** Login   <wu_d@epitech.net>
** 
** Started on  Wed Apr  2 14:45:14 2014 mauhoi wu
** Last update Sun Apr  6 07:49:46 2014 mauhoi wu
*/

#include "graphic.hpp"

Graphic::Graphic() {
}

Graphic::~Graphic() {
  al_destroy_event_queue(this->_eventTimerQueue);
  al_destroy_event_queue(this->_eventQueue);
  al_destroy_display(this->display);
}

void	Graphic::init(Game *game) {
  if (!al_init())
    throw Exception("allegro init failure");
  al_set_new_display_flags(ALLEGRO_WINDOWED);
  if (!(this->display = al_create_display(game->getConfig()->getX() * BLOCK, game->getConfig()->getY() * BLOCK + 20)))
    throw Exception("allegro display create failure");
  al_set_window_position(this->display, 0, 0);
  al_set_window_title(this->display, "Nibbler Allegro");
  al_init_primitives_addon();
  al_install_keyboard();
  this->_eventTimerQueue = al_create_event_queue();
  this->_timer = al_create_timer(0.1);
  this->_eventQueue = al_create_event_queue();
  al_register_event_source(this->_eventQueue, al_get_display_event_source(this->display));
  al_register_event_source(this->_eventQueue, al_get_keyboard_event_source());
  al_register_event_source(this->_eventTimerQueue, al_get_timer_event_source(this->_timer));
  this->_whiteColor = al_map_rgb(255, 255, 255);
  this->_pointColor = al_map_rgb(255, 0, 0);
  al_init_font_addon();
  al_init_ttf_addon();
  this->_font = al_load_font("./font/font.ttf", 15, 0);
  al_start_timer(this->_timer);
}

void	Graphic::displayMap(Game *game) {
  std::list<Body>::iterator	i;

  al_clear_to_color(al_map_rgb(0,0,0));
  i = game->getSnake()->getBodies()->begin();
  while (i != game->getSnake()->getBodies()->end())
    {
      al_draw_rectangle(i->getX() * BLOCK, i->getY() * BLOCK, i->getX() * BLOCK + BLOCK, i->getY() * BLOCK + BLOCK, this->_whiteColor, 1.0);
      i++;
    }
  al_draw_rectangle(game->getPoint()->getX() * BLOCK, game->getPoint()->getY() * BLOCK, game->getPoint()->getX() * BLOCK + BLOCK, game->getPoint()->getY() * BLOCK + BLOCK, this->_pointColor, 1.0);
}

void	Graphic::displayPlayer(Game *game) {
  al_draw_rectangle(0, game->getConfig()->getY() * BLOCK, game->getConfig()->getX() * BLOCK, game->getConfig()->getY() * BLOCK + 20, this->_pointColor, 1.0);
  std::stringstream ss;
  ss << game->getPlayer()->getScore();
  std::string s = ss.str();
  al_draw_text(this->_font, this->_whiteColor, 5, game->getConfig()->getY() * BLOCK, 0, s.c_str());
  al_draw_text(this->_font, this->_whiteColor, game->getConfig()->getX() * BLOCK - 50, game->getConfig()->getY() * BLOCK, 1, game->getPlayer()->getName().c_str());
  al_flip_display();
}

void	Graphic::wait(int time) {
  al_set_timer_speed(this->_timer, ALLEGRO_USECS_TO_SECS(time));
  ALLEGRO_EVENT	ev;
  al_wait_for_event(this->_eventTimerQueue, &ev);
}

bool	Graphic::keyEvent(Game *game) {
  ALLEGRO_EVENT	ev;

  while (!al_is_event_queue_empty(this->_eventQueue))
    {
      bool isEvent = al_get_next_event(this->_eventQueue, &ev);
      if (isEvent && ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	return (false);
      else if (isEvent && ev.type == ALLEGRO_EVENT_KEY_DOWN)
	{
	  switch(ev.keyboard.keycode)
	    {
	    case ALLEGRO_KEY_LEFT:
	      game->keyLeft();
	      break;
	    case ALLEGRO_KEY_RIGHT:
	      game->keyRight();
	      break;
	    case ALLEGRO_KEY_ESCAPE:
	      return (false);
	      break;
	    }
	}
    }
  return (true);
}

extern "C" {
  Graphic	*load_graphic()
  {
    return new Graphic();
  }
}
