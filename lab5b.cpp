#include <iostream>
using namespace std;
int main()
{
   // Get number from user
   int input = 0;
   cout << "Enter a number:\n";
   cin >> input;

   // Print numbers from [1..input]
   for (int num = 1; num <= input; num = num + 1)
      cout << num << " ";
   cout << endl;

   // Print EVEN numbers from [0..input-1] (FIX)
   for (int num = 0; (num < input)&&(num%2==0); num = num+2)
	cout << num << " ";
   cout << endl;

   // Print ODD numbers from [input..1] (FIX)
   if(input%2==0)
   {
   	 for (int num = input-1; num >= 1; num = num-2)
		cout << num << " ";
  	 cout << endl;
   }
   else
   {
   	 for (int num = input; num >= 1; num = num-2)
		cout << num << " ";
  	 cout << endl;
   }

   return 0 ;
}
/*
Enter a number:
8
1 2 3 4 5 6 7 8 
0 2 4 6 
7 5 3 1 
cdwood@turing:~/CSCE2004/labs/lab5$ ./lab5b.exe
Enter a number:
11
1 2 3 4 5 6 7 8 9 10 11 
0 2 4 6 8 10 
11 9 7 5 3 1 
*/
