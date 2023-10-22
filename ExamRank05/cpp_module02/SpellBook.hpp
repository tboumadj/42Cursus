#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

#pragma once
#include <map>
#include "ASpell.hpp"

class SpellBook
{
  public:
    SpellBook();
    ~SpellBook();

    void learnSpell(ASpell *spell);
    void forgetSpell(const std::string &str);
    ASpell* createSpell(const std::string &str);
    
  private:
    SpellBook(const SpellBook &co);
    SpellBook &operator=(const SpellBook &co);
    std::map<std::string, ASpell*> _list;
  };

#endif
