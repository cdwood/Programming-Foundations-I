#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Course
{
public:
	Course(); //default constructor
	
	void get(string& name, string& time, string& number, char& g, int& h) const;
	void getName(string& name)const;
	void getGrade(char& g)const;
	void getHours(int& h) const;
	void getNumber(string& number) const;
	void set(string name, string time, string number, char g, int h);
	void setGrade(char g);
	void setHours(int h);
	void print() const;

private:
	string courseName;
	string courseTime;
	string courseNumber;
	char grade;
	int hours;
};

Course::Course()//Default constructor sets all variables to default values
{
	courseName = "";
	courseTime = "Fall 2015";
	courseNumber = "CSCE 2004";
	grade = 'A';
	hours = 4;
}

void Course::get(string& name, string& time, string& number, char& g, int& h) const //get method takes in variables and sets them to the value of the corresponding variables for that course object to be used throughout the program.
{
	name = courseName;
	time = courseTime;
	number = courseNumber;
	g = grade;
	h = hours;
}
void Course::getGrade(char& g) const//finds the grade of the course and stores it in the variable passed to it.
{
	g = grade;
}
void Course::getHours(int& h) const//finds the hours of the course and stores it in the variable passed to it.
{
	h = hours;
}
void Course::getName(string& name)const//finds the name of the course and stores it in the variable passed to it.
{
	name = courseName;
}
void Course::getNumber(string& number) const//finds the number of the course and stores it in the variable passed to it.
{
	number = courseNumber;
}

void Course::set(string name, string time, string number, char g, int h) //set takes in values and assigns them to the corresponding variables for that course object. 
{
	courseName = name;
	courseTime = time;
	courseNumber = number;
	grade = g;
	hours = h;
}
void Course::setGrade(char g)
{
	grade = g;
}
void Course::setHours(int h)
{
	hours = h;
}

void Course::print() const //print prints the value of each variable in the course object to the display.
{
	cout << courseName << endl;
	cout << courseTime << endl;
	cout << courseNumber << endl;	
	cout << grade << endl;
	cout << hours << endl;
}

class Requirement
{
public:
	Requirement();
	void getGroup(string& gp) const;
	void set(string group, string subgroup, int hoursReq);
	void addCourse(string name, int h);
	bool match(Course course);
	bool met();
	void print() const;
private:
	string group;//Stores the group of the requirement.
	string subgroup;//Stores the subgroup of the requirement.
	int hoursReq;//Stores the hours required to meet the requirement.
	string names[50];//Stores the names of the courses that can be used to meet the requirement.
	int hours[50];//Stores the hours for each course that can be used to meet the requirement.
	Course matched[20];//Stores eached course that has been used as a match for the requiremtn.
	int numberMatched;//Stores the number of courses in matched array.
	int hoursEarned;//Stores the number of hours earned for this requirement.
	int coursesIn;//Stores the number of courses that can be used to meet the requirement.
};

Requirement::Requirement()//Initiates the variables of the requirement.
{
	group = "";
	subgroup = "";
	hoursReq = 0;
	for(int i = 0; i<50; i++)
	{
		names[i] = "";
		hours[i] = 0;
	}
	numberMatched = 0;
	hoursEarned = 0;
	coursesIn = 0;
}
void Requirement::getGroup(string& gp) const//finds the group of the requirement and stores it in the variable passed to it.
{
	gp = group;
}
void Requirement::set(string grp, string subgrp, int hoursRq)//Sets the group, subgroup, and hours required for the requirement
{
	group = grp;
	subgroup = subgrp;
	hoursReq = hoursRq;
}
void Requirement::addCourse(string name, int h)//Adds a course to the requirement
{
	names[coursesIn] = name;
	hours[coursesIn] = h;
	coursesIn++;
}
bool Requirement::match(Course course)//determines if a course matches any of the courses in the requirement and adds if it does it adds it to the matched array of courses
{
	string n;
	course.getNumber(n);
	for(int i = 0; i<=coursesIn; i++)
	{
		if(n==names[i])
		{
			hoursEarned = hoursEarned + hours[i];
			matched[numberMatched] = course;
			numberMatched++;
			return true;
		}
	}
	return false;
}
bool Requirement::met()//Determines if the requirement was met.
{
	if(hoursReq == hoursEarned)
		return true;
	else
		return false;
}
void Requirement::print() const//prints out the details of the requirement
{
	if(hoursReq <= hoursEarned)
	{
		cout << group << " " << subgroup << " requirement is met by:\n";
		for(int i = 0; i < numberMatched; i++)
		{
			matched[i].print();
		}
	}
	else if(hoursEarned > 0)
	{
		cout << group << " " << subgroup << " requirement is partially met by (hours still needed " << hoursReq-hoursEarned << ")\n";
		for(int i = 0; i < numberMatched; i++)
		{
			matched[i].print();
		}
	}
	else
	{
		cout << group << " " << subgroup << " requirement is not met at all.\n";
	}
}
		
