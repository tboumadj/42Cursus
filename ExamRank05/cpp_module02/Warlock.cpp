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
  for (std::map<std::string, ASpell*>::iterator it = _list.begin(); it != _list.end(); ++it)
  {
    delete it->second;
  }
  _list.clear();
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

void Warlock::learnSpell(ASpell *spell)
{
  if (spell)
  {
    if (this->_list.find(spell->getName()) == this->_list.end())
      this->_list[spell->getName()] = spell->clone();
  }
  return ;
}

void Warlock::forgetSpell(std::string str)
{
  if (this->_list.find(str) != this->_list.end())
    this->_list.erase(this->_list.find(str));
  return ;
}

void Warlock::launchSpell(std::string str, const ATarget &target)
{
  if (this->_list.find(str) != this->_list.end())
    this->_list[str]->launch(target);
  return ;
}
