#include <iostream>

#include "thesaurus.h"

using namespace std;

ThesaurusUnit* Thesaurus::findUnitByName(const std::string& name)
{
  for (auto unit : units)
    if (unit->name == name)
      return unit;

  return nullptr;
}

void Thesaurus::append(ThesaurusUnit* unit)
{
  auto pos = find(units.begin(), units.end(), unit);
  if (pos != units.end())
  {
    cout << "Unit " << unit->name << " is already in the thesaurus";
    return;
  }

  for (auto synonym : unit->synonyms)
  {
    auto synonymicUnit = findUnitByName(synonym->name);
    if (synonymicUnit)
      synonymicUnit->appendSynonym(unit);
  }

  for (auto antonym : unit->antonyms)
  {
    auto antomicUnit = findUnitByName(antonym->name);
    if (antomicUnit)
      antomicUnit->appendAntonym(unit);
  }

  units.insert(unit);
}

void Thesaurus::print()
{
  cout << "***THESAURUS***" << endl;
  for (auto unit : units)
  {
    unit->print();
    cout << endl;
  }
}