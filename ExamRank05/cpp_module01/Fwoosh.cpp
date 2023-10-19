#include "Fwoosh.hpp"

Fwoosh::Fwoosh(): ASpell("Fwoosh", "fwooshed")
{
  return ;
}

Fwoosh::~Fwoosh()
{
  return ;
}

Fwoosh::Fwoosh(const Fwoosh &co): ASpell(co)
{
  return ;
}

Fwoosh &Fwoosh::operator=(const Fwoosh &co)
{
  if (this != &co)
  {
    *this = co;
  }
  return (*this);
}

ASpell *Fwoosh::clone(void)const
{
  return (new Fwoosh());
}

