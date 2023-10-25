#include "Warlock.hpp"

Warlock::Warlock()
{
}

Warlock::~Warlock()
{
  std::cout << this->_name << ": My job here is done!" << std::endl;
}

Warlock::Warlock(std::string name, std::string title): _name(name), _title(title)
{
  std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(const Warlock &co)
{
  *this = co;
}

Warlock &Warlock::operator=(const Warlock &co)
{
  if (this != &co)
    *this = co;
  return (*this);
}

const std::string &Warlock::getName()const
{
  return (this->_name);
}

const std::string &Warlock::getTitle()const
{
  return (this->_title);
}

void Warlock::setTitle(const std::string &str)
{
  this->_title = str;
}

void Warlock::introduce()const
{
  std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
  _list.learnSpell(spell);
}

void Warlock::forgetSpell(std::string str)
{
  _list.forgetSpell(str);
}

void Warlock::launchSpell(std::string str, ATarget &target)
{
  if(_list.createSpell(str))
    _list.createSpell(str)->launch(target);
}



