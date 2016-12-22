#include <iostream>
using namespace std;

int smallest(int a[], int left, int right) {
   if (left > right || left < 0 || right < 0) 
    	{
		return 1;  
	}
   int index = left;
   for(int i = left; i<=right; i++)
   {
      if(a[index] > a[i])
      {
         index = i;
      }
   }
   return index;
}

// Program to test smallest function
//-----------------------------------------
int main()
{
   int a[] = {9,1,5,7,4,2,6,0,8,3};
   int where;
  
   // test case one
   where = smallest(a, 0, 9);
   cout << "The smallest value in A[0..9] is " << a[where] 
        << " at index " << where << endl;
   for (int i = 0; i<=9; i++)
      cout << "a[" << i << "] = " << a[i] << endl;

   // test case two
   where = smallest(a, 0, 5);
   cout << "The smallest value in A[0..5] is " << a[where] 
        << " at index " << where << endl;
   for (int i = 0; i<=5; i++)
      cout << "a[" << i << "] = " << a[i] << endl;

   // test case three
   where = smallest(a, 2, 7);
   cout << "The smallest value in A[2..7] is " << a[where] 
        << " at index " << where << endl;
   for (int i = 2; i<=7; i++)
      cout << "a[" << i << "] = " << a[i] << endl;
   
   return 0;
}
/*
Output
The smallest value in A[0..9] is 0 at index 7
a[0] = 9
a[1] = 1
a[2] = 5
a[3] = 7
a[4] = 4
a[5] = 2
a[6] = 6
a[7] = 0
a[8] = 8
a[9] = 3
The smallest value in A[0..5] is 1 at index 1
a[0] = 9
a[1] = 1
a[2] = 5
a[3] = 7
a[4] = 4
a[5] = 2
The smallest value in A[2..7] is 0 at index 7
a[2] = 5
a[3] = 7
a[4] = 4
a[5] = 2
a[6] = 6
a[7] = 0
*/
