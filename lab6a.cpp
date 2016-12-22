#include <iostream>
using namespace std;

int main()
{
   // Declare array of integers
   const int DATA_SIZE = 20;
   int data[DATA_SIZE]={0};
   int seed = 37;
   double mean = 0;
   double sum = 0;
   double variance = 0;
   
   for (int index = 0; index < DATA_SIZE; index++)
      cout << data[index] << " ";
   cout << endl;
   // Initialize array
   for (int index = 0; index < DATA_SIZE; index++){
      data[index] = seed % 100;
      seed = seed + 37;
   }

   // Print array
   for (int index = 0; index < DATA_SIZE; index++)
      cout << data[index] << " ";
   cout << endl;

   //Mean Calculation
   for (int index = 0; index < DATA_SIZE; index++)
     {
      sum = sum + data[index];
      mean = sum/DATA_SIZE;
     }
   cout << "mean = " << mean << endl;

   //Variance Calculation
   for (int index = 0; index < DATA_SIZE; index++)
   {
    variance = variance + ((data[index]-mean)*(data[index]-mean))/DATA_SIZE;
   }
   cout << "variance = " << variance << endl;

   return 0 ;
}
/*
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
37 74 11 48 85 22 59 96 33 70 7 44 81 18 55 92 29 66 3 40 
mean = 48.5
variance = 789.25
*/
