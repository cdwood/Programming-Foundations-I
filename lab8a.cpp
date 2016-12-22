#include <iostream>
using namespace std;

char GetConcert()
{
   char Concert;
   cout << "The following concerts are available:\n";
   cout << "     B for Beyonce\n";
   cout << "     L for Lady Gaga\n";
   cout << "     T for Taylor Swift\n";
   cout << "Enter the letter for the concert you want:\n";
   cin >> Concert;
   while ((Concert!= 'B')&&(Concert!= 'L')&&(Concert!= 'T'))
   {
      cout << "That is not a valid concert letter. \nPlease enter a valid letter.\n";
      cout << "The following concerts are available:\n";
      cout << "     B for Beyonce\n";
      cout << "     L for Lady Gaga\n";
      cout << "     T for Taylor Swift\n";
      cout << "Enter the letter for the concert you want:\n";
      cin >> Concert;
   }
   return Concert;
}

int GetNumTickets()
{
   int NumTickets;
   cout << "Enter the number of tickets you want:\n";
   cin >> NumTickets;
   while ((NumTickets < 0) || (NumTickets > 10))
   {
      if (NumTickets < 0)
         cout << "You can not sell tickets here.\n";
      else if (NumTickets > 10)
         cout << "You may not purchase more than 10 tickets.\n";
      cout << "Enter the number of tickets you want:\n";
      cin >> NumTickets;
   }
   return NumTickets;
}

int main()
{
   // Declare variables 
   char Concert;
   int NumTickets;
   // Call function to find out the concert they want to attend
   Concert = GetConcert();
   // Call function to find out how many tickets they want
   NumTickets = GetNumTickets();
   // Print out the information you have collected.
   cout << "\nThe customer has placed the following order:\n";
   cout << "Concert: " << Concert << endl;
   cout << "Number of Tickets: " << NumTickets << endl;
   return 0;
}
/*
The following concerts are available:
     B for Beyonce
     L for Lady Gaga
     T for Taylor Swift
Enter the letter for the concert you want:
b 
That is not a valid concert letter. 
Please enter a valid letter.
The following concerts are available:
     B for Beyonce
     L for Lady Gaga
     T for Taylor Swift
Enter the letter for the concert you want:
T
Enter the number of tickets you want:
15
You may not purchase more than 10 tickets.
Enter the number of tickets you want:
8

The customer has placed the following order:
Concert: T
Number of Tickets: 8
cdwood@turing:~/CSCE2004/labs/lab8$ ./lab8a
The following concerts are available:
     B for Beyonce
     L for Lady Gaga
     T for Taylor Swift
Enter the letter for the concert you want:
X
That is not a valid concert letter. 
Please enter a valid letter.
The following concerts are available:
     B for Beyonce
     L for Lady Gaga
     T for Taylor Swift
Enter the letter for the concert you want:
T
Enter the number of tickets you want:
7

The customer has placed the following order:
Concert: T
Number of Tickets: 7
cdwood@turing:~/CSCE2004/labs/lab8$ ./lab8a
The following concerts are available:
     B for Beyonce
     L for Lady Gaga
     T for Taylor Swift
Enter the letter for the concert you want:
R
That is not a valid concert letter. 
Please enter a valid letter.
The following concerts are available:
     B for Beyonce
     L for Lady Gaga
     T for Taylor Swift
Enter the letter for the concert you want:
L
Enter the number of tickets you want:
3

The customer has placed the following order:
Concert: L
Number of Tickets: 3
*/

