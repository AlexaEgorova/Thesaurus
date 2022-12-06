#ifndef THESAURUS_H
#define THESAURUS_H

#include <unordered_set>

#include "thesaurusunit.h"

class Thesaurus
{
public:
  Thesaurus() = default;
  ~Thesaurus() = default;

public:
  ThesaurusUnit* findUnitByName(const std::string& name);
  void append(ThesaurusUnit* unit);
  void print();

private:
  std::unordered_set<ThesaurusUnit*> units;
};

#endif