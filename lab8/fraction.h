#ifndef FRACTION_H
#define FRACTION_H
#include<iostream>
#include <algorithm>
#include <string>


class Fraction
{
    private:
        int myNumerator ;
        int myDenominator;
    public:
        Fraction();
        Fraction(int,int);
        Fraction(const Fraction & );
        int getmyNumerator();
        int getmyDenominator();
        void setter(int,int);
        void toString(int,int);
        bool operator==( const Fraction &);
        bool operator!=(const Fraction &);
        Fraction operator+(Fraction);
        Fraction operator-(Fraction);
        Fraction operator*(Fraction);
        void simplify();
        friend std::ostream &operator <<( std::ostream &, const Fraction&);
        friend std::istream &operator >>( std::istream &, Fraction &);
        void displayFraction();
};
#endif
