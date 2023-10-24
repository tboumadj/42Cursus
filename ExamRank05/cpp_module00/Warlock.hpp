#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <ostream>
# include <string>

class Warlock
{
  public:
    Warlock(std::string name, std::string title);
    ~Warlock();

    //G&S
    const std::string   &getName()const;
    const std::string   &getTitle()const;
    void          setTitle(const std::string &str);

    void          introduce() const;

  private:

    Warlock();
    Warlock(const Warlock &co);
    Warlock &operator=(const Warlock &co);

    std::string _name;
    std::string _title;
  };
#endif

