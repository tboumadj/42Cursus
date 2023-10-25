#include "ATarget.hpp"

ATarget::ATarget(std::string type): _type(type)
{
}

ATarget::~ATarget()
{
}

ATarget::ATarget(const ATarget &co)
{
  *this = co;
}

ATarget &ATarget::operator=(const ATarget &co)
{
  if (this != &co)
    *this = co;
  return (*this);
}

const std::string &ATarget::getType()const
{
  return (this->_type);
}

void ATarget::getHitBySpell(const ASpell &spell)const
{
  std::cout << this->_type << " has been " << spell.getEffects() << "!" << std::endl;
}
