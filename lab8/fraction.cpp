#include<iostream>
#include <algorithm>
#include "Fraction.h"
using namespace std;

Fraction::Fraction() //default constructor
{
    myNumerator = 0;
    myDenominator = 1;
}

Fraction::Fraction (int a, int b)
{
      myNumerator = a;
      myDenominator = b;
}

Fraction::Fraction (const Fraction &f)  //copy constuctor
{
    myNumerator = f.myNumerator;
    myDenominator = f.myDenominator;

}

int Fraction::getmyNumerator()
{
      return  myNumerator;
}

int Fraction::getmyDenominator()
{
      return myDenominator;
}

void Fraction::setter(int Numerator,int Denominator)
{
      myNumerator = Numerator;
      myDenominator = Denominator;
}

void Fraction::toString(int a,  int b)
{
    cout << a << "/" << b << endl;

}


bool Fraction:: operator==(const Fraction &right)
  {
     return (this->myDenominator == right.myDenominator && this-> myNumerator == right.myNumerator);
  }

bool Fraction:: operator!=(const Fraction &right)
  {
     return ! (this->myDenominator == right.myDenominator && this-> myNumerator == right.myNumerator);
  }


Fraction Fraction:: operator+(Fraction right)
{   Fraction result;
    result.myDenominator = myDenominator* (right.myDenominator);
    result.myNumerator = myNumerator* (right.myDenominator) + myDenominator* (right.myNumerator);
    return result;
}

Fraction Fraction:: operator-(Fraction right)
{   Fraction result;
    result.myDenominator = myDenominator* (right.myDenominator);
    result.myNumerator= myNumerator* (right.myDenominator) - myDenominator* (right.myNumerator);
    return result;
}


Fraction Fraction:: operator*(Fraction right)
{   Fraction result;
    result.myNumerator = myNumerator * (right.myNumerator);
    result.myDenominator= myDenominator * (right.myDenominator);
    return  result;
}


void Fraction:: simplify()
{
     int gcd = 0;
     gcd = __gcd(myNumerator,myDenominator);
     myNumerator = myNumerator/gcd;
     myDenominator= myDenominator/gcd;
     toString(myNumerator,myDenominator);
}

std::istream &operator >>( std::istream &input, Fraction &D )
{
    input >> D.myNumerator >> D.myDenominator;
     return input;
}

std::ostream &operator <<( std::ostream &output, const Fraction &D )
 {

    output <<  D.myNumerator << " / " << D.myDenominator;
    return output;
}

void Fraction::displayFraction()
{
	cout << "The Numerator is :" << myNumerator << endl;
	cout << "The Denominator is :" << myDenominator << endl;
}
