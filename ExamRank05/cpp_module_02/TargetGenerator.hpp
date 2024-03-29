#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <map>
#include <iostream>
#include <ostream>
#include <string>
#include "ATarget.hpp"

class TargetGenerator
{
  private:
    TargetGenerator(const TargetGenerator &co);
    TargetGenerator &operator=(const TargetGenerator &co);

    std::map<std::string, ATarget*> _target;

  public:
    TargetGenerator();
    ~TargetGenerator();

    void learnTargetType(ATarget *target);
    void forgetTargetType(const std::string &str);
    ATarget *createTarget(const std::string &str);
  };

#endif
