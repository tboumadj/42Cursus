#include "Fireball.hpp"

Fireball::Fireball(): ASpell("Fireball", "burnt to a crisp")
{
  return ;
}

Fireball::~Fireball()
{
  return ;
}

Fireball::Fireball(const Fireball &co): ASpell(co)
{
  return ;
}

Fireball &Fireball::operator=(const Fireball &co)
{
  if (this != &co)
  {
    *this = co;
  }
  return (*this);
}

ASpell *Fireball::clone(void)const
{
  return (new Fireball());
}
