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
  for(std::map<std::string, ASpell*>::iterator it = this->_list.begin(); it != this->_list.end(); ++it)
    {
      delete it->second;
    }
  this->_list.clear();
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
  if (spell)
  {
    if (_list.find(spell->getName()) == _list.end())
    {
      _list[spell->getName()] = spell->clone();
    }
  }
}

void Warlock::forgetSpell(std::string str)
{
  if (_list.find(str) != _list.end())
  {
    _list.erase(_list.find(str));
  }
}

void Warlock::launchSpell(std::string str, ATarget &target)
{
  if(_list.find(str) != _list.end())
  {
    _list[str]->launch(target);
  }
}



