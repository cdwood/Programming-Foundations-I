// Include statements
#include <cstdlib>
#include <iostream>
using namespace std;
   
// Main function
int main()
{
   // Declare variables
   int data[100];
   int number = 0;

   // Get user input
   cout << "Enter number of values:\n";
   cin >> number;

   // Process data
   for (int i = 0; i < number; i++)
   {
      data[i] = random() % 100;
      cout << data[i] << " ";
   }
   cout << endl;
   
   return 0 ;
}
