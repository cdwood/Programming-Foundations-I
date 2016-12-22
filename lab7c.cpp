#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   double num, root, error;
   cout << "Enter number:\n";
   cin >> num;

   root = sqrt(num);
   cout << "sqrt(" << num << ")= " << root << endl;

   error = num - root * root;
   cout << "error= " << error << endl << endl;

   root = pow(num, 0.5);
   cout << "pow(" << num << ",1/2)= " << root << endl;
   
   error = num - root * root;
   cout << "error= " << error << endl << endl;

   root = cbrt(num);
   cout << "cbrt(" << num << ")= " << root << endl;

   error = num - root * root * root;
   cout << "error= " << error << endl << endl;

   root = pow(num,1.0/3.0);
   cout << "pow(" << num << ",1/3)= " << root << endl;

   error = num - root * root * root;
   cout << "error= " << error << endl << endl;
   return 0;
}
/*
Enter number:
42
sqrt(42)= 6.48074
error= 0

pow(42,1/2)= 6.48074
error= 0

cbrt(42)= 3.47603
error= 0

pow(42,1/3)= 3.47603
error= 0

cdwood@turing:~/CSCE2004/labs/lab7$ ./lab7c
Enter number:
-42
sqrt(-42)= -nan
error= -nan

pow(-42,1/2)= -nan
error= -nan

cbrt(-42)= -3.47603
error= 0

pow(-42,1/3)= -nan
error= -nan

cdwood@turing:~/CSCE2004/labs/lab7$ ./lab7c
Enter number:
12345
sqrt(12345)= 111.108
error= 1.81899e-12

pow(12345,1/2)= 111.108
error= 1.81899e-12

cbrt(12345)= 23.1116
error= -1.81899e-12

pow(12345,1/3)= 23.1116
error= 9.09495e-12
*/
