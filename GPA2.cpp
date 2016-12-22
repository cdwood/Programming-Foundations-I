#include <iostream>
#include <string>
using namespace std;
 
int main()
{
	int courseAmt;//This variable stores the number of courses the user wishes to enter.
	std::string courseName;//Stores the name of the course.
	std::string courseNum;//Stores the course number.
	char charIn;//This variable stores the letter grade that the user inputs.
	int grade;//Stores the course grade as a number
	int hours;//Stores the course hours.
	double gpa;//This variable stores the final computed gpa.
	double gradeWeight;//This variable stores the total grade points weighted by credit hour.
	int hourSum=0;//This variable stores the total number of credit hours.

	cout << "Welcome to PFI GPA calculator!\n";//Welcomes user to program

	cout << "Enter the number of classes for GPA calculation\n"; //Requests number of courses to be entered.
	cin >> courseAmt;
	//Checks to see if user input is valid.
	while((courseAmt<=0)||(cin.fail()))
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Please enter only positive Integers\n";
		cout << "Enter the number of classes for GPA calculation\n"; 
		cin >> courseAmt;
	}
	//Removes any remaining input from input stream.
	cin.clear();
	cin.ignore(256, '\n');

	//Requests user to enter information for each course. Loops until info has been gathered for each course.
	for(int num = 1; num<=courseAmt; num=num+1)
	{
		std::cout << "Enter the course name for your class number " << num << std::endl;//Requests course name
		std::getline(std::cin, courseName);
		std::cout << "Enter the course number for your class number " << num << std::endl;//Requests course number
		std::getline(std::cin, courseNum);
		cout << "Enter the grade (A,B,C,D,F,W,I) for your class number " << num << "\n";//Requests course grade
		cin >> charIn;
		bool valid = false;//test case for while loop.
		//Checks to see if grade entered is valid and assigns it a value.
		while(!valid)
		{
			valid = true;
			if(charIn=='A')
				grade = 4;
			else if(charIn=='B')
				grade = 3;
			else if(charIn=='C')
				grade = 2;
			else if(charIn=='D')
				grade = 1;
			else if(charIn=='F')
				grade = 0;
			else if(charIn=='W')
				grade = 5;
			else if(charIn=='I')
				grade = 5;
			else
			{
				valid = false;
				cin.clear();
				cin.ignore(256, '\n');
				cout << "You did not enter A or B or C or D or F or W or I, please try again.\n";
				cout << "Enter the grade (A,B,C,D,F,W,I) for your class number " << num << "\n";
				cin >> charIn;
			}
		}

		valid = false;
		cout << "Enter hours (1..5) for your class number " << num << "\n";//Requests number of hours for course
		cin >> hours;
		//Checks to see if number of hours is valid
		while(!valid)
		{
			valid = true;
			if((hours>=1)&&(hours<=5));
			else
			{
				valid = false;
				cin.clear();
				cin.ignore(256, '\n');
				cout << "You did not enter hours within 1 and 5, please try again\n";
				cout << "Enter hours (1..5) for your class number " << num << "\n";
				cin >> hours;
			}
		}

		//adds grade and hours to gradeWeight and hourSum. Does not add anything if grade=5 becuase it is I or W in this case.
		if(grade != 5)
		{
			gradeWeight = gradeWeight + (grade*hours);
			hourSum = hourSum + hours;
		}
		else
		{
			gradeWeight = gradeWeight;
			hourSum = hourSum;
		}
		//Removes any remaining input from the input stream.
		cin.clear();
		cin.ignore(256, '\n');
	}

	gpa = gradeWeight/hourSum;//Calculates the final gpa.

	//Outputs gpa
	if(gpa >= 3.0)
		cout << "Congratulations, your GPA was " << gpa << "\n";
	else
		cout << "Sorry dude, your GPA was " << gpa << "\n";
	return 0;

}
