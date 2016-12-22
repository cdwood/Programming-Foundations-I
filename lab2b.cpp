// Include statements
#include <iostream>
using namespace std;

// Main function
int main ()
{
  // Constant declaration 
  double x = 100;

  // Get user input
  double y = 0;
  cout << "Enter value for y: " << endl;
  cin >> y;

  // Perform arithmetic operations
  double sum = x + y;
  double difference = x - y;
  double quotient = x / y;
  int remainder = int(x) % int(y);
  double product = x * y;

  // Print results 
  cout << "The sum (x + y) is: " << sum << endl;
  cout << "The difference (x - y) is: " << difference << endl;
  cout << "The quotient (x / y) is: " << quotient << endl;
  cout << "The remainder (x % y) is: " << remainder << endl;
  cout << "The product (x * y) is: " << product << endl;

  return 0;
}

//output
/*
Enter value for y: 
3
The sum (x + y) is: 103
The difference (x - y) is: 97
The quotient (x / y) is: 33.3333
The remainder (x % y) is: 1
The product (x * y) is: 300
cdwood@turing:~/CSCE2004/labs/lab2$ ./lab2b.exe
Enter value for y: 
45
The sum (x + y) is: 145
The difference (x - y) is: 55
The quotient (x / y) is: 2.22222
The remainder (x % y) is: 10
The product (x * y) is: 4500
*/
