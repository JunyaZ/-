/*==============================================================
 course: CSC232 Lab1
 Created by: Junya Zhao
 Last modified date :	1/30/2018
 Program:  8 function calculator
===============================================================*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int factorial(int n)
{
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}
double  caculator (char Operator, float operand1, float operand2)
{
    switch(Operator)
    {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        if(operand2!=0)
        {
            return operand1/operand2;
        }
        else
        {
            cout << "Sorry, the second operand can not be 0 ";
        }
    case '^':
        return pow(operand1,operand2);
    case 'l':
        return log10(operand1);
    case '!':
        return factorial(operand1);
    }

}
int main()
{

    char Operator;
    int operand1, operand2;
    double answer;
    string MENU =
                    " + : addition operation\n"
                    " - : subtraction operation\n"
                    " * : multiplication operation\n"
                    " / : division operation\n"
                    " ^ : exponentiation operation\n"
                    " l : base-10 logarithm operation\n"
                    " ! : factorial operation and\n"
                    " q to quit.\n"
                    "******************************** \n"
                    "Enter an a operator: ";

    cout << "Junya's 8-function caculator";
    cout << MENU;
    cin >> Operator;

            while(Operator !='q')
            {
                if (Operator == '+' || Operator == '-' || Operator == '*' || Operator == '/' || Operator == '^'|| Operator == 'l' || Operator == '!' )
                    {
                        cout <<" Enter the first operand :";
                        cin >> operand1;
                    }
                    else
                    {
                        cout << "Error: Invalid operator ";
                        break;
                    }
                if (Operator == '+' || Operator == '-' || Operator == '*' || Operator == '/' || Operator == '^')
                   {
                       cout <<" Enter the second operand :";
                       cin >> operand2;
                   }

                answer = caculator (Operator, operand1,operand2);
                cout << "The answer is : " << answer <<endl;
                cout << MENU;
                cin >> Operator;
            }
}



