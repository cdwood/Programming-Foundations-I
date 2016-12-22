#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

char rot13(char ch)
{
   if ((ch >= 'a') && (ch <= 'z'))
      return char((13 + ch - 'a') % 26 + 'a');
   else if ((ch >= 'A') && (ch <= 'Z'))
      return char((13 + ch - 'A') % 26 + 'A');
   else
      return ch;
}

string rot13(string str)
{
   for (unsigned int i = 0; i < str.length(); i++)
      str[i] = rot13(str[i]);
   return str;
}

int main()
{
   fstream infile;
   infile.open("message.in");
   ofstream outfile;
   outfile.open("message.out");
   if(outfile.fail())
   {
      cout << "Error: could not open output file\n";
      exit (EXIT_FAILURE);
   }
   string word;
   int count = 1;
   char line[100];
   while (infile.getline(line, 100))
      cout << count++ << ":" << rot13(line) << endl;
   infile.close();
   outfile.close();
   return 0;
}
/*Output:
1:How can you tell an extrovert from an introvert at NSA? 
2:In the elevators, the extrovert looks at the OTHER guy's shoes.
3:Knock, Knock.
4:Who's there?
5:Et.
6:Et who?
7:Et tu, Brute? Then fall, Caesar!
*/
