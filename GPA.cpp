#include <iostream>
using namespace std;
 
int main()
{
	double gpa;//This variable stores the final computed gpa.
	char charIn;//This variable stores the letter grade that the user inputs.
	//These variables store the grade for each class represented as a number (0-4) for each class.
	int grade1;
	int grade2;
	int grade3;
	int grade4;
	int grade5;
	//These variables store the number of hours corresponding to each class entered.
	int hours1;
	int hours2;
	int hours3;
	int hours4;
	int hours5;
	double gradeWeight;//This variable stores the total grade points weighted by credit hour.
	int hourSum;//This variable stores the total number of credit hours.


	cout << "Welcome to PFI GPA calculator!";//This outputs a statement welcoming the user to the program.
	cout << "Enter the grade (A,B,C,D,F) for your class number 1\n";//This outputs a statement requesting the user to enter the letter grade value for the first course.
	cin >> charIn;//This stores the character that the user enters under the variable charIn.
	//These if statements determine the integer value of the letter grade enetered for the course and store it in the variable grade1.
	if(charIn=='A')
		grade1 = 4;
	else if(charIn=='B')
		grade1 = 3;
	else if(charIn=='C')
		grade1 = 2;
	else if(charIn=='D')
		grade1 = 1;
	else if(charIn=='F')
		grade1 = 0;
	//This statement tells the user that they didn't eneter a valid letter grade and stores a 0 in the grade for this class, treating it as an F.
	else
	{
		cout << "That is not a valid letter grade. An F has been assumed for this class.\n";
		grade1 = 0;
	}
	cout << "Enter hours (1..5) for your class number 1\n";//This outputs a statement asking the user to input the number of hours for the first class.
	cin >> hours1;//This stores the number of hours in the variable hours1.

	cout << "Enter the grade (A,B,C,D,F) for your class number 2\n";//This outputs a statement requesting the user to enter the letter grade value for the second course.
        cin >> charIn;//This stores the character that the user enters under the variable charIn.
	//These if statements determine the integer value of the letter grade enetered for the course and store it in the variable grade2.
        if(charIn=='A')
                grade2 = 4;
        else if(charIn=='B')
                grade2 = 3;
        else if(charIn=='C')
                grade2 = 2;
        else if(charIn=='D')
                grade2 = 1;
        else if(charIn=='F')
                grade2 = 0;
	//This statement tells the user that they didn't eneter a valid letter grade and stores a 0 in the grade for this class, treating it as an F.
        else
	{
                cout << "That is not a valid letter grade. An F has been assumed for this class.\n";
		grade2 = 0;
	}
        cout << "Enter hours (1..5) for your class number 2\n";//This outputs a statement asking the user to input the number of hours for the second class.
        cin >> hours2;//This stores the number of hours in the variable hours2.

	cout << "Enter the grade (A,B,C,D,F) for your class number 3\n";//This outputs a statement requesting the user to enter the letter grade value for the third course.
        cin >> charIn;//This stores the character that the user enters under the variable charIn.
	//These if statements determine the integer value of the letter grade enetered for the course and store it in the variable grade3.
        if(charIn=='A')
                grade3 = 4;
        else if(charIn=='B')
                grade3 = 3;
        else if(charIn=='C')
                grade3 = 2;
        else if(charIn=='D')
                grade3 = 1;
        else if(charIn=='F')
                grade3 = 0;
	//This statement tells the user that they didn't eneter a valid letter grade and stores a 0 in the grade for this class, treating it as an F.
        else
	{
                cout << "That is not a valid letter grade. An F has been assumed for this class.\n";
		grade3 = 0;
	}
        cout << "Enter hours (1..5) for your class number 3\n";//This outputs a statement asking the user to input the number of hours for the third class.
        cin >> hours3;//This stores the number of hours in the variable hours3.

	cout << "Enter the grade (A,B,C,D,F) for your class number 4\n";//This outputs a statement requesting the user to enter the letter grade value for the fourth course.
        cin >> charIn;//This stores the character that the user enters under the variable charIn.
	//These if statements determine the integer value of the letter grade enetered for the course and store it in the variable grade4.
	if(charIn== 'A')
		grade4 = 4;
        else if(charIn=='B')
                grade4 = 3;
        else if(charIn=='C')
                grade4 = 2;
        else if(charIn=='D')
                grade4 = 1;
        else if(charIn=='F')
                grade4 = 0;
	//This statement tells the user that they didn't eneter a valid letter grade and stores a 0 in the grade for this class, treating it as an F.
        else
	{
                cout << "That is not a valid letter grade. An F has been assumed for this class.\n";
		grade4 = 0;
	}
        cout << "Enter hours (1..5) for your class number 4\n";//This outputs a statement asking the user to input the number of hours for the fourth class.
        cin >> hours4;//This stores the number of hours in the variable hours4.

	cout << "Enter the grade (A,B,C,D,F) for your class number 5\n";//This outputs a statement requesting the user to enter the letter grade value for the fifth course.
        cin >> charIn;//This stores the character that the user enters under the variable charIn.
	//These if statements determine the integer value of the letter grade enetered for the course and store it in the variable grade5.
        if(charIn=='A')
                grade5 = 4;
        else if(charIn=='B')
                grade5 = 3;
        else if(charIn=='C')
                grade5 = 2;
        else if(charIn=='D')
                grade5 = 1;
        else if(charIn=='F')
                grade5 = 0;
	//This statement tells the user that they didn't eneter a valid letter grade and stores a 0 in the grade for this class, treating it as an F.
        else
	{
                cout << "That is not a valid letter grade. An F has been assumed for this class.\n";
		grade5 = 0;
	}
        cout << "Enter hours (1..5) for your class number 5\n";//This outputs a statement asking the user to input the number of hours for the fifth class.
        cin >> hours5;//This stores the number of hours in the variable hours5.

	gradeWeight = (grade1*hours1)+(grade2*hours2)+(grade3*hours3)+(grade4*hours4)+(grade5*hours5);//This calculates the total grade points weighted by credit hour by multiplying each grade point by its corresponding number of hours and stores it in gradeWeight.
	hourSum = hours1+hours2+hours3+hours4+hours5;//This calculates the total number of credit hours and stores it in hourSum.
	gpa = gradeWeight/hourSum;//This calculates the final gpa by dividing the total grade points weighted by credit hour by the total number of credit hours and stores it in gpa.

	//These if statements determine if the gpa is equal to or higher than a 3.0 and gives you a congratulations for it being higher or a sorry dude if it is lower.
	if(gpa >= 3.0)
		cout << "Congratulations, your GPA was " << gpa << "\n";
	else
		cout << "Sorry dude, you GPA was " << gpa << "\n";

}
