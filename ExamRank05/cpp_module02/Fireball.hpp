#ifndef FIREBALL_HPP
# define FIREBALL_HPP

#pragma once
#include "ASpell.hpp"

class Fireball : public ASpell
{
  public:
    Fireball();
    virtual ~Fireball();
    Fireball(const Fireball &co);
    Fireball &operator=(const Fireball &co);

    virtual ASpell *clone()const;
  };

#endif
