#include "SpellBook.hpp"

SpellBook::SpellBook()
{
}

SpellBook::~SpellBook()
{
  for(std::map<std::string, ASpell*>::iterator it = _book.begin(); it != _book.end(); ++it)
  {
    delete it->second;
  }
  _book.clear();
}

SpellBook::SpellBook(const SpellBook &co)
{
  *this = co;
}

SpellBook &SpellBook::operator=(const SpellBook &co)
{
  if (this != &co)
    *this = co;
  return (*this);
}

void SpellBook::learnSpell(ASpell *spell)
{
  if (spell)
  {
    _book[spell->getName()] = spell->clone();
  }
}

void SpellBook::forgetSpell(const std::string &str)
{
  std::map<std::string, ASpell*>::iterator it = _book.find(str);
  if (it != _book.end())
  {
    delete it->second;
    _book.erase(it);
  }
}

ASpell *SpellBook::createSpell(const std::string &str)
{
  ASpell *tmp = NULL;
  if (_book.find(str) != _book.end())
    tmp = _book[str];
  return (tmp);
}
