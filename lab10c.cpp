#include <iostream>
using namespace std;

void mySwap(int& x, int& y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

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

int sorting(int a[], int left, int right) {
   if (left > right || left < 0 || right < 0) 
      {
         return 1;
      }
   for(int i = left; i<=right; i++)
   {
      int small;
      small = smallest(a, i, right);
      mySwap(a[i], a[small]);
   }
   return 0; //for success
}


// Program to test sorting function
//-----------------------------------------
int main()
{
   int a[] = {9,1,5,7,4,2,6,0,8,3};
  
   // test case one
   sorting(a, 1, 5);
   cout << " The value in A[1..5] is sorted nondecreasingly\n";
   for (int i = 0; i<10; i++)
      cout << "a[" << i << "] = " << a[i] << endl;

   // test case two
   sorting(a, 0, 9);
   cout << " The value in A[0..9] is sorted nondecreasingly\n";
   for (int i = 0; i<10; i++)
      cout << "a[" << i << "] = " << a[i] << endl;

   
   return 0;
}
/*
Output
 The value in A[1..5] is sorted nondecreasingly
a[0] = 9
a[1] = 1
a[2] = 2
a[3] = 4
a[4] = 5
a[5] = 7
a[6] = 6
a[7] = 0
a[8] = 8
a[9] = 3
 The value in A[0..9] is sorted nondecreasingly
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
*/
