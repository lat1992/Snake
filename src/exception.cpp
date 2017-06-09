/*
// Exception.cpp for  in /home/tsai_g/rendu/cpp_abstractvm/srcs
// 
// Made by tsai guillaume
// Login   <tsai_g@epitech.net>
// 
// Started on  Thu Feb 27 12:15:14 2014 tsai guillaume
** Last update Wed Mar 26 03:10:11 2014 mauhoi wu
*/

#include	"exception.hpp"

Exception::Exception(std::string const& msg) throw():  msg(msg) {
}

Exception::~Exception() throw() {
}

const char*	Exception::what() const throw() {
  return (this->msg.c_str());
}