bool isPass(Course course)//determines if a passing grade was earned for a course
{
	char g;
	course.getGrade(g);
	if(g!='F' && g!='W' && g!='I')
		return true;
	else
		return false;	
}

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

void isDuplicate(Course courses[], Course course, int n, int cLoc, Course& best)//finds all duplicates of a course and determines the one with the highest grade.
{
	string name, nameT;
	char g, gt;
	course.getName(name);
	course.getGrade(g);
	best = course;
	for(int i = 0; i < n; i++)
	{
		courses[i].getName(nameT);
		if((name == nameT)&&(i!=cLoc))
		{
			courses[i].getGrade(gt);
			if((gradeConvert(gt)>gradeConvert(g))&&(gradeConvert(gt)!=5)&&(gradeConvert(gt)!=6))
			{
				best = courses[i];
				g = gt;
			}
		}
	}
}

bool validated(Course course, Course valid[], int n)//Determines if a course is in an array.
{
	string name, nameT;
	course.getName(name);
	for(int i = 0; i<n; i++)
	{
		valid[i].getName(nameT);
		if(name==nameT)
			return true;
	}
	return false;
}

bool degreeAudit(const char filename[], Course courses[], int n)//Runs a degree audit on the University Core course requirements.
{
	Requirement requirements[30];//Stores all requirements stored in the requirements file.
	Requirement reqByGroup[30];//Stores all requirements in University Core.
	Course valid[n];//Stores the courses that can be used to satisfy requirements.
	Course coursesUsed[20];//Stores the courses used to meet a requirement.
	string group, subgroup, courseNumber;
	int hoursReq, hours;
	int used = 0;//Stores the number of courses that have been used on a requirement.
	int index = 0;//Stores the number of requirements stored.
	int valI = 0;//Stores the number of courses that can be used to satisfy requirements.
	int reqIndex = 0;//Stores the number of requirements stored for University Core requirements
	fstream infile;
	infile.open(filename);
	if(infile.fail())
	{
		cout << "Failed to open file named: " << filename << endl;
		return false;
	}
	getline(infile, group);//gets the group of the first requirement
	while(!(infile.eof()))//reads in each requirement and stores it in a requirement object while there is still content in the requirements file.
	{
		getline(infile, subgroup);//gets the subgroup of the requirement
		infile >> hoursReq;//gets the amount of hours needed to meet the course requirement
		requirements[index].set(group, subgroup, hoursReq);//sets the values of the requirement
		infile.ignore(256, '\n');//clears the input stream
		getline(infile, courseNumber);//gets the course number of the first course in course requirements
		while((!(infile.eof()))&&(courseNumber!=""))//gets the hours and course number of each course in the requirement list while the line is not blank
		{
			infile>>hours;//stores the number of hours in hours variable
			requirements[index].addCourse(courseNumber, hours);//adds the course to the requirement
			infile.ignore(256, '\n');//clears the input stream
			getline(infile, courseNumber);//gets the course number of the next course
		}
		index++;//increases the index for the requirements array
		getline(infile, group);//gets the group for the next requirement
	}
	for(int i = 0; i < index; i++)//Creating an array filled with only Universitys Core requirements.
	{
		string thisGroup;
		requirements[i].getGroup(thisGroup);
		if(thisGroup == "University Core")
		{
			reqByGroup[reqIndex] = requirements[i];
			reqIndex++;
		}
	}
	for(int i = 0; i < n; i++)//Creating an array filled with only valid courses
	{
		if(!(validated(courses[i], valid, valI)))
		{		
			if(isPass(courses[i]))
			{
				isDuplicate(courses, courses[i], n, i, valid[valI]);
				valI++;
			}	
		}
	}
	for(int i = 0; i < valI; i++)//Checks for matches between the valid courses and the requirements.
	{
		for(int j = 0; j < reqIndex; j++)
		{
			if((!(reqByGroup[j].met())&&(!(validated(valid[i], coursesUsed, used)))))	
			{
				if(reqByGroup[j].match(valid[i]))
				{
					coursesUsed[used] = valid[i];
					used++;
				}
			}
		}
	}
	for(int i = 0; i < reqIndex; i++)//Prints out all requirements tested.
	{
		reqByGroup[i].print();
		cout << endl;
	}
	return true;
}

