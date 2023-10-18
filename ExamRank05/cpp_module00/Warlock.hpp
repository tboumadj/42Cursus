#ifndef WARLOCK_HPP
# define RPN_HPP

# include <iostream>
# include <ostream>
# include <string>

class Warlock
{
  public:
    Warlock(std::string name, std::string title);
    ~Warlock();
    Warlock(const Warlock &co);
    Warlock &operator=(const Warlock &co);

    //G&S
    std::string   getName()const;
    std::string   getTitle()const;
    void          setTitle(std::string str);

    void          introduce() const;

  private:
    std::string _name;
    std::string _title;
  };
#endif

