#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

void print_quadratic(double a, double b, double c)
{
   cout << "Quadratic equation: ";
   cout << a << "x^2" << " + " << b << "x" << " + " << c << endl;
}

void print_roots(double a , double b, double c)
{
   double discriminant = b * b - 4 * a * c;
   double root1 = (- b - sqrt(discriminant)) / (2 * a);
   double root2 = (- b + sqrt(discriminant)) / (2 * a);
   if (discriminant < 0)
      cout << "There are no roots to this quadratic equation\n";
   else if (discriminant == 0)
      cout << "There is one root: " << root1 << endl;
   else
      cout << "There are two roots: " << root1 << " and " << root2 << endl;
}

double get_coefficients(double &a, double &b, double &c)
{
   while (a == 0)
   {
      cout << "Enter quadratic coefficients a b c:\n";
      cin >> a >> b >> c;
      if (a == 0)
         cout << "Ooops, when a=0 you have a linear equation\n";
   }
   return a; 
   return b;
   return c;
}

int main()
{
   double a = 0, b = 0, c = 0;

   // Get coefficients of quadratic equation
   get_coefficients(a,b,c);

   // Print quadratic equation
   print_quadratic(a,b,c);

   // Print roots of quadratic equation
   print_roots(a,b,c);
   print_quadratic(-a,-b,-c);
   print_roots(-a,-b,-c);
   return 0;
}
/*
Enter quadratic coefficients a b c:
1 -5 6
Quadratic equation: 1x^2 + -5x + 6
There are two roots: 2 and 3
Quadratic equation: -1x^2 + 5x + -6
There are two roots: 3 and 2
cdwood@turing:~/CSCE2004/labs/lab8$ ./lab8c
Enter quadratic coefficients a b c:
3 -5 7
Quadratic equation: 3x^2 + -5x + 7
There are no roots to this quadratic equation
Quadratic equation: -3x^2 + 5x + -7
There are no roots to this quadratic equation
cdwood@turing:~/CSCE2004/labs/lab8$ ./lab8c
Enter quadratic coefficients a b c:
1 5 6
Quadratic equation: 1x^2 + 5x + 6
There are two roots: -3 and -2
Quadratic equation: -1x^2 + -5x + -6
There are two roots: -2 and -3
*/
