#include "SpellBook.hpp"

SpellBook::SpellBook()
{
  return ;
}

SpellBook::~SpellBook()
{
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
  return (*this);
}

void SpellBook::learnSpell(ASpell *spell)
{
  if (spell)
    {
      if (this->_list.find(spell->getName()) == this->_list.end())
        this->_list[spell->getName()] = spell->clone();
    }
  return ;
}

void SpellBook::forgetSpell(const std::string &str)
{
  if (this->_list.find(str) == this->_list.end())
    this->_list.erase(this->_list.find(str));
  return ;
}
