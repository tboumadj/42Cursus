#include "BrickWall.hpp"

BrickWall::BrickWall(): ATarget("Inconspicuous Red-Brick Wall")
{
  return ;
}

BrickWall::~BrickWall()
{
  return ;
}

ATarget *BrickWall::clone(void)const
{
  return (new BrickWall());
}
