#ifndef BRICKWALL_HPP
# define BRICKWALL_HPP

//#pragma once
#include "ATarget.hpp"

class BrickWall : public ATarget
{
  public:
    BrickWall();
    ~BrickWall();
    ATarget *clone()const;
  };

#endif
