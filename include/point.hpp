/*
** point.hpp for point in /home/lat/cpp_nibbler
** 
** Made by mauhoi wu
** Login   <wu_d@epitech.net>
** 
** Started on  Sat Apr  5 19:30:42 2014 mauhoi wu
** Last update Sun Apr  6 04:12:21 2014 mauhoi wu
*/

#ifndef POINT_HPP_
# define POINT_HPP_

class	Point {
protected:
  int	_x;
  int	_y;
  bool	_exist;

public:
  Point();
  virtual ~Point();
  int	getX();
  int	getY();
  void	setPoint(int, int);
  bool	isExist();
  void	turnExist();
};

#endif /* !POINT_HPP_ */
