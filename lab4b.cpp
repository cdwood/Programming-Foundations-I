
#include <iostream>
using namespace std;
int main()
{
   // Get number from user
   int input = 0;
   double accumulator = 0;
   cout << "How many numbers would you like me to average together?\n";
   cin >> input;
   if(input<=0)
	cout<<"The mean of the user input values is:0\n";
   else
   {


	   // Compute and print the mean of the user input

	   int number = 0;
	   double x;
	   while (number < input)
	   {
	      cout << "Please type a numerical value now: ";
	      cin >> x;
	      accumulator = accumulator + x;
	      number = number + 1;
	   }
	   accumulator = accumulator / number;
	   cout << "The mean of the user input values is: " << accumulator << endl;
	   return 0;
   }
}
/*
How many numbers would you like me to average together?
4
Please type a numerical value now: 4
Please type a numerical value now: 4
Please type a numerical value now: 4
Please type a numerical value now: 4
The mean of the user input values is: 4
cdwood@turing:~/CSCE2004/labs/lab4$ ./lab4b.exe
How many numbers would you like me to average together?
4
Please type a numerical value now: 3
Please type a numerical value now: 2
Please type a numerical value now: 5
Please type a numerical value now: 7
The mean of the user input values is: 4.25
cdwood@turing:~/CSCE2004/labs/lab4$ ./lab4b.exe
How many numbers would you like me to average together?
-1
The mean of the user input values is:0
cdwood@turing:~/CSCE2004/labs/lab4$ ./lab4b.exe
How many numbers would you like me to average together?
0
The mean of the user input values is:0
*/
