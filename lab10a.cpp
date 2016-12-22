#include <iostream>
#include <string>
using namespace std;

// your code for swap function goes here:
void mySwap(int& x, int& y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

int main()
{
   int x,y;
   int a[] = {0,1,2,3,4,5,6,7,8,9};
   x = 3;
   y = 7;
  
   // current values of our variables
   cout << "x = " << x << endl;
   cout << "y = " << y << endl;
   for (int i = 0; i<10; i++)
      cout << "a[" << i << "] = " << a[i] << endl;

   mySwap(x,y);
   mySwap(a[0], a[9]);

   // current values after the above swap
   cout << "x = " << x << endl;
   cout << "y = " << y << endl;
   for (int i = 0; i<10; i++)
      cout << "a[" << i << "] = " << a[i] << endl;

   
   return 0;
}
/*
Output:
x = 3
y = 7
a[0] = 0
a[1] = 1
a[2] = 2
a[3] = 3
a[4] = 4
a[5] = 5
a[6] = 6
a[7] = 7
a[8] = 8
a[9] = 9
x = 7
y = 3
a[0] = 9
a[1] = 1
a[2] = 2
a[3] = 3
a[4] = 4
a[5] = 5
a[6] = 6
a[7] = 7
a[8] = 8
a[9] = 0
*/
