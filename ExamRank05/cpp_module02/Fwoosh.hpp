#ifndef FWOOSH_HPP
# define FWOOSH_HPP

//#pragma once
#include "ASpell.hpp"

class Fwoosh : public ASpell
{
  public:
    Fwoosh();
    virtual ~Fwoosh();
    Fwoosh(const Fwoosh &co);
    Fwoosh &operator=(const Fwoosh &co);

    virtual ASpell *clone()const;
  };

#endif
