#include "fraction.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Fraction::Fraction()
{
                sign = "";
                whole = 0;
                top = 0;
                bottom = 1;
}
//calculate constructor
void Problem::calculate(void)
{
}
//set functions for fraction
void Fraction::setsign(const string& temp)
{
	sign = temp;
}
void Fraction::setwhole(const int temp)
{
    if(temp >= 0)
    	whole = temp;
		}
void Fraction::settop(const int temp)
{
    if(top >= 0)
    	top = temp;
		
}
void Fraction::setbottom(const int temp)
{
    if(bottom >= 1)
        bottom = temp;
}

void Problem::setrightfrac(const Fraction& temp)
{
    rightfrac = temp;
}
void Problem::setanswer(const Fraction& temp)
{
	answer = temp;
}
void Problem::setleftfrac(const Fraction& temp)
{
	leftfrac = temp;
}
//Problem constructor
Problem::Problem()
{
}
// get functions
string Fraction::getsign()const
{
    return sign;
}
int Fraction::getwhole()const
{
    return whole;
}
int Fraction::gettop()const
{
    return top;
}
int Fraction::getbottom()const
{
    return bottom;
}
Fraction Problem::getleftfrac()const
{
	return leftfrac;
}
Fraction Problem::getrightfrac()const
{
	return rightfrac;
}
Fraction Problem::getanswer()const
{
	return answer;
 } 
//display functions
void Problem::display()const
{
}
void AddProblem::display()const
{
	Fraction templeft=getleftfrac();
	Fraction tempright=getrightfrac();
	Fraction tempanswer=getanswer();
	cout<<templeft<<"+"<<tempright<<"="<<tempanswer;
}
void SubProblem::display()const
{
	Fraction templeft=getleftfrac();
	Fraction tempright=getrightfrac();
	Fraction tempanswer=getanswer();
	cout<<templeft<<"-"<<tempright<<"="<<tempanswer;
}
void MultProblem::display()const
{
	Fraction templeft=getleftfrac();
	Fraction tempright=getrightfrac();
	Fraction tempanswer=getanswer();
	cout<<templeft<<"*"<<tempright<<"="<<tempanswer;
}
void DivideProblem::display()const
{
	Fraction templeft=getleftfrac();
	Fraction tempright=getrightfrac();
	Fraction tempanswer=getanswer();
	cout<<templeft<<"/"<<tempright<<"="<<tempanswer;
}
// math functions
void Fraction::improper()
{
	int temp1=0;
    temp1=whole*bottom+top;
    whole=0;
    top=temp1;
}
void Fraction::reduce()
{
	int temp1=0;
	int temp2=0;
    temp1=top/bottom;
    temp2=top%bottom;
    whole=temp1;
    top=temp2;

}
//sub classes for add.multi.div,sub
void AddProblem::calculate()
{
	Fraction leftfrac = getleftfrac();
	Fraction rightfrac = getrightfrac();\
	Fraction tempanswer;
	tempanswer=leftfrac+rightfrac;
	setanswer(tempanswer);
}
void SubProblem::calculate()
{
	Fraction leftfrac = getleftfrac();
	Fraction rightfrac = getrightfrac();
	Fraction tempanswer;
	tempanswer=leftfrac-rightfrac;
	setanswer(tempanswer);
}
void MultProblem::calculate()
{
	Fraction leftfrac = getleftfrac();
	Fraction rightfrac = getrightfrac();
	Fraction tempanswer;
	tempanswer=leftfrac*rightfrac;
	setanswer(tempanswer);
}
void DivideProblem::calculate()
{
	Fraction leftfrac = getleftfrac();
	Fraction rightfrac = getrightfrac();
	Fraction tempanswer;
	tempanswer=leftfrac/rightfrac;
	setanswer(tempanswer);
}
//operator overloads
Fraction operator+(Fraction& leftfrac,Fraction& rightfrac)
{
	Fraction tempanswer;
    //turns into a improper
    leftfrac.improper();
    rightfrac.improper();
    //find a common den
    tempanswer.top=leftfrac.top*rightfrac.bottom+leftfrac.bottom*rightfrac.top;
    tempanswer.bottom=leftfrac.bottom*rightfrac.bottom;
    tempanswer.reduce();
    return tempanswer;
}
Fraction operator-(Fraction& leftfrac,Fraction& rightfrac)
{
	Fraction tempanswer;
	//turns into a improper
    leftfrac.improper();
    rightfrac.improper();
    //find a common den
    tempanswer.settop(leftfrac.gettop()*rightfrac.getbottom()-leftfrac.getbottom()*rightfrac.gettop());
    tempanswer.setbottom(leftfrac.getbottom() * rightfrac.getbottom());
    tempanswer.reduce();
    return tempanswer;
}
Fraction operator*(Fraction& leftfrac,Fraction& rightfrac)
{
	Fraction tempanswer;
	//improper form
	leftfrac.improper();
    rightfrac.improper();
    //calculations
    tempanswer.top=leftfrac.top*rightfrac.top;
    tempanswer.bottom=leftfrac.bottom*rightfrac.bottom;
    tempanswer.reduce();
    return tempanswer;
}
Fraction operator/(Fraction& leftfrac,Fraction& rightfrac)
{
	Fraction tempanswer;	
	//improper form
	leftfrac.improper();
    rightfrac.improper();
    //calculations
    tempanswer.top=leftfrac.top*rightfrac.bottom;
    tempanswer.bottom=leftfrac.bottom*rightfrac.top;
    tempanswer.reduce();
    return tempanswer;
}
ostream& operator <<(ostream& outp,Fraction& f1)
{
	if(f1.bottom==1)
		cout<<f1.top+f1.whole;
	else
		cout<<f1.whole<<" "<<f1.top<<"/"<<f1.bottom;
}
istream& operator >>(istream& imp,Fraction& f1)
{
	int temp1,temp2,temp3;
	string string1,sub1,sub2,sub3,sub4;
	getline(imp,string1);
	int s1=string1.find(" ",0);
		if(s1==-1)
			cout << "data not imputed correctly" << endl;
		else
		{
			sub1=string1.substr(0,s1);
			temp1=atoi(sub1.c_str());
			sub2=string1.substr(s1+1);
		int s2=sub2.find("/");
		if(s2==-1)
 			cout<<"data not imputed correctly" << endl;
	 	else
			{
			sub3=sub2.substr(0,s2);
			if(sub3.find_first_not_of("1234567890")!=-1)
				cout<<"data not imputed correctly" << endl;
			else{
				temp2=atoi(sub3.c_str());
				sub4=sub2.substr(s2+1);
				if(sub4.find_first_not_of("1234567890")!=-1)
					cout<<"data not imputed correctly" << endl;
					else{
						temp3=atoi(sub4.c_str());
					f1.setwhole(temp1);
					f1.settop(temp2);
					f1.setbottom(temp3);
						}
				}
			}
		}
		return imp;
}
