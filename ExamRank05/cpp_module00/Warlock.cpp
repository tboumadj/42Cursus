#include "Warlock.hpp"


Warlock::Warlock()
{
  return ;
}

Warlock::Warlock(std::string name, std::string title): _name(name), _title(title)
{
  std::cout << this->_name << ": This looks like another boring day." 
    << std::endl;
  return ;
}

Warlock::~Warlock()
{
  std::cout << this->_name << ": My job here is done!" << std::endl;
  return ;
}

Warlock::Warlock(const Warlock &co)
{
  *this = co;
  return ;
}

Warlock &Warlock::operator=(const Warlock &co)
{
  if (this != &co)
  {
    *this = co;
  }
  return (*this);
}

//G&S

std::string Warlock::getName()const
{
  return (this->_name);
}

std::string Warlock::getTitle()const
{
  return (this->_title);
}

void Warlock::setTitle(std::string str)
{
  this->_title = str;
  return ;
}

void Warlock::introduce() const
{
  std::cout << this->_name << ": I am " << this->_name <<
    ", " << this->_title <<"!" << std::endl;
  return ;
}
