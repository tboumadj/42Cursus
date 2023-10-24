#ifndef ATARGET_HPP
#define ATARGET_HPP

//#pragma once
# include <iostream>
# include <ostream>
# include <string>
//# include "ASpell.hpp"

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

    //G&S
    std::string getType()const;

    virtual ATarget *clone()const =0;
    void    getHitBySpell(ASpell const &spell)const;

  };

# include "ASpell.hpp"

#endif
