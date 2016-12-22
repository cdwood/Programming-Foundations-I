#include <iostream>
using namespace std;
 
int main()
{
   // Calculate area and volume of a cube
   double Height = 3.0;//added a semicolon to the end of this line. 
   double Area   = 6 * Height * Height;//changed the 8 to a 6 in order to correctly calculate the area.
   double Volume = Height * Height * Height;//Multiplied by height another time in order to calculate the correct volume.
   
   // Print results
   cout << "Height = " << Height << "\n";
   cout << "Area   = " << Area   << "\n";//Added dobule quotes in the appropriate locations to make the statement print correctly
   cout << "Volume = " << Volume << "\n";//Added << around the word volume so that it would print the variable instead of the word volume.
   return 0;
}
