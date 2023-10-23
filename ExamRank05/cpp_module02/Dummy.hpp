#ifndef DUMMY_HPP
# define DUMMY_HPP

//#pragma once
# include "ATarget.hpp"

class Dummy : public ATarget
{
  public:
    Dummy();
    virtual ~Dummy();
    Dummy(const Dummy &co);
    Dummy &operator=(const Dummy &co);

    virtual ATarget *clone()const;
  };

#endif
