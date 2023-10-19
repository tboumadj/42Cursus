#include "Dummy.hpp"

Dummy::Dummy(): ATarget("Target Practice Dummy")
{
  return ;
}

Dummy::~Dummy()
{
  return ;
}

Dummy::Dummy(const Dummy &co): ATarget(co)
{
  return ;
}

Dummy &Dummy::operator=(const Dummy &co)
{
  if (this != &co)
  {
    *this = co;
  }
  return (*this);
}

ATarget *Dummy::clone(void)const
{
  return (new Dummy());
}