double gpa(int n, const Course courses[])//Takes in the number of courses n, the grades, and the hours and returns the gpa as type double.
{
	string name, time, number;
	char g;
	int h;
	double gradeWeight = 0;//Stores the sum of the grades weighted by hour.
	double gpa;//Stores the calculated gpa.
	int hourSum = 0;//Stores the sum of the hours
	int gradeNum;//Stores the numerical value of a grade.
	for (int num = 0; num<n; num++)//loops through each value in grades and adds to the appropriate sums.
	{
		courses[num].get(name, time, number, g, h);
		gradeNum = gradeConvert(g);//Converts the grade to a numerical value.
		if((gradeNum != 5) && (gradeNum != 6))//If grade is not W or I its weighted grade and number of hours is added to the sums.
		{
			gradeWeight = gradeWeight + (gradeNum * h);
			hourSum = hourSum + h;
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

double semesterGpa(int n, const Course courses[], string semester)//Takes in the number of courses n, the times, grades, hours, and the semester for gpa calculation and returns a gpa of type double.
{
	string name, time, number;
	char g;
	int h;
	Course coursesP[80];
	double semesterGpa;//Stores the gpa for the specified semester.
	bool hasCourse = false;//Stores the validity of a particular semester containing any courses.
	for(int num = 0; num < n; num++)//loops through the semesters to find a match and stores the values in the appropriate arrays.
	{
		courses[num].get(name, time, number, g, h);
		if(time == semester)//If the two semester values match then the grade and hours at that point are stored in the new arrays.
		{
			coursesP[num] = courses[num];
			hasCourse = true;//It can be assumed at this point that there are courses in the specified semester
		}
		else//If the course at this point is not in the specified semester it is treated as a withdrawn course and is not calculated in the gpa.
		{
			coursesP[num].setGrade('W');
			coursesP[num].setHours(0);
		}
	}
	semesterGpa = gpa(n, coursesP);//calls the gpa function giving it the total number of courses and the new grades and hours arrays that contain valid values only for the specified semester.
	if(!hasCourse)//returns -1 if no courses are found
		return -1;
	else//returns gpa for that semester if courses are found.
		return semesterGpa;
}

int DRule(int n, Course courses[])//Calculates the number of courses for which a grade of D was earned. Takes in the number of courses, grades, and hours and returns an integer value.
{
	char g;
	int h;
	int dHours = 0;//Stores the sum of the hours for which a grade of D was earned.
	for(int num = 0; num < n; num++)//loops through each course in grades and adds the hours for that course to the sum if that grade is D.
	{
		courses[num].getGrade(g);
		courses[num].getHours(h);
		if(g == 'D')
			dHours = dHours + h;
	}
	return dHours;//Returns the total number of hours with grade D.
}

void print(int n, Course courses[])//Takes in the total number of courses, names, times, numbers, grades, and hours and prints these values out.
{
	string name, time, number;
	char g;	
	int h;
	cout << "The following are your courses in input format:\n" << n << "\n";
	for(int i = 0; i<n; i=i+1)//loops through each course in the arrays and prints the values out as they were entered.
	{
		courses[i].get(name, time, number, g, h);
		cout << name << "\n";
		cout << time << "\n";
		cout << number << "\n";
		cout << g << "\n";
		cout << h << "\n";
	}
}

void getCourse(Course& courses, int n)//Takes in the total number of courses, and the reference to a specific point in the arrays for times, numbers, grades, hours, and courses, and stores user input in these variables.
{
	bool valid = true;
	string name, time, number;
	char g;
	int h;
	cin.clear();
	cin.ignore(256, '\n');
	std::cout << "Enter the course name for your class number " << n + 1 << std::endl;//Requests course name
	std::getline(std::cin, name);
	std::cout << "Enter the time taken your class number " << n+1 << std::endl;
	std::getline(std::cin, time);
	std::cout << "Enter the course number for your class number " << n+1 << std::endl;//Requests course number
	std::getline(std::cin, number);
	while(valid)//repeats until user enters valid grade.
	{
		valid = false;
		cout << "Enter the grade (A,B,C,D,F,W,I) for your class number " << n+1 << "\n";//Requests course grade
		cin >> g;
		if((g!='A')&&(g!='B')&&(g!='C')&&(g!='D')&&(g!='F')&&(g!='W')&&(g!='I'))//error checking for grade input.
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
		cin >> h;
		if((h<1)||(h>5))//error checking for hours input.
		{
			valid = true;
			cout << "You did not enter hours within 1 and 5, please try again\n";
		}
	}
	courses.set(name, time, number, g, h);//sets the value of this specific course object to the values being stored in the parallel arrays.
}

bool removeCourse(Course courses[], int& n)//takes in the array for name, time, number, grade, hours, and courses, as well as the value for the number courses and removes a course specified by the user.
{
	string name, time, number;
	char g;
	int h;
	int courseChoice;//stores the number of the course the user wishes to delete
	char yesNo;//stores the user's menu choices
	bool valid = true;
	while(valid)//asks the user which course they would like to delete with error checking
	{
		valid = false;
		cout << "Select from 1 to " << n << " for the course to be deleted" << endl;
		cin >> courseChoice;
		if(courseChoice > n)
		{
			valid = true;
		}
	}
	//displays the informaiton of the course the user has selected.
	cout << "Here is the course you have selected for deletion:\n";
	cout << "Course number " << courseChoice << endl;
	courses[courseChoice-1].get(name, time, number, g, h);
	cout << name << endl;
	cout << time << endl;
	cout << number << endl;
	cout << g << endl;
	cout << h << endl;
	valid = true;
	while(valid)//confirms the user's choice and deletes the course
	{
		cout << "Would you like to delete the course above?\n";
		cout << "Please enter y for yes and n for no\n";
		cin >> yesNo;
		if(yesNo == 'y')//Deletes the course by setting the values of this course to the values of the last course in the arrays and decreases the number of courses stored by one.
		{
			courses[courseChoice-1] = courses[n-1];
			/*name[courseChoice-1] = name[n-1];
			time[courseChoice-1] = time[n-1];
			number[courseChoice-1] = number[n-1];
			grade[courseChoice-1] = grade[n-1];
			hours[courseChoice-1] = hours[n-1];
			courses[courseChoice-1].set(name[courseChoice-1], time[courseChoice-1], number[courseChoice-1], grade[courseChoice-1], hours[courseChoice-1]);//removes the course from the array of course objects as well.*/
			n=n-1;
			valid = false;
		}
		else if(yesNo == 'n')
		{
			valid = false;
			return false;
		}
		else
		{
			cout << "The character you entered is " << yesNo << " that is not y or n\n";
		}
	}
	return true;
}
			
char menu()//Presents the menu options and returns the menu choice chosen as a type char.
{
	char menuOp;//Stores the chosen menu option.
	bool valid = true;
	while(valid)//Loops until a valid menu option is chosen.
	{
		valid = false;
		cout << "\n" << "Welcome to the interactive menu driven part of the system.\n" << "Please Enter the character next to the choice you wish to pick.\n" << "Here are your options:\n" << "A(a). Compute the GPA of all courses\n" << "B(b). List all courses\n" << "C(c). Compute the total credit hours of the courses with grade D\n" << "D(d). Compute the GPA for a particular semester\n" << "E(e). Add another course to the course list.\n" << "F(f). Delete a course from the list.\n" << "G(g). Degree Audit\n" << "Q(q). Quit the program\n" << "\n" << "Please choose one of the above:\n";
		cin >> menuOp;
		if(!((menuOp=='A')||(menuOp=='a')||(menuOp=='B')||(menuOp=='b')||(menuOp=='C')||(menuOp=='c')||(menuOp=='D')||(menuOp=='d')||(menuOp=='E')||(menuOp=='e')||(menuOp=='F')||(menuOp=='f')||(menuOp=='G')||(menuOp=='g')||(menuOp=='Q')||(menuOp=='q')))//error checking for menu option input.
		{
			valid = true;
			cout << "You did not type A,a,B,b,C,c,D,d,E,e,F,f,G,g, or Q,q please try again\n";
		}
	}
	return menuOp;//Returns the menu option choice.
}

bool reading(const char filename[], Course courses[], int& n, int capacity)//takes in a filename to be read, the arrays for name, time, number, grade, hours, and courses, as well as the number of objects in these arrays and the capacities of these arrays.
{
	string name, time, number;
	char g;
	int h;
	fstream infile;
	infile.open(filename);
	if(infile.fail())//verifies fiel input is possible
	{
		cout << "failed to open file named: " << filename << endl;
		return false;
	}
	infile >> n;
	if(n>capacity)//chekcs to make sure there is enough space in the arrays to store the information in the file
	{
		cout << "insufficient space in the arrays!" << endl;
		return false;
	}
	for(int i = 0; i<n; i++)//takes in teh value and stores it in the arrays for each piece of information in the file.
	{
		infile.ignore(256, '\n');
		getline(infile,name); 
		getline(infile,time);
		getline(infile,number);
		infile >> g;
		if((g!='A')&&(g!='B')&&(g!='C')&&(g!='D')&&(g!='F')&&(g!='W')&&(g!='I'))
		{
			cout << "Grade for course " << number << " is invalid." << endl;
			return false;
		}
		infile >> h;
		if((h < 1)||(h > 5))
		{
			cout << "Hours for course " << number << " are not within 1 and 5.";
			return false;
		}
		courses[i].set(name, time, number, g, h);//stores the information that is stroed in the parallel arrays at this instance in the very same instance of course object in the course array.
	}
	infile.close();
	return true;
}

bool writing(const char filename[], const Course courses[], int n)//Takes in a filename as well as the arrays for name, time, number, grade, and hours, along with the variable that stores the number of items stored in these arrays.
{
	string name, time, number;
	char g;
	int h;
	ofstream outfile;
	outfile.open(filename);
	if(outfile.fail())//verifies the output file can be opened.
	{
		cout << "failed to open file named: " << filename << endl;
		return false;
	}
	outfile << n << "\n";
	for(int i = 0; i < n; i++)//outputs every piece of informaiton in the arrays to the output file as it was input.
	{
		courses[i].get(name, time, number, g, h);
		outfile << name << "\n";
		outfile << time << "\n";
		outfile << number << "\n";
		outfile << g << "\n";
		outfile << h << "\n";
	}
	outfile.close();
	return true;
}

int main()
{
	int courseAmt;//Stores the total number of choices.
	Course courses[80];
	//std::string names[10];//Stores the course names for each course
	//std::string numbers[10];//Stores the course numbers for each course.
	//std::string times[10];//Stores the semster each course was taken.
	//char grades[10];//Stores the letter grade for each course.
	//int hours[10];//Stores the number of hourse each course was taken.
	bool valid = true;
	char menuOp = true;//Stores the menu choice of the user.
	double totalGpa;//Stores the gpa for all courses.
	string filename = "courses.txt";
	
	cout << "Welcome to PFI course management system v1\n";
	while(valid)//asks if the user wants to use an input file or manual input and acts accordingly
	{
		cout << "Would you like to read the courses taken from a file?\n";
		cout << "Please enter y for yes and n for no\n";
		cin >> menuOp;
		if(menuOp == 'y')
		{
			valid = true;
			while(valid)//asks if the user wants to use the default file or specify a file and acts accordingly
			{
				cout << "Would you like to use the default file?\n";
				cout << "Please enter y for yes and n for no\n";
				cin >> menuOp;
				if(menuOp == 'y')
				{
					if(!(reading(filename.c_str(), courses, courseAmt, 80)))
					{
						cout << "Error in reading the default file, terminating...\n";
						return 1;
					}
					else
					{
						cout << "File input was successful. Please review the courses." << endl;
						print(courseAmt, courses);
					}
					valid = false;
				}
				else if(menuOp == 'n')
				{
					cout << "Enter your file name\n";
					cin >> filename;
					if(!(reading(filename.c_str(), courses, courseAmt, 80)))
					{
						cout << "Error in reading the input file, terminating...\n";
						return 1;
					}
					else
					{
						cout << "File input was successful. Please review the courses." << endl;
						print(courseAmt, courses);
					}
					valid = false;
				}
				else
				{
					cout << "The character you entered is " << menuOp << " that is not y or n\n";
					cin.clear();
					cin.ignore(256, '\n');
				}
			}
			valid = false;
		}
		else if(menuOp == 'n')
		{
			cout << "Interactive mode was selected.\n";
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
				getCourse(courses[i], i);
			}
			valid = false;
		}
		else
		{
			cout << "The character you entered is " << menuOp << " that is not y or n\n";
		}
	}
	valid = true;
	while(valid)//loops the menu until menu option Q is chosen.
	{
		menuOp = menu();
		if((menuOp == 'A')||(menuOp == 'a'))//When option A is chosen it calls the gpa function and displays the value of gpa.
		{
			totalGpa = gpa(courseAmt, courses);
			if(totalGpa >= 3.0)
				cout << "\n" << "Congratulations, your GPA was " << totalGpa << "\n";
			else
				cout << "\n" << "Sorry dude, your GPA was " << totalGpa << "\n";
		}
		else if((menuOp == 'B')||(menuOp == 'b'))//When option B is chosen it calls the print function.
		{
			print(courseAmt, courses);
		}
		else if((menuOp == 'C')||(menuOp == 'c'))//When option C is chosen it calls the dHours function and prints the value that dHours returns.
		{
			int dHours = 0;
			dHours = DRule(courseAmt, courses);	
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
			gpa = semesterGpa(courseAmt, courses, semesterP);
			if(gpa < 0)//If the function returns -1 it means no courses were taken in that semester so this prints a message stating that.
			{
				cout << "You did not take any course in " << semesterP << endl;
			}
			else//Prints the gpa for that semester.
			{
				if(gpa >= 3.0)
					cout << "\n" << "Congratulations, your GPA was " << gpa << " " << semesterP << "\n";
				else
					cout << "\n" << "Sorry dude, your GPA was " << gpa << " " << semesterP << "\n";
			}
		}
		else if((menuOp == 'E')||(menuOp == 'e'))//If option E is chosen it calls the getCourse function and adds one to the total number of courses.
		{
			if(courseAmt < 80)
			{
				getCourse(courses[courseAmt], courseAmt);
				courseAmt = courseAmt + 1;
				cout << "Please review the updated courses below\n";
				print(courseAmt, courses);
			}
			else
			{
				cout << "No more room to store another course, sorry." << endl;
			}
		}
		else if((menuOp == 'F')||(menuOp == 'f'))//If option F is chosen it calls the removeCourse function and removes a couse of the user's selection from the arrays.
		{
			if(removeCourse(courses, courseAmt))
			{
				cout << "Please review the updated courses below\n";
				print(courseAmt, courses);
			}
		}	
		else if((menuOp == 'G')||(menuOp == 'g'))//Asks for a file where degree requirements are stored and runs a degree audit.
		{
			filename = "";
			cout << "Enter the file name of your degree audit file.\n";
			cin >> filename;
			degreeAudit(filename.c_str(), courses, courseAmt);
		}
		else if((menuOp == 'Q')||(menuOp == 'q'))//If option Q is chosen it terminates the loop and the program.
		{
			if(!(writing("courses.txt", courses, courseAmt)))//calls writing and outputs all information in the arrays to "courses.txt"
			{
				cout << "Error in writing to the output file. Terminating..." << endl;
				return 1;
			}
			valid = false;
			cout << "Thank you for using the system, terminating...\n";
			return 1;
		}
	}
}

