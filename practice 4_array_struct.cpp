#include <iostream>
#include <iomanip>
using namespace std;

// This program demonstrates how to use an array of structures

// Junya Zhao

// Fill in code to declare a structure called taxPayer that has three
// members:	taxRate, income, and taxes — each of type float
struct taxPayer
{
    float taxaRate;
    float income;
    float taxes;
};

int main()
{
	// Fill in code to define an array named citizen which holds
	// 5 taxPayers structures
    taxPayer citizen[5];

    cout << fixed << showpoint << setprecision(2);

	cout << "Please enter the annual income and tax rate for 5 tax payers: ";

	cout << endl << endl << endl;

	for (int count = 0; count < 5; count++)
	{

		cout << "Enter this year's income for tax payer " << (count + 1);
		cout << ": ";
        cin  >> citizen[count].income; // read in the income to the appropriate place

		cout << "Enter the tax rate for tax payer # " << (count + 1);
		cout << ": ";
        cin  >> citizen[count].taxaRate; // read in the tax rate to the appropriate place
        citizen[count].taxes = (citizen[count].taxaRate)*(citizen[count].income);// compute the taxes for the citizen and store it in the appropriate place
		cout << endl;
	}

	cout << "Taxes due for this year: " << endl << endl;
	for (int index= 0; index < 5; index++)   // a loop that will output the tax information
	{
		cout << "Tax Payer # " << (index + 1) << ": " << "$ " << citizen[index].taxes << endl;
	}

	return 0;
}
