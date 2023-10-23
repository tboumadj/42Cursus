#ifndef ASPELL_HPP
# define ASPELL_HPP

//#pragma once
# include <iostream>
# include <ostream>
# include <string>
//# include "ATarget.hpp"

class ATarget;

class ASpell
{
  public:
    ASpell(std::string name, std::string effects);
    virtual ~ASpell();
    ASpell(const ASpell &co);
    ASpell &operator=(const ASpell &co);

    //G&S
    std::string   getName()const;
    std::string   getEffects()const;

    virtual ASpell *clone()const =0;
    void    launch(ATarget const &target)const;

  protected:
    std::string _name;
    std::string _effects;
  };

#include "ATarget.hpp"

#endif
