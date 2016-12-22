#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
   // Declare 2D array
   const int SIZE = 3;
   char board[SIZE][SIZE];

   // Read x's and o's
   cout << "Enter x's and o's on board (L-R, T-B): ";
   for (int r = 0; r < SIZE; r++)
      for (int c = 0; c < SIZE; c++)
         cin >> board[r][c];

   // Print 2D array
   cout << "\n+---+---+---+\n";
   for (int r = 0; r < SIZE; r++)
   {
      cout << "| ";
      for (int c = 0; c < SIZE; c++)
         cout << board[r][c] << " | ";
      cout << "\n+---+---+---+\n";
   }

   // Check board contains only x's and o's
   bool valid = true;
   // TBA
   for (int r = 0; r < SIZE; r++)
   {
      for (int c = 0; c < SIZE; c++)
      {
       if((board[r][c]!= 'x') && (board[r][c] != 'o'))
   	  valid = false;
       else
    	  valid = true;
      }
   }
   if (!valid)
   {
      cout << "Sorry, you can only enter x's and o's\n";
      exit(1);
   }

   // Check first diagonal to see who wins
   char winner = ' ';
   if ((board[0][0] == board[1][1]) &&
       (board[1][1] == board[2][2]))
      winner = board[0][0];

   // Check second diagonal to see who wins
   if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]))
      winner = board [0][2];
   // TBA

   // Check rows to see who wins
   for (int r = 0; r < SIZE; r++)
      if ((board[r][0] == board[r][1]) &&
          (board[r][1] == board[r][2]))
         winner = board[r][0];

   // Check columns to see who wins
   for (int c = 0; c < SIZE; c++)
      if ((board[0][c] == board[1][c]) && (board[1][c] == board[2][c]))
        winner = board[0][c];
   // TBA

   // Print winner
   if (winner != ' ')
      cout << "Congratulations " << winner << " is the winner\n";
   else
      cout << "Sorry, no one wins\n";
   return 0 ;
}
/*
Enter x's and o's on board (L-R, T-B): oxo oxx oox

+---+---+---+
| o | x | o | 
+---+---+---+
| o | x | x | 
+---+---+---+
| o | o | x | 
+---+---+---+
Congratulations o is the winner


Enter x's and o's on board (L-R, T-B): oxo xox xxx

+---+---+---+
| o | x | o | 
+---+---+---+
| x | o | x | 
+---+---+---+
| x | x | x | 
+---+---+---+
Congratulations x is the winner


Enter x's and o's on board (L-R, T-B): helpmeout

+---+---+---+
| h | e | l | 
+---+---+---+
| p | m | e | 
+---+---+---+
| o | u | t | 
+---+---+---+
Sorry, you can only enter x's and o's
