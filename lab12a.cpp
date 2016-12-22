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
   cout << "Constructor" << endl;
   mUaid = 0;
   mName = "none";
   mGpa  = 0.0;
}

Student::Student(const Student & original)
{
   cout << "Copy constructor" << endl;
   mUaid = original.mUaid;
   mName = original.mName;
   mGpa  = original.mGpa;
}

Student::~Student()
{
   cout << "Destructor" << endl;
}

void Student::set(const int uaid, const string name, const double gpa)
{
   cout << "Set" << endl;
   mUaid = uaid;
   mName = name;
   mGpa  = gpa;
}

void Student::get(int & uaid, string & name, double & gpa) const
{
   cout << "Get" << endl;
   uaid = mUaid;
   name = mName;
   gpa  = mGpa;
}

void Student::print() const
{
   cout << "Print" << endl;
   cout << mUaid << " " << mName << " " << mGpa << endl;
}

void Student::read()
{
   cout << "Read" << endl;
   cin >> mUaid >> mName >> mGpa;
   if(mGpa < 0.0)
      mGpa = 0.0;
   else if(mGpa > 4.0)
      mGpa = 4.0;
}

int main()
{
   cout << "Testing Student class\n";
   Student student1;
   student1.set(1234, "John", 2.5);
   student1.print(); 
   Student student2(student1);
   student2.print();
   student2.set(2345, "Susan", 3.9);
   student2.print();
   Student student3;
   student3.read();
   student3.print();
   return 0;
}
/*
Output:
Testing Student class
Constructor
Set
Print
1234 John 2.5
Copy constructor
Print
1234 John 2.5
Set
Print
2345 Susan 3.9
Constructor
Read
3456 Brian 5.5
Print
3456 Brian 4
Destructor
Destructor
Destructor
cdwood@turing:~/CSCE2004/labs/lab12$ ./lab12a
Testing Student class
Constructor
Set
Print
1234 John 2.5
Copy constructor
Print
1234 John 2.5
Set
Print
2345 Susan 3.9
Constructor
Read
3456 Brian -2.5
Print
3456 Brian 0
Destructor
Destructor
Destructor
*/
