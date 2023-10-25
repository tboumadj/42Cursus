#include "ASpell.hpp"

ASpell::ASpell(std::string name, std::string effects): _name(name), _effects(effects)
{
}

ASpell::~ASpell()
{
}

ASpell::ASpell(const ASpell &co)
{
  *this = co;
}

ASpell &ASpell::operator=(const ASpell &co)
{
  if (this != &co)
    *this = co;
  return (*this);
}

const std::string &ASpell::getName()const
{
  return (this->_name);
}

const std::string &ASpell::getEffects()const
{
  return (this->_effects);
}

void  ASpell::launch(const ATarget &target)const
{
  target.getHitBySpell(*this); 
}
