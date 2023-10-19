#ifndef BRICKWALL_HPP
# define BRICKWALL_HPP

#pragma once
#include "ATarget.hpp"

class BrickWall : public ATarget
{
  public:
    BrickWall();
    virtual ~BrickWall();
    BrickWall(const BrickWall &co);
    BrickWall &operator=(const BrickWall &co);

    virtual ATarget *clone()const;
  };

#endif
