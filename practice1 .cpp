/*==============================================================
 Created by: Junya Zhao
 Last modified date :	1/30/2018
 Program:  8 function calculator
 The program will display on the screen a menu of the eight operations telling the user to enter 
 +, -, *, /, ^, l, !, or q to specify the operation to be performed. The program will read the
 operation from the keyboard. If the user enters a q the execution will terminate. Otherwise, 
 the program will display on the screen a prompt for the first operand, which it will then read 
 from the keyboard. If the operation requires two operands then the program will display on the 
 screen a prompt for the second operand which it will then read from the keyboard. The program will
 then compute the result of performing the specified operation using the operand(s) provided and output 
 this result. The program should repeat this behavior until the user specifies the q operation.
	Loop:
1.	Display MENU via cout.
2.	Read the operator from cin.
3.	If the operator is q, terminate the loop. Otherwise continue with the following:
4.	Display a prompt for the first operand via cout.
5.	Read the operand from cin.
6.	If the operator is a binary operator:
a.	Display a prompt for the second operand via cout.
b.	Read operand 2 from cin.
7.	Compute result using operand 1, the operator and operand 2.
8.	Output result.
9.	If and invalid operator is entered display an error message and return 0.
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



