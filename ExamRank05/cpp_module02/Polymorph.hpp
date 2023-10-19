#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP

#pragma once
# include "ASpell.hpp"

class Polymorph: public ASpell
{
  public:
    Polymorph();
    virtual ~Polymorph();
    Polymorph(const Polymorph &co);
    Polymorph &operator=(const Polymorph &co);

    virtual ASpell *clone()const;
  };

#endif
