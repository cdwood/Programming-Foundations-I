
#include <iostream>
using namespace std;
int main()
{
   // Get number from user
   int input = 0;
   cout << "Enter a number:\n";
   cin >> input;

   // Print some numbers
   cout << "Here are some odd numbers:\n";
   int number = 1;
   while (number <= input)
   {
      cout << number << endl;
      number = number + 2;
   }
   cout << "Here are some even numbers:\n";
   int number1 = 0;
   while (number1 <= input)
   {
      cout << number1 << endl;
      number1 = number1 + 2;
   }
   return 0;
}
/*

Enter a number:

10

Here are some odd numbers:

1

3

5

7

9

Here are some even numbers:

0

2

4

6

8

10



Enter a number:

11      

Here are some odd numbers:

1

3

5

7

9

11

Here are some even numbers:

0

2

4

6

8

10



Enter a number:

-10

Here are some odd numbers:

Here are some even numbers:

*/
