// Include statements
#include <cstdlib>
#include <iostream>
using namespace std;
   
// Main function
int main()
{
   // Declare variables
   int *data;
   int number = 0;

   // Get user input
   cout << "Enter number of values:\n";
   cin >> number;
   if(number < 0)
   {
      number = 0;
   }
   data = new int[number];

   // Process data
   cout << "number = " << number << endl;
   for (int i = 0; i < number; i++)
   {
      data[i] = rand() % 100;
      cout << data[i] << " ";
   }
   cout << endl;
   cout << "number = " << number << endl;
   
   delete [] data;
   return 0 ;
}
/*
Output:
Enter number of values:
-8
number = 0

number = 0
cdwood@turing:~/CSCE2004/labs/lab13$ ./lab13b
Enter number of values:
57
number = 57
83 86 77 15 93 35 86 92 49 21 62 27 90 59 63 26 40 26 72 36 11 68 67 29 82 30 62 23 67 35 29 2 22 58 69 67 93 56 11 42 29 73 21 19 84 37 98 24 15 70 13 26 91 80 56 73 62 
number = 57
cdwood@turing:~/CSCE2004/labs/lab13$ ./lab13b
Enter number of values:
190
number = 190
83 86 77 15 93 35 86 92 49 21 62 27 90 59 63 26 40 26 72 36 11 68 67 29 82 30 62 23 67 35 29 2 22 58 69 67 93 56 11 42 29 73 21 19 84 37 98 24 15 70 13 26 91 80 56 73 62 70 96 81 5 25 84 27 36 5 46 29 13 57 24 95 82 45 14 67 34 64 43 50 87 8 76 78 88 84 3 51 54 99 32 60 76 68 39 12 26 86 94 39 95 70 34 78 67 1 97 2 17 92 52 56 1 80 86 41 65 89 44 19 40 29 31 17 97 71 81 75 9 27 67 56 97 53 86 65 6 83 19 24 28 71 32 29 3 19 70 68 8 15 40 49 96 23 18 45 46 51 21 55 79 88 64 28 41 50 93 0 34 64 24 14 87 56 43 91 27 65 59 36 32 51 37 28 75 7 74 21 58 95 
number = 190
*/
