#include "ASpell.hpp"

ASpell::ASpell(std::string name, std::string effects): _name(name), _effects(effects)
{
  return ;
}

ASpell::~ASpell()
{
  return ;
}

ASpell::ASpell(const ASpell &co)
{
  *this = co;
  return ;
}

ASpell &ASpell::operator=(const ASpell &co)
{
  if (this != &co)
  {
    *this = co;
  }
  return (*this);
}

std::string ASpell::getName()const
{
  return (this->_name);
}

std::string ASpell::getEffects()const
{
  return (this->_effects);
}

void ASpell::launch(ATarget const &target)const
{
  target.getHitBySpell(*this);
  return ;
}
