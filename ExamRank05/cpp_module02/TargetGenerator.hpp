#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

//#pragma once
#include <map>
#include "ATarget.hpp"

class ATarget;

class TargetGenerator
{
  public:
    TargetGenerator();
    ~TargetGenerator();
    void learnTargetType(ATarget *target);
    void forgetTargetType(const std::string &str);
    ATarget* createTarget(const std::string &str);

  private:
    TargetGenerator(const TargetGenerator &co);
    TargetGenerator &operator=(const TargetGenerator &co);
    std::map<std::string, ATarget*> _target;
  };

#endif
