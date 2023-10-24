#include "Fireball.hpp"

Fireball::Fireball(): ASpell("Fireball", "burnt to a crisp")
{
  return ;
}

Fireball::~Fireball()
{
  return ;
}

ASpell *Fireball::clone(void)const
{
  return (new Fireball());
}
