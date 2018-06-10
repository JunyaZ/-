#include <iostream>
#include <string>
#include "Fraction.h"

using namespace std;

int main()
{
    //Test for calling the default constructor
    cout << " Test for calling the default constructor"<< endl;
    Fraction f1;
    f1.displayFraction();
    cout<< "================"<< endl;

    //Test for calling the constructor with two ints
    cout << " Test for calling the constructor with two ints" << endl;
    Fraction f2(2,3);
    f2.displayFraction();
    cout<< "===================="<< endl;

    //Test for calling the copy constructor
    cout << " Test for calling the copy constructor" << endl;
    Fraction f_C(2,3);
    Fraction f_(f_C);
    f_.displayFraction();
    f_.setter(5,13);
    f_.displayFraction();
    f_C.displayFraction();
    cout<< "===================="<< endl;

    //Test for setter and getter
    Fraction f3;
    f3.setter(8,9); // setter
    cout << " get Numerator : " << f3.getmyNumerator() << endl;
    cout << "  get Denominator:" << f3.getmyDenominator()<< endl;
    cout<< "================"<< endl;



    // Test for the toString function
    cout << " display fraction :";
    f2.toString(2,3);
    cout<< "================"<< endl;


    //Test the overload operator " == " and  "!="
    Fraction x0(1,2);
    Fraction y0(1,2);
    cout <<" are they equal? yes is 0,  no is 0. The answer is :" << (x0 == y0) << endl;
    cout <<" are they equal? yes is 0,  no is 0. The answer is :" << (x0 != y0) << endl;
    //c0.toString(c0.getmyNumerator(),c0.getmyDenominator());


    //Test the overload operator " + "
    Fraction a0(1,2);
    Fraction b0(3,4);
    Fraction c0;
    c0 = a0 + b0;
    cout << " The result is ";
    c0.toString(c0.getmyNumerator(),c0.getmyDenominator());


    //Test the overload operator " - "
    Fraction a1(1,2);
    Fraction b1(3,4);
    Fraction c1;
    c1 = a1 - b1;
    cout << " The result is ";
    c1.toString(c1.getmyNumerator(),c1.getmyDenominator());


     //Test the overload operator " * "
    Fraction a2(1,2);
    Fraction b2(3,9);
    Fraction c2;
    c2 = a2 * b2;
    cout << " The result is ";
    c2.toString(c2.getmyNumerator(),c2.getmyDenominator());



    //Test the overload operator " * "
    cout << "simplified answer is : " <<endl;
    c2.simplify();


    //Test the overload operator " << " and  ">>"
   Fraction d1(13, 10), d2(5, 11), d3;
   cout << "Enter the fraction";
   cout << " first type in Numerator/ second type in Denominator) :" << endl;
   cin >> d3;
   cout << "First Fraction is  : " << d1 << endl;
   cout << "Second Fraction is :" << d2 << endl;
   cout << "Third Fraction is :" << d3 << endl;
    return 0;
}
