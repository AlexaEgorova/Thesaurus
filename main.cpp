#include <unordered_set>
#include <iostream>

#include "thesaurusunit.h"
#include "thesaurus.h"

using namespace std;

int main()
{
  Thesaurus thesaurus;

  ThesaurusUnit good("good", "to be desired or approved of");
  ThesaurusUnit bad("bad", "of poor quality or a low standard");
  good.appendAntonym(&bad);
  bad.appendAntonym(&good);
  thesaurus.append(&good);
  thesaurus.append(&bad);

  ThesaurusUnit super("perfect", "as good as it is possible to be");
  super.appendSynonym(&good);
  thesaurus.append(&super);

  cout << "Welcome to the thesaurus!" << endl;
  while (true)
  {
    cout << endl << "What do you want to do?" << endl
         << "1 - look through the thesaurus" << endl
         << "2 - find a word" << endl
         << "3 - exit" << endl;
    string command;
    cin >> command;
    if (command == "1")
    {
      thesaurus.print();
    }
    else if (command == "2")
    {
      cout << "Enter the word: ";
      string word;
      cin >> word;
      auto unit = thesaurus.findUnitByName(word);
      if (unit)
      {
        unit->print();
      }
      else
      {
        cout << "No such word in thesaurus" << endl;
      }
    }
    else if (command == "3")
    {
      break;
    }
  }

  return 0;
}