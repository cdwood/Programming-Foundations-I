#include <iostream>
using namespace std;
int main()
{
   // Declare and initialize variables
   double InputValue = 0;
   double TotalValue = 0;
   int CountValue = 0;

   double AverageValue = 0;

   // Read input value
   cout << "Enter input value (or -1 to stop):\n";
   cin >> InputValue;

   // While loop to total up the daily sales
   while (InputValue != -1)
   {
      // Update total and count (FIX)
	TotalValue = TotalValue + InputValue;
	CountValue = CountValue + 1;
      // Read input value
      cout << "Enter input value (or -1 to stop):\n";
      cin >> InputValue;
   }

   // Calculate and print average value (FIX)
   if(CountValue>0)
   {
  	 AverageValue = TotalValue/CountValue;
	 cout << "Average: " << AverageValue << endl;
   	 return 0;
   }
}
/*
Enter input value (or -1 to stop):
4
Enter input value (or -1 to stop):
4
Enter input value (or -1 to stop):
-1
Average: 4
cdwood@turing:~/CSCE2004/labs/lab4$ ./lab4c.exe
Enter input value (or -1 to stop):
10
Enter input value (or -1 to stop):
20
Enter input value (or -1 to stop):
-1
Average: 15
cdwood@turing:~/CSCE2004/labs/lab4$ ./lab4c.exe
Enter input value (or -1 to stop):
-1
cdwood@turing:~/CSCE2004/labs/lab4$ ./lab4c.exe
Enter input value (or -1 to stop):
7
Enter input value (or -1 to stop):
8
Enter input value (or -1 to stop):
-1
Average: 7.5
*/
