#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include <ostream>
#include <string>

class ASpell;

class ATarget
{
  protected:
    std::string _type;

  public:
    ATarget(std::string type);
    virtual ~ATarget();
    ATarget(const ATarget &co);
    ATarget &operator=(const ATarget &co);

    const std::string &getType()const;
    void  getHitBySpell(const ASpell &spell)const;

    virtual ATarget *clone()const = 0;
  };

#include "ASpell.hpp"

#endif
