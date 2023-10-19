#include "BrickWall.hpp"

BrickWall::BrickWall(): ATarget("Inconspicuous Red-Brick Wall")
{
  return ;
}

BrickWall::~BrickWall()
{
  return ;
}

BrickWall::BrickWall(const BrickWall &co): ATarget(co)
{
  return ;
}

BrickWall &BrickWall::operator=(const BrickWall &co)
{
  if (this != &co)
  {
    *this = co;
  }
  return (*this);
}

ATarget *BrickWall::clone(void)const
{
  return (new BrickWall());
}
