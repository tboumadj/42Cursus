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
  return ;
}
