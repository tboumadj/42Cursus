#include "ATarget.hpp"

ATarget::ATarget(std::string type): _type(type)
{
  return ;
}

ATarget::~ATarget()
{
  return ;
}

ATarget::ATarget(const ATarget &co)
{
  *this = co;
  return ;
}

ATarget &ATarget::operator=(const ATarget &co)
{
  if (this != &co)
  {
    *this = co;
  }
  return (*this);
}

std::string ATarget::getType()const
{
  return (this->_type);
}

void ATarget::getHitBySpell(ASpell const &spell)const
{
  std::cout << this->_type << " has been " << spell.getEffects() << "!" << std::endl;
  return ;
}
