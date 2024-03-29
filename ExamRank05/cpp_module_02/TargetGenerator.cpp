#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
}

TargetGenerator::~TargetGenerator()
{
  for(std::map<std::string, ATarget*>::iterator it = _target.begin(); it != _target.end(); ++it)
  {
    delete it->second;
  }
  _target.clear();
}

TargetGenerator::TargetGenerator(const TargetGenerator &co)
{
  *this = co;
}

TargetGenerator &TargetGenerator::operator=(const TargetGenerator &co)
{
  if (this != &co)
    *this = co;
  return (*this);
}

void TargetGenerator::learnTargetType(ATarget *target)
{
  if (target)
  {
    _target[target->getType()] = target->clone();
  }
  //if (target)
  //{
  // _target[target->getType()] = target;
  //}
}

void TargetGenerator::forgetTargetType(const std::string &str)
{
  std::map<std::string, ATarget*>::iterator it = _target.find(str);
  if (it != _target.end())
{
    delete it->second;
    _target.erase(it);
  }
  //if (_target.find(str) != _target.end())
  //  _target.erase(_target.find(str));
}

ATarget *TargetGenerator::createTarget(const std::string &str)
{
  ATarget *tmp = NULL;
  if (_target.find(str) != _target.end())
    tmp = _target[str];
  return (tmp);
}
