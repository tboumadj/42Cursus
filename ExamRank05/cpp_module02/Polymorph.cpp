#include "Polymorph.hpp"

Polymorph::Polymorph(): ASpell("Polymorph", "turned into a critter")
{
  return ;
}

Polymorph::~Polymorph()
{
  return ;
}

Polymorph::Polymorph(const Polymorph &co): ASpell(co)
{
  return ;
}

Polymorph &Polymorph::operator=(const Polymorph &co)
{
  if (this != &co)
  {
    *this = co;
  }
  return (*this);
}

ASpell *Polymorph::clone(void)const
{
  return (new Polymorph());
}
