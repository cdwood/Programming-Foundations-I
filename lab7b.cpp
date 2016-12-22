// Include statements
#include <iostream>
#include <cstring>
using namespace std;

// Main function
int main()
{
   const int SIZE = 80;
   char greeting[SIZE] = "Dear ";
   char name[SIZE] = "Mom";
   char alphabet[SIZE] = "abcedfghijklmnopqrstuvwxyz";
   char alphabet_upper[SIZE];
   int index;
   int len;

   cout << "The value of c-string variable greeting is: " << greeting << endl;
   cout << "The value of c-string variable name is: " << name << endl;
   cout << "The value of c-string variable alphabet is: " << alphabet << endl;
   
   cout << endl; // add a blank line
   // finding out number of characters in a string
   len = strlen(greeting);
   cout << "len = " << len << endl;
   strcpy(name, greeting);

   
   cout << endl;
   // to have the effect of assignment we have to copy each individual elements
   




   cout << "After assigning greeting to name by strcpy:\n";
   cout << "The value of c-string variable greeting is: " << greeting << endl;
   cout << "The value of c-string variable name is: " << name << endl;

   cout << endl;
   // getting upper case alphabet, using toupper function
   index = 0;
   while(alphabet[index] != '\0')
   {
      alphabet_upper[index] = toupper(alphabet[index]);
      index = index +1;
   }
   alphabet_upper[index] = '\0';

   cout << "the value of alphabet_upper is: " << alphabet_upper << endl;
   cout << "The value of alphabet is: " << alphabet << endl;
   cout << endl;
   // c-string comparision
   if(name == greeting)
      cout << "name and greeting have the same value\n";
   else if(name < greeting)
      cout << "name has less value\n";
   else
      cout << "greeting has less value\n";
   // (A) the right way to compare c-string   
   if(strcmp(name, greeting) == 0)
      cout << "name and greeting have the same value\n";
   else if(strcmp(name, greeting) < 0)
      cout << "name has less value\n";
   else 
      cout << "greeting has less value\n";
   cout << endl; 
   // c-string comparison after changing the value from Mom to Dad
   strcpy(name, "Dad");
   if(name == greeting)
      cout << "name and greeting have the same value\n";
   else if(name < greeting)
      cout << "name has less value\n";
   else
      cout << "greeting has less value\n";
   // (B) the right way to compare c-string
   if(strcmp(name, greeting) == 0)
      cout << "name and greeting have the same value\n";
   else if(strcmp(name, greeting) < 0)
      cout << "name has less value\n";
   else 
      cout << "greeting has less value\n";
   cout << endl;
   // comparing c-string literals
   cout << "The return value of strcmp(\"abc\",\"ab\") is " << strcmp("abc","ab") << endl;
   cout << "The return value of strcmp(\"abc\",\"abk\") is " << strcmp("abc","abk") << endl;
   cout << "The return value of strcmp(\"ABC\",\"ab\") is " << strcmp ("ABC","ab") << endl;
   

   return 0;
}
/*
The value of c-string variable greeting is: Dear 
The value of c-string variable name is: Mom
The value of c-string variable alphabet is: abcedfghijklmnopqrstuvwxyz

len = 5

After assigning greeting to name by strcpy:
The value of c-string variable greeting is: Dear 
The value of c-string variable name is: Dear 

the value of alphabet_upper is: ABCEDFGHIJKLMNOPQRSTUVWXYZ
The value of alphabet is: abcedfghijklmnopqrstuvwxyz

greeting has less value
name and greeting have the same value

greeting has less value
name has less value

The return value of strcmp("abc","ab") is 1
The return value of strcmp("abc","abk") is -1
The return value of strcmp("ABC","ab") is -1
*/
