#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#pragma once
# include <iostream>
# include <ostream>
# include <string>
# include <map>
# include "ASpell.hpp"
# include "ATarget.hpp"

class ATarget;
class ASpell;

class Warlock
{
  public:
    Warlock(std::string name, std::string title);
    ~Warlock();

    //G&S
    std::string   getName()const;
    std::string   getTitle()const;
    void          setTitle(std::string str);

    void          introduce() const;
    void          learnSpell(ASpell *spell);
    void          forgetSpell(std::string str);
    void          launchSpell(std::string str, const ATarget &target);

  private:

    Warlock();
    Warlock(const Warlock &co);
    Warlock &operator=(const Warlock &co);
    std::string _name;
    std::string _title;
    std::map<std::string, ASpell *> _list;
  };
#endif

