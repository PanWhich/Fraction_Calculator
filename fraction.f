#ifndef FRACTION_H
#define FRACTION_H
#include <string>
#include <iostream>
using namespace std;
//fraction class
class Fraction
{
	public:
		Fraction();
		void setsign(const string&);
		void setwhole(const int);
		void settop(const int);
		void setbottom(const int);
		string getsign (void) const;
		int getwhole (void) const;
		int gettop (void) const;
		int getbottom (void) const;
		void display(void)const;
		void improper ();
		void reduce ();
		friend Fraction operator+(Fraction&,Fraction&);
	 	friend Fraction operator-(Fraction&,Fraction&);
		friend Fraction operator*(Fraction&,Fraction&);
		friend Fraction operator/(Fraction&,Fraction&);
		friend ostream& operator<<(ostream&,Fraction&);
  		friend istream& operator>>(istream&,Fraction&);
	private:
		string sign;
		int whole;
		int top;
		int bottom;
	};

// Problem classes and its derived class
class Problem
{
public:
  Problem();
  virtual void calculate();
  virtual void display ()const;
  Fraction getleftfrac()const;
  void setleftfrac (const Fraction&);
  void setrightfrac (const Fraction&);
  Fraction getrightfrac()const;
  Fraction getanswer()const;
  void setanswer (const Fraction&);
private:
  Fraction leftfrac;
  Fraction rightfrac;
  Fraction answer;
};
//add
class AddProblem:public Problem
{
public:
   virtual void calculate (void);
   virtual void display ()const;
private:
  
};
//subtract
class SubProblem:public Problem
{
public:
   virtual void calculate (void);
   virtual void display ()const;
private:
  
};
//multiply
class MultProblem:public Problem
{
public:
  virtual void calculate (void);
  virtual void display ()const;
private:
  
};
//divide
class DivideProblem:public Problem
{
public:
  virtual void calculate (void);
  virtual void display ()const;
private:
};

#endif
