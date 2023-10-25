#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include <ostream>
#include <string>

class ATarget;

class ASpell
{
  protected:
    std::string _name;
    std::string _effects;

  public:
    ASpell(std::string name, std::string effects);
    virtual ~ASpell();
    ASpell(const ASpell &co);
    ASpell &operator=(const ASpell &co);

    const std::string &getName()const;
    const std::string &getEffects()const;
    void  launch(const ATarget &target)const;

    virtual ASpell *clone()const = 0;
  };

#include "ATarget.hpp"

#endif
