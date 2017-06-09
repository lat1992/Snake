//
// Exception.hpp for  in /home/tsai_g/rendu/cpp_abstractvm/nouveau/src
// 
// Made by tsai guillaume
// Login   <tsai_g@epitech.net>
// 
// Started on  Fri Feb 28 14:06:52 2014 tsai guillaume
// Last update Fri Feb 28 14:07:53 2014 tsai guillaume
//

#ifndef EXCEPTION_HPP_
# define EXCEPTION_HPP_

#include <string>
#include <exception>

class Exception : public std::exception {
public:
  Exception(std::string const& msg) throw();
  virtual ~Exception() throw();

  virtual const char* what() const throw();

private:
  std::string   msg;
};

#endif /* !EXCEPTION_HPP_ */
