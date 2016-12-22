#include <iostream>
#include <string>
using namespace std;

// Interface for Temperature class
class Temperature
{
public:
   Temperature();
   Temperature(const Temperature & Temp);
   ~Temperature();
   double getCelsius() const;
   double getFahrenheit() const;
   void setCelsius(double Temp);
   void setFahrenheit(double Temp);
   void print();
   void read();

private:
   static const double ABSOLUTE_ZERO = -273.15;
   double CelsiusTemperature;
   std::string input;
};

// Implementation of Temperature class
Temperature::Temperature()
{
   CelsiusTemperature = 0;
}

Temperature::Temperature(const Temperature & Temp)
{
   CelsiusTemperature = Temp.CelsiusTemperature;
}

Temperature::~Temperature()
{
}

double Temperature::getCelsius() const
{
   return CelsiusTemperature;
}

double Temperature::getFahrenheit() const
{
   return 9.0 * CelsiusTemperature / 5.0 + 32.0;
}

void Temperature::setCelsius(double Temp)
{
   CelsiusTemperature = Temp;
   if (CelsiusTemperature < ABSOLUTE_ZERO)
      CelsiusTemperature = ABSOLUTE_ZERO;
}

void Temperature::setFahrenheit(double Temp)
{
   CelsiusTemperature = (Temp - 32.0) * 5.0 / 9.0 ;
   if (CelsiusTemperature < ABSOLUTE_ZERO)
      CelsiusTemperature = ABSOLUTE_ZERO;
}

void Temperature::print()
{
   cout << (9.0 * CelsiusTemperature / 5.0 + 32.0) << "F = " << CelsiusTemperature << "C\n";
}

void Temperature::read()
{
   cin >> CelsiusTemperature;
   std::getline(std::cin, input);
   if((input.find("F", 0) != -1)||(input.find("f", 0) != -1))
   {
      CelsiusTemperature = (CelsiusTemperature - 32.0) * 5.0 / 9.0;
   }
   else if((input.find("C",0) != -1)||(input.find("c",0) != -1))
   {
      CelsiusTemperature = CelsiusTemperature;
   }
   else
   {
      CelsiusTemperature = -300.0;
   }
}

// Program to test Temperature class
int main()
{
   Temperature Start;
   Temperature End;
   cout << "Enter start temperature: ";
   Start.read();
   cout << "Enter end temperature: ";
   End.read();

   if((Start.getCelsius() == -300.0)||(End.getCelsius() == -300.0))
      return -1;

   cout.precision(3);
   for (double F = Start.getFahrenheit(); F <= End.getFahrenheit(); F++)
   {
      Temperature Temp;
      Temp.setFahrenheit(F);
      Temp.print();
   }
   return 0;
}
/*
Output:
Enter start temperature: 75 D
Enter end temperature: 85 Z
cdwood@turing:~/CSCE2004/labs/lab11$ ./lab11c
Enter start temperature: 75 F
Enter end temperature: 85 F
75F = 23.9C
76F = 24.4C
77F = 25C
78F = 25.6C
79F = 26.1C
80F = 26.7C
81F = 27.2C
82F = 27.8C
83F = 28.3C
84F = 28.9C
85F = 29.4C

Enter start temperature: 30 C
Enter end temperature: 60 C
86F = 30C
87F = 30.6C
88F = 31.1C
89F = 31.7C
90F = 32.2C
91F = 32.8C
92F = 33.3C
93F = 33.9C
94F = 34.4C
95F = 35C
96F = 35.6C
97F = 36.1C
98F = 36.7C
99F = 37.2C
100F = 37.8C
101F = 38.3C
102F = 38.9C
103F = 39.4C
104F = 40C
105F = 40.6C
106F = 41.1C
107F = 41.7C
108F = 42.2C
109F = 42.8C
110F = 43.3C
111F = 43.9C
112F = 44.4C
113F = 45C
114F = 45.6C
115F = 46.1C
116F = 46.7C
117F = 47.2C
118F = 47.8C
119F = 48.3C
120F = 48.9C
121F = 49.4C
122F = 50C
123F = 50.6C
124F = 51.1C
125F = 51.7C
126F = 52.2C
127F = 52.8C
128F = 53.3C
129F = 53.9C
130F = 54.4C
131F = 55C
132F = 55.6C
133F = 56.1C
134F = 56.7C
135F = 57.2C
136F = 57.8C
137F = 58.3C
138F = 58.9C
139F = 59.4C
140F = 60C

Enter start temperature: 50 V
Enter end temperature: 70 Z
cdwood@turing:~/CSCE2004/labs/lab11$ 
*/
