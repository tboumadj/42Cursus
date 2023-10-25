#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <ostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"


class Warlock
{
  private:
    std::string _name;
    std::string _title;
    SpellBook _list;
    
    Warlock();
    Warlock(const Warlock &co);
    Warlock &operator=(const Warlock &co);

  public:
    Warlock(std::string name, std::string title);
    ~Warlock();

    const std::string &getName()const;
    const std::string &getTitle()const;
    void  setTitle(const std::string &str);
    void  introduce()const;

    void  learnSpell(ASpell *spell);
    void  forgetSpell(std::string str);
    void  launchSpell(std::string str, ATarget &target);

  };

#endif
