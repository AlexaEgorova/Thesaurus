#ifndef THESAURUS_UNIT_H
#define THESAURUS_UNIT_H

#include <string>
#include <vector>

class ThesaurusUnit
{
public:
  ThesaurusUnit(const std::string& name, const std::string& meaning);
  ~ThesaurusUnit() = default;

  void appendSynonym(ThesaurusUnit* synonym);
  void appendAntonym(ThesaurusUnit* antonym);

  void print();

  std::string name;
  std::string meaning;
  std::vector<ThesaurusUnit*> synonyms;
  std::vector<ThesaurusUnit*> antonyms;
};

#endif