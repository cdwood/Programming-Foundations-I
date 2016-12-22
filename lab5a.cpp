#include <iostream>
using namespace std;
int main()
{
   int num = 0;

   cout << "Enter a positive even number:\n";
   cin >> num;
   while ((num <= 0)||(num%2==1))
   {
      cout << "Enter a positive even number:\n";
      cin >> num;
   }
   cout << "num = " << num << endl;
   return 0;
}
/*
Enter a positive even number:
-2
Enter a positive even number:
-1
Enter a positive even number:
0
Enter a positive even number:
1
Enter a positive even number:
2
num = 2
cdwood@turing:~/CSCE2004/labs/lab5$ ./lab5a.exe
Enter a positive even number:
-4
Enter a positive even number:
3
Enter a positive even number:
4
num = 4
*/
