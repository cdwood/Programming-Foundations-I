// Include statements
#include <cstdlib>
#include <iostream>
using namespace std;

// Main function
int main()
{
   // Get user input
   int size1 = 0;
   cout << "Enter size of array1:\n";
   cin >> size1;
   if (size1 < 0) 
      size1 = 0;

   // Get user input
   int size2 = 0;
   cout << "Enter size of array2:\n";
   cin >> size2;
   if (size2 < 0) 
      size2 = 0;

   // Process array1
   int * array1 = new int[size1];
   cout << "array1:\n";
   for (int i = 0; i < size1; i++)
   {
      array1[i] = 17;
      cout << array1[i] << " ";
   }
   cout << endl;

   // Location A
   //Return memory to O/S
   delete [] array1;

   // Process array2
   int * array2 = new int[size2];
   cout << "array2:\n";
   for (int i = 0; i < size2; i++)
   {
      cout << array2[i] << " ";
      array2[i] = 42;
      cout << array2[i] << " ";
   }
   cout << endl;

   // Location B
   // Print array1
   cout << "array1:\n";
   for (int i = 0; i < size1; i++)
      cout << array1[i] << " ";
   cout << endl;

   // Location C
   array1 = NULL;

   // Return memory to O/S
   delete [] array2;
   array2 = NULL;

   return 0 ;
}
/*
Output:
Enter size of array1:
20
Enter size of array2:
20
array1:
17 17 17 17 17 17 17 17 17 17 17 17 17 17 17 17 17 17 17 17 
array2:
0 42 0 42 17 42 17 42 17 42 17 42 17 42 17 42 17 42 17 42 17 42 17 42 17 42 17 42 17 42 17 42 17 42 17 42 17 42 17 42 
array1:
42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 
*/
