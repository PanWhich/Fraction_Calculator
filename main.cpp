
#include "fraction.h"
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
int main(int argc, char**agrv) 
{
	Problem*ptr=0;
	Fraction templeftfrac, temprightfrac, tempanswer;
	AddProblem ap;
	SubProblem sp;
	MultProblem mp;
	DivideProblem dp;
	string whole,top,bottom,temp;
	string sign;
	Fraction f1,f2;
	int selection;

do
{
	//main menu
	cout << "" <<endl;
	cout << "Fraction Calculator Main menu :D" << endl;
	cout << "1. Enter left fraction" << endl;
	cout << "2. Enter right fraction" << endl;
	cout << "3. Add Fractions" << endl;
	cout << "4. Subtract Fractions" << endl;
	cout << "5. Multiply Fractions" << endl;
	cout << "6. Divide Fractions" << endl;
	cout << "7. Exit Calculator" << endl;
	cout << "Enter slection: " << endl;
	while(!(cin >> selection) || cin.peek() != '\n')
    {
     cout << "Please enter an INTEGER: ";
     cin.clear();
     cin.ignore(30000, '\n');            
    }
    cin.get();
	switch(selection)
	{
		case 1:
			{
				//setting left fraction
				cout <<"example -1 1/2"<<endl;
				cout <<"enter the fraction: ";
				cin>>f1;
				break;
			}
		case 2:
			{
				//setting right fraction
				cout <<"example -1 1/2"<<endl;
				cout <<"enter the fraction: ";
				cin>>f2;
				break;
			}
		case 3:
			{
				//adding fraction
				
				ptr=&ap;
				ptr->setleftfrac(f1);
				ptr->setrightfrac(f2);
				ptr->calculate();
				ptr->display();
				
				break;
			}
		case 4:
			{
				//subtracting fraction
				ptr=&sp;
				ptr->setleftfrac(f1);
				ptr->setrightfrac(f2);
				ptr->calculate();
				ptr->display();
				break;
			}
		case 5:
			{
				//multiplying fraction
				ptr=&mp;
				ptr->setleftfrac(f1);
				ptr->setrightfrac(f2);
				ptr->calculate();
				ptr->display();
				break;
			}
		case 6:
			{
				//dividing fraction
				ptr=&dp;
				ptr->setleftfrac(f1);
				ptr->setrightfrac(f2);
				ptr->calculate();
				ptr->display();
				break;
			}
		case 7:
			{
				//ending program
				cout << "Thank you for using our fraction calculator" << endl;
				break;
			}
		};
}
while(selection != 7);
return 0;
}

