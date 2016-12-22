#include <iostream>
#include <string>
using namespace std;
 
int main()
{
	int courseAmt;//This variable stores the number of courses the user wishes to enter.
	std::string courseName[10];//Stores the name of the course.
	std::string courseNum[10];//Stores the course number.
	std::string semester[10];//Stores the semester the course was taken.
	char charIn;//This variable stores the letter grade that the user inputs.
	char menuOp;//This variable stores the menu choice that the user enters.
	int grade[10];//Stores the course grade as a number
	int hours[10];//Stores the course hours.
	double gpa;//This variable stores the final computed gpa.
	double gradeWeight;//This variable stores the total grade points weighted by credit hour.
	int hourSum=0;//This variable stores the total number of credit hours.

	cout << "Welcome to PFI course management system v1\n";//Welcomes user to program

	cout << "Enter the number of classes for the system\n"; //Requests number of courses to be entered.
	cin >> courseAmt;
	//Checks to see if user input is valid.
	while((courseAmt<=0)||(courseAmt > 10)||(cin.fail()))
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Please enter only positive Integers less than 10.\n";
		cout << "Enter the number of classes for the system\n"; 
		cin >> courseAmt;
	}
	//Removes any remaining input from input stream.
	cin.clear();
	cin.ignore(256, '\n');

	//Requests user to enter information for each course. Loops until info has been gathered for each course.
	for(int num = 0; num<courseAmt; num=num+1)
	{
		std::cout << "Enter the course name (e.g. Programming Foundations I) for your class number " << num+1 << std::endl;//Requests course name
		std::getline(std::cin, courseName[num]);
		std::cout << "Enter the time taken (e.g Spring 2016) your class number " << num+1 << std::endl;
		std::getline(std::cin, semester[num]);
		std::cout << "Enter the course number (e.g. CSCE 2004) for your class number " << num+1 << std::endl;//Requests course number
		std::getline(std::cin, courseNum[num]);
		cout << "Enter the grade (A,B,C,D,F,W,I) for your class number " << num+1 << "\n";//Requests course grade
		cin >> charIn;
		bool valid = false;//test case for while loop.
		//Checks to see if grade entered is valid and assigns it a value.
		while(!valid)
		{
			valid = true;
			if(charIn=='A')
				grade[num] = 4;
			else if(charIn=='B')
				grade[num] = 3;
			else if(charIn=='C')
				grade[num] = 2;
			else if(charIn=='D')
				grade[num] = 1;
			else if(charIn=='F')
				grade[num] = 0;
			else if(charIn=='W')
				grade[num] = 5;
			else if(charIn=='I')
				grade[num] = 6;
			else
			{
				valid = false;
				cin.clear();
				cin.ignore(256, '\n');
				cout << "You did not enter A or B or C or D or F or W or I, please try again.\n";
				cout << "Enter the grade (A,B,C,D,F,W,I) for your class number " << num+1 << "\n";
				cin >> charIn;
			}
		}

		valid = false;
		cout << "Enter hours (1..5) for your class number " << num+1 << "\n";//Requests number of hours for course
		cin >> hours[num];
		//Checks to see if number of hours is valid
		while(!valid)
		{
			valid = true;
			if((hours[num]>=1)&&(hours[num]<=5));
			else
			{
				valid = false;
				cin.clear();
				cin.ignore(256, '\n');
				cout << "You did not enter hours within 1 and 5, please try again\n";
				cout << "Enter hours (1..5) for your class number " << num+1 << "\n";
				cin >> hours[num];
			}
		}

		//adds grade and hours to gradeWeight and hourSum. Does not add anything if grade=5 becuase it is I or W in this case.
		if((grade[num] != 5)|| (grade[num] != 6))
		{
			gradeWeight = gradeWeight + (grade[num]*hours[num]);
			hourSum = hourSum + hours[num];
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

	//Menu portion of program.
	bool valid = false;
	while(!valid)
	{
		//Displays menu options and stores user's choice.
		cout << "\n" << "Welcome to the interactive menu driven part of the system.\n" << "Please Enter the character next to the choice you wish to pick.\n" << "Here are your options:\n" << "A(a). Compute the GPA of all courses\n" << "B(b). List all courses\n" << "C(c). Compute the total credit hours of the courses with grade D\n" << "D(d). Compute the GPA for a particular semester\n" << "E(e). Add another course to the course list\n" << "Q(q). Quit the program\n" << "\n" << "Please choose one of the above:\n";
		cin >> menuOp;
		//Scenario for menu option A. Calculates GPA as previous programs did.
		if((menuOp=='A')||(menuOp=='a'))
		{
			gpa = gradeWeight/hourSum;//Calculates the final gpa.

			//Outputs gpa
			if(gpa >= 3.0)
				cout << "\n" << "Congratulations, your GPA was " << gpa << "\n";
			else
				cout << "\n" << "Sorry dude, your GPA was " << gpa << "\n";
		}
		//Scenario for menu option B. Loops through and displays courses as they were input.
		else if((menuOp=='B')||(menuOp=='b'))
		{
			cout << "The following are your courses in input format:\n" << courseAmt << "\n";
			for(int i = 0; i<courseAmt; i=i+1)//loops through each variable in each array and prints it out in order.
			{
				cout << courseName[i] << "\n";
				cout << semester[i] << "\n";
				cout << courseNum[i] << "\n";
				//Converts numerical grade value back to character grade value
				if(grade[i] == 4)
					cout << 'A' << "\n";
				else if(grade[i] == 3)
					cout << 'B' << "\n";
				else if(grade[i] == 2)
					cout << 'C' << "\n";
				else if(grade[i] == 1)
					cout << 'D' << "\n";
				else if(grade[i] == 0)
					cout << 'F' << "\n";
				else if(grade[i] == 5)
					cout << 'W' << "\n";
				else if(grade[i] == 6)
					cout << 'I' << "\n";
				else
					cout << "No grade for this course\n";
				cout << hours[i] << "\n";
			}
		}
		//Scenario for menu option C. Determines the number of hours for which a grade of D was earned.
		else if((menuOp == 'C')||(menuOp == 'c'))
		{
			int dHours = 0;
			for(int i = 0; i<courseAmt; i=i+1)//loops through each variable in grade array and adds the number of hours for that course to a sum whihc is printed at the end.
			{
				if(grade[i] == 1)
					 dHours = dHours + hours[i];
			}
			cout << "Total hours with D grades are " << dHours << "\n";//Displays hours in which D was earned.
		}
		//Scenario for menu option D. Calculates the GPA for a specific semester
		else if((menuOp == 'D')||(menuOp == 'd'))
		{
			double gradeWeightP = 0;
			int hourSumP = 0;
			cin.clear();
			cin.ignore(256, '\n');
			std::string semesterP;
			//Requests and stores the semester that the user wishes to calculate GPA for.
			std::cout << "Please enter the semester time (e.g. Fall 2014)" << "\n";
			std::getline(std::cin, semesterP);
			for(int i = 0; i<courseAmt; i = i+1)//loops through every variable in semester and finds those that match the semester the user desires.
			{
				if(semester[i]==semesterP)
				{
					if((grade[i] != 5)|| (grade[i] != 6))//creates sums of the weigted grades and hours for each course in those semesters.
					{
						gradeWeightP = gradeWeightP + (grade[i]*hours[i]);
						hourSumP = hourSumP + hours[i];
					}
					else
					{
						gradeWeightP = gradeWeightP;
						hourSum = hourSumP;
					}
				}
			}
			//Calculates GPA or lets the user know no courses were found for that semester.
			if(gradeWeightP==0)
				cout << "You did not take any course in " << semesterP << endl;
			else
			{
				gpa = gradeWeightP/hourSumP;
				if(gpa >= 3.0)
					cout << "\n" << "Congratulations, your GPA was " << gpa << "\n";
				else
					cout << "\n" << "Sorry dude, your GPA was " << gpa << "\n";
			}
		}
		//Scenario for menu option E. Walks the user through entering information for another course and stores it in the appropriat variables.
		else if((menuOp=='E')||(menuOp=='e'))
		{
			if(courseAmt < 10)
			{
				cin.clear();
				cin.ignore(256, '\n');
				std::cout << "Enter the course name (e.g. Programming Foundations I) for your class number " << courseAmt+1 << std::endl;//Requests course name
				std::getline(std::cin, courseName[courseAmt]);
				std::cout << "Enter the time taken (e.g Spring 2016) your class number " << courseAmt+1 << std::endl;
				std::getline(std::cin, semester[courseAmt]);
				std::cout << "Enter the course number (e.g. CSCE 2004) for your class number " << courseAmt+1 << std::endl;//Requests course number
				std::getline(std::cin, courseNum[courseAmt]);
				cout << "Enter the grade (A,B,C,D,F,W,I) for your class number " << courseAmt+1 << "\n";//Requests course grade
				cin >> charIn;
				bool valid = false;//test case for while loop.
				//Checks to see if grade entered is valid and assigns it a value.
				while(!valid)
				{
					valid = true;
					if(charIn=='A')
						grade[courseAmt] = 4;
					else if(charIn=='B')
						grade[courseAmt] = 3;
					else if(charIn=='C')
						grade[courseAmt] = 2;
					else if(charIn=='D')
						grade[courseAmt] = 1;
					else if(charIn=='F')
						grade[courseAmt] = 0;
					else if(charIn=='W')
						grade[courseAmt] = 5;
					else if(charIn=='I')
						grade[courseAmt] = 6;
					else
					{
						valid = false;
						cin.clear();
						cin.ignore(256, '\n');
						cout << "You did not enter A or B or C or D or F or W or I, please try again.\n";
						cout << "Enter the grade (A,B,C,D,F,W,I) for your class number " << courseAmt+1 << "\n";
						cin >> charIn;
					}
				}
	
				valid = false;
				cout << "Enter hours (1..5) for your class number " << courseAmt+1 << "\n";//Requests number of hours for course
				cin >> hours[courseAmt];
				//Checks to see if number of hours is valid
				while(!valid)
				{
					valid = true;
					if((hours[courseAmt]>=1)&&(hours[courseAmt]<=5));
					else
					{
						valid = false;
						cin.clear();
						cin.ignore(256, '\n');
						cout << "You did not enter hours within 1 and 5, please try again\n";
						cout << "Enter hours (1..5) for your class number " << courseAmt+1 << "\n";
						cin >> hours[courseAmt];
					}
				}

				//adds grade and hours to gradeWeight and hourSum. Does not add anything if grade=5 becuase it is I or W in this case.
				if((grade[courseAmt] != 5)|| (grade[courseAmt] != 6))
				{
					gradeWeight = gradeWeight + (grade[courseAmt]*hours[courseAmt]);
					hourSum = hourSum + hours[courseAmt];
				}
				else
				{
					gradeWeight = gradeWeight;
					hourSum = hourSum;
				}
				courseAmt = courseAmt + 1;
			}
			//Lets the user know that the arrays that store course information are full. 
			else
				cout << "No room to store another course, sorry." << endl;
		}
		//Scenario for menu option Q which terminates the program.
		else if((menuOp=='Q')||(menuOp=='q'))
		{
			valid = true;
			cout << "Thank you for using the system, terminating...\n";
			return 1;
		}
		else
			cout << "You did not type A,a,B,b,C,c,D,d,E,e, or Q,q please try again\n";
	}
	return 0;
}
