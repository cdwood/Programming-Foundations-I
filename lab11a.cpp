#include <iostream>
#include <string>
using namespace std;

int main()
{
   string phrase = "A quick brown fox jumps over the lazy dog.";
   string copy(phrase);
   string part(phrase, 8, 9);

   cout << "phrase = " << phrase << endl;
   cout << "length = " << phrase.length() << endl;
   cout << "copy = " << copy << endl;
   cout << "length = " << copy.length() << endl;
   cout << "part = " << part << endl;
   cout << "length = " << part.length() << endl;
   part.assign("black");
   part.append(" cat");
   part = "sleek " + part;
   cout << "part = " << part << endl;
   cout << "length = " << part.length() << endl;
   string word = "lazy";
   int pos = copy.find(word, 0);
   copy.insert(pos, "old ");
   cout << "pos = " << pos << endl;
   cout << "copy = " << copy << endl;
   cout << "length = " << copy.length() << endl;
   word = "quick";
   pos = copy.find(word, 0);
   copy.erase(pos, 5);
   copy.insert(pos, "frisky");
   cout << "copy = " << copy << endl;
   cout << "length = " << copy.length() << endl;
   for (int i = 0; i < phrase.length(); i++)
      if (phrase[i] == ' ')
      {
         phrase.erase(i,1);
         cout << "phrase = " << phrase << endl;
         cout << "length = " << phrase.length() << endl;
      }
   return 0;
}
/*
Output:
phrase = A quick brown fox jumps over the lazy dog.
length = 42
copy = A quick brown fox jumps over the lazy dog.
length = 42
part = brown fox
length = 9
part = sleek black cat
length = 15
pos = 33
copy = A quick brown fox jumps over the old lazy dog.
length = 46
copy = A frisky brown fox jumps over the old lazy dog.
length = 47
phrase = Aquick brown fox jumps over the lazy dog.
length = 41
phrase = Aquickbrown fox jumps over the lazy dog.
length = 40
phrase = Aquickbrownfox jumps over the lazy dog.
length = 39
phrase = Aquickbrownfoxjumps over the lazy dog.
length = 38
phrase = Aquickbrownfoxjumpsover the lazy dog.
length = 37
phrase = Aquickbrownfoxjumpsoverthe lazy dog.
length = 36
phrase = Aquickbrownfoxjumpsoverthelazy dog.
length = 35
phrase = Aquickbrownfoxjumpsoverthelazydog.
length = 34
*/
