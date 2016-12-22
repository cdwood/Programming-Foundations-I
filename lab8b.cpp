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

float GetCost(char Concert, int NumTickets)
{
   float Cost = 0;
   // Beyonce tickets are $35 each
   if(Concert == 'B')
	Cost = 35 * NumTickets;
   // Lady Gaga tickets are $45 each
   if(Concert == 'L')
	Cost = 45 * NumTickets;
   // Taylor Swift tickets are $40 each
   if(Concert == 'T')
	Cost = 40 * NumTickets;
   // Give 10% discount on 5 or more tickets
   if(NumTickets >= 5)
	Cost = Cost - (.1 * Cost);
   return Cost;
}

int main()
{
   // Declare variables 
   char Concert = 0;
   int NumTickets = 0;
   float Cost = 0;

   // Call function to find out the concert they want to attend
   Concert = GetConcert();

   // Call function to find out how many tickets they want
   NumTickets = GetNumTickets();

   // Call function to get total cost
   Cost = GetCost(Concert, NumTickets);

   // Print out the information you have collected.
   cout << "\nThe customer has placed the following order:\n";
   cout << "Concert: " << Concert << endl;
   cout << "Number of Tickets: " << NumTickets << endl;
   cout << "Total Cost: " << Cost << endl;
   return 0;
}
/*
The following concerts are available:
     B for Beyonce
     L for Lady Gaga
     T for Taylor Swift
Enter the letter for the concert you want:
T
Enter the number of tickets you want:
6

The customer has placed the following order:
Concert: T
Number of Tickets: 6
Total Cost: 216
cdwood@turing:~/CSCE2004/labs/lab8$ ./lab8b
The following concerts are available:
     B for Beyonce
     L for Lady Gaga
     T for Taylor Swift
Enter the letter for the concert you want:
B
Enter the number of tickets you want:
2

The customer has placed the following order:
Concert: B
Number of Tickets: 2
Total Cost: 70
cdwood@turing:~/CSCE2004/labs/lab8$ ./lab8b
The following concerts are available:
     B for Beyonce
     L for Lady Gaga
     T for Taylor Swift
Enter the letter for the concert you want:
L
Enter the number of tickets you want:
8

The customer has placed the following order:
Concert: L
Number of Tickets: 8
Total Cost: 324
*/
