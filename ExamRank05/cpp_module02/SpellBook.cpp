#include "SpellBook.hpp"

SpellBook::SpellBook()
{
  return ;
}

SpellBook::~SpellBook()
{
  for (std::map<std::string, ASpell*>::iterator it = _list.begin(); it != _list.end(); ++it)
  {
    delete it->second;
  }
  _list.clear();
  return ;
}

SpellBook::SpellBook(const SpellBook &co)
{
  *this = co;
  return ;
}

SpellBook &SpellBook::operator=(const SpellBook &co)
{
  if (this != &co)
  {
   *this = co;
  }
  //this->_list = co._list;
  return (*this);
}

void SpellBook::learnSpell(ASpell *spell)
{
  if (spell)
  {
    _list[spell->getName()] = spell->clone();
  }
  return ;
}

void SpellBook::forgetSpell(const std::string &str)
{
  std::map<std::string, ASpell*>::iterator it = _list.find(str);
  if (it != _list.end())
  {
    delete it->second;
    _list.erase(it);
  }
  return ;
}

ASpell* SpellBook::createSpell(const std::string &str)
{
  //ASpell *tmp = NULL;
  //if (_list.find(str) != _list.end())
  // {
  //  tmp = _list[str];
  //  return (tmp);
  //  }
  //return (NULL);
  ASpell* tmp = NULL;
  if (_list.find(str) != _list.end())
    tmp = _list[str];
  return (tmp);
}
