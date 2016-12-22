#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Student
{
public:
   Student();
   Student(const Student & original);
   ~Student();

   void set(const int uaid, const string name, const double gpa);
   void get(int & uaid, string & name, double & gpa) const;
   void print() const;
   void read();

private:
   int mUaid;
   string mName;
   double mGpa;
};

Student::Student()
{
   mUaid = 0;
   mName = "none";
   mGpa  = 0.0;
}

Student::Student(const Student & original)
{
   mUaid = original.mUaid;
   mName = original.mName;
   mGpa  = original.mGpa;
}

Student::~Student()
{
}

void Student::set(const int uaid, const string name, const double gpa)
{
   mUaid = uaid;
   mName = name;
   mGpa = gpa;
   if (mGpa < 0.0)      mGpa = 0.0;
   else if (mGpa > 4.0) mGpa = 4.0;
}

void Student::get(int &uaid, string & name, double &gpa) const
{
   uaid = mUaid;
   name = mName;
   gpa  = mGpa;
}

void Student::print() const
{
   cout << mUaid << " " << mName << " " << mGpa << endl;
}

void Student::read()
{
   cin >> mUaid >> mName >> mGpa;
   if (mGpa < 0.0)      mGpa = 0.0;
   else if (mGpa > 4.0) mGpa = 4.0;
}

class Course
{
public:
   Course(const int count=0);
   Course(const Course & original);
   ~Course();

   void print() const;
   void read();
   void topStudents(double gpa);

private:
   static const int MAX_STUDENTS = 100;
   Student mStudents[MAX_STUDENTS];
   int mNumStudents;
};

Course::Course(const int count)
{
   cout << "Constructor" << endl;
   mNumStudents = count;
}

Course::Course(const Course & original)
{
   cout << "Copy constructor" << endl;
   mNumStudents = original.mNumStudents;
   for (int i = 0; i < mNumStudents; i++)
   {
      mStudents[i] = original.mStudents[i];
   }
}

Course::~Course()
{
   cout << "Destructor" << endl;
}

void Course::print() const
{
   cout << "Print" << endl;
   for(int i = 0; i < mNumStudents; i++)
   {
      mStudents[i].print();
   }
}

void Course::read()
{
   cout << "Read" << endl;
   for(int i = 0; i< mNumStudents; i++)
   {
      mStudents[i].read();
   }
}

void Course::topStudents(double gpa)
{
   cout << "topStudents" << endl;
   int id;
   string name;
   double mGpa;
   for(int i = 0; i < mNumStudents; i++)
   {
      mStudents[i].get(id, name, mGpa);
      if(mGpa >= gpa)
      {
         mStudents[i].print();
      }
   }
}

int main()
{
   cout << "Testing Student class\n";
   Student student1;
   student1.set(1234, "John", 2.5);
   student1.print();

   cout << "Testing Course class\n";
   Course course(5);
   course.print();
   course.read();
   course.print();
   course.topStudents(3.5);
   return 0;
}
/*
Output:
cdwood@turing:~/CSCE2004/labs/lab12$ ./lab12c < Students.txt
Testing Student class
1234 John 2.5
Testing Course class
Constructor
Print
0 none 0
0 none 0
0 none 0
0 none 0
0 none 0
Read
Print
1234 Susan 3.9
2345 John 3.2
3456 Laura 3.8
4567 Brian 3.5
5678 David 3.1
topStudents
1234 Susan 3.9
3456 Laura 3.8
4567 Brian 3.5
Destructor
*/
