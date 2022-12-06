#include <iostream>

#include "thesaurusunit.h"

using namespace std;

ThesaurusUnit::ThesaurusUnit(const string& name, const string& meaning):
  name(name),
  meaning(meaning)
{
}

void ThesaurusUnit::appendSynonym(ThesaurusUnit* synonym)
{
  auto pos = find(synonyms.begin(), synonyms.end(), synonym);
  if (pos == synonyms.end())
    synonyms.push_back(synonym);
  else
    cout << "Synonym " << synonym->name << " already exists for unit " << name << endl;
}

void ThesaurusUnit::appendAntonym(ThesaurusUnit* antonym)
{
  auto pos = find(antonyms.begin(), antonyms.end(), antonym);
  if (pos == antonyms.end())
    antonyms.push_back(antonym);
  else
    cout << "Antonym " << antonym->name << " already exists for unit " << name << endl;
}

void ThesaurusUnit::print()
{
  cout << "-------" << endl;
  cout << "name: " << name << endl;
  cout << "meaning: " << meaning << endl;

  cout << "synonyms: ";
  for (int i = 0; i < synonyms.size(); ++i)
  {
    if (i < synonyms.size() - 1)
      cout << synonyms[i]->name << ", ";
    else
      cout << synonyms[i]->name;
  }
  cout << endl;
  
  cout << "antonyms: ";
  for (int i = 0; i < antonyms.size(); ++i)
  {
    if (i < antonyms.size() - 1)
      cout << antonyms[i]->name << ", ";
    else
      cout << antonyms[i]->name;
  }
  cout << endl;
}