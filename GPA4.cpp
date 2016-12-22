#include <iostream>
#include <string>
using namespace std;

int gradeConvert(const char grade)//Converts a grade represented as a character to a grade represented as an integer.
{
	int gradePoint;
	if(grade=='A')
		gradePoint = 4;
	else if(grade=='B')
		gradePoint = 3;
	else if(grade=='C')
		gradePoint = 2;
	else if(grade=='D')
		gradePoint = 1;
	else if(grade=='F')
		gradePoint = 0;
	else if(grade=='W')
		gradePoint = 5;
	else if(grade=='I')
		gradePoint = 6;
	return gradePoint;
}

double gpa(int n, const char grades[], const int hours[])//Takes in the number of courses n, the grades, and the hours and returns the gpa as type double.
{
	double gradeWeight = 0;//Stores the sum of the grades weighted by hour.
	double gpa;//Stores the calculated gpa.
	int hourSum = 0;//Stores the sum of the hours
	int gradeNum;//Stores the numerical value of a grade.
	for (int num = 0; num<n; num++)//loops through each value in grades and adds to the appropriate sums.
	{
		gradeNum = gradeConvert(grades[num]);//Converts the grade to a numerical value.
		if((gradeNum != 5) && (gradeNum != 6))//If grade is not W or I its weighted grade and number of hours is added to the sums.
		{
			gradeWeight = gradeWeight + (gradeNum * hours[num]);
			hourSum = hourSum + hours[num];
		}
		else//When grade is W or I nothing is added to the sums.
		{
			gradeWeight = gradeWeight;
			hourSum = hourSum;
		}
	}
	gpa = gradeWeight/hourSum;//Gpa is calculated by dividing the grade sum by the hour sum.
	return gpa;//Gpa is returned as type double.
}

double semesterGpa(int n, const string times[], const char grades[], const int hours[], string semester)//Takes in the number of courses n, the times, grades, hours, and the semester for gpa calculation and returns a gpa of type double.
{
	char gradesP[10];//Stores the grade values for the courses in the specified semester.
	int hoursP[10];//Stores the hours for the courses in the specified semester.
	double semesterGpa;//Stores the gpa for the specified semester.
	bool hasCourse = false;//Stores the validity of a particular semester containing any courses.
	for(int num = 0; num < n; num++)//loops through the semesters to find a match and stores the values in the appropriate arrays.
	{
		if(times[num] == semester)//If the two semester values match then the grade and hours at that point are stored in the new arrays.
		{
			gradesP[num] = grades[num];
			hoursP[num] = hours[num];
			hasCourse = true;//It can be assumed at this point that there are courses in the specified semester
		}
		else//If the course at this point is not in the specified semester it is treated as a withdrawn course and is not calculated in the gpa.
		{
			gradesP[num] = 'W';
			hoursP[num] = 0;
		}
	}
	semesterGpa = gpa(n, gradesP, hoursP);//calls the gpa function giving it the total number of courses and the new grades and hours arrays that contain valid values only for the specified semester.
	if(!hasCourse)//returns -1 if no courses are found
		return -1;
	else//returns gpa for that semester if courses are found.
		return semesterGpa;
}

int DRule(int n, char grades[], int hours[])//Calculates the number of courses for which a grade of D was earned. Takes in the number of courses, grades, and hours and returns an integer value.
{
	int dHours = 0;//Stores the sum of the hours for which a grade of D was earned.
	for(int num = 0; num < n; num++)//loops through each course in grades and adds the hours for that course to the sum if that grade is D.
	{
		if(grades[num] == 'D')
			dHours = dHours + hours[num];
	}
	return dHours;//Returns the total number of hours with grade D.
}

void print(int n, string names[], string times[], string numbers[], char grades[], int hours[])//Takes in the total number of courses, names, times, numbers, grades, and hours and prints these values out.
{
	cout << "The following are your courses in input format:\n" << n << "\n";
	for(int i = 0; i<n; i=i+1)//loops through each course in the arrays and prints the values out as they were entered.
	{
		cout << names[i] << "\n";
		cout << times[i] << "\n";
		cout << numbers[i] << "\n";
		cout << grades[i] << "\n";
		cout << hours[i] << "\n";
	}
}

void getCourse(string& name, string& time, string& number, char& grade, int& hours, int n)//Takes in the total number of courses, and the reference to a specific point in the arrays for times, numbers, grades, and hours, and stores user input in these variables.
{
	bool valid = true;
	cin.clear();
	cin.ignore(256, '\n');
	std::cout << "Enter the course name (e.g. Programming Foundations I) for your class number " << n + 1 << std::endl;//Requests course name
	std::getline(std::cin, name);
	std::cout << "Enter the time taken (e.g Spring 2016) your class number " << n+1 << std::endl;
	std::getline(std::cin, time);
	std::cout << "Enter the course number (e.g. CSCE 2004) for your class number " << n+1 << std::endl;//Requests course number
	std::getline(std::cin, number);
	while(valid)//repeats until user enters valid grade.
	{
		valid = false;
		cout << "Enter the grade (A,B,C,D,F,W,I) for your class number " << n+1 << "\n";//Requests course grade
		cin >> grade;
		if((grade!='A')&&(grade!='B')&&(grade!='C')&&(grade!='D')&&(grade!='F')&&(grade!='W')&&(grade!='I'))//error checking for grade input.
		{
			valid = true;
			cout << "You did not enter A or B or C or D or F or W or I, please try again.\n";
		}
	}
	valid = true;
	while(valid)//loops until user inputs a valid number of hours.
	{
		valid = false;
		cout << "Enter hours (1..5) for your class number " << n+1 << "\n";//Requests amount of hours.
		cin >> hours;
		if((hours<1)||(hours>5))//error checking for hours input.
		{
			valid = true;
			cout << "You did not enter hours within 1 and 5, please try again\n";
		}
	}
}
			
char menu()//Presents the menu options and returns the menu choice chosen as a type char.
{
	char menuOp;//Stores the chosen menu option.
	bool valid = true;
	while(valid)//Loops until a valid menu option is chosen.
	{
		valid = false;
		cout << "\n" << "Welcome to the interactive menu driven part of the system.\n" << "Please Enter the character next to the choice you wish to pick.\n" << "Here are your options:\n" << "A(a). Compute the GPA of all courses\n" << "B(b). List all courses\n" << "C(c). Compute the total credit hours of the courses with grade D\n" << "D(d). Compute the GPA for a particular semester\n" << "E(e). Add another course to the course list\n" << "Q(q). Quit the program\n" << "\n" << "Please choose one of the above:\n";
		cin >> menuOp;
		if(!((menuOp=='A')||(menuOp=='a')||(menuOp=='B')||(menuOp=='b')||(menuOp=='C')||(menuOp=='c')||(menuOp=='D')||(menuOp=='d')||(menuOp=='E')||(menuOp=='e')||(menuOp=='Q')||(menuOp=='q')))//error checking for menu option input.
		{
			valid = true;
			cout << "You did not type A,a,B,b,C,c,D,d,E,e, or Q,q please try again\n";
		}
	}
	return menuOp;//Returns the menu option choice.
}

int main()
{
	int courseAmt;//Stores the total number of choices.
	std::string names[10];//Stores the course names for each course
	std::string numbers[10];//Stores the course numbers for each course.
	std::string times[10];//Stores the semster each course was taken.
	char grades[10];//Stores the letter grade for each course.
	int hours[10];//Stores the number of hourse each course was taken.
	bool valid = true;
	char menuOp;//Stores the menu choice of the user.
	double totalGpa;//Stores the gpa for all courses.
	
	cout << "Welcome to PFI course management system v1\n";
	cout << "Enter the number of classes for the system\n";
	cin >> courseAmt;
	while((courseAmt <= 0)||(courseAmt > 10)||(cin.fail()))//error chekcing for amount of courses to be entered.
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Please enter only positive Integers less than 10.\n";
		cout << "Enter the number of classes for the system\n"; 
		cin >> courseAmt;
	}
	for(int i = 0; i<courseAmt; i++)//Calls getCourse for the number of courses the user wants to enter.
	{
		getCourse(names[i], times[i], numbers[i], grades[i], hours[i], i);
	}
	while(valid)//loops the menu until menu option Q is chosen.
	{
		menuOp = menu();
		if((menuOp == 'A')||(menuOp == 'a'))//When option A is chosen it calls the gpa function and displays the value of gpa.
		{
			totalGpa = gpa(courseAmt, grades, hours);
			if(totalGpa >= 3.0)
				cout << "\n" << "Congratulations, your GPA was " << totalGpa << "\n";
			else
				cout << "\n" << "Sorry dude, your GPA was " << totalGpa << "\n";
		}
		else if((menuOp == 'B')||(menuOp == 'b'))//When option B is chosen it calls the print function.
		{
			print(courseAmt, names, times, numbers, grades, hours);
		}
		else if((menuOp == 'C')||(menuOp == 'c'))//When option C is chosen it calls the dHours function and prints the value that dHours returns.
		{
			int dHours = 0;
			dHours = DRule(courseAmt, grades, hours);	
			cout << "Total hours with D grades are " << dHours << "\n";
		}
		else if((menuOp == 'D')||(menuOp == 'd'))//When D is chosen it asks the user to enter a semster and calls the semesterGpa function and prints the gpa that it returns.
		{
			double gpa;
			cin.clear();
			cin.ignore(256, '\n');
			std::string semesterP;
			std::cout << "Please enter the semester time (e.g. Fall 2014)" << "\n";
			std::getline(std::cin, semesterP);
			gpa = semesterGpa(courseAmt, times, grades, hours, semesterP);
			if(gpa < 0)//If the function returns -1 it means no courses were taken in that semester so this prints a message stating that.
			{
				cout << "You did not take any course in " << semesterP << endl;
			}
			else//Prints the gpa for that semester.
			{
				if(gpa >= 3.0)
					cout << "\n" << "Congratulations, your GPA was " << gpa << "\n";
				else
					cout << "\n" << "Sorry dude, your GPA was " << gpa << "\n";
			}
		}
		else if((menuOp == 'E')||(menuOp == 'e'))//If option E is chosen it calls the getCourse function and adds one to the total number of courses.
		{
			if(courseAmt < 10)
			{
				getCourse(names[courseAmt], times[courseAmt], numbers[courseAmt], grades[courseAmt], hours[courseAmt], courseAmt);
				courseAmt = courseAmt + 1;
			}
			else
			{
				cout << "No more room to store another course, sorry." << endl;
			}
		}
		else if((menuOp == 'Q')||(menuOp == 'q'))//If option Q is chosen it terminates the loop and the program.
		{
			valid = false;
			cout << "Thank you for using the system, terminating...\n";
			return 1;
		}
	}
}

