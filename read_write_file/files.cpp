// This program uses hours, pay rate, state tax and fed tax to determine gross
// and net pay.

// Junya Zhao
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	fstream payfile;
	// Fill in the code to define payfile as an input file

	float gross;
	float net;
	float hours;
	float payRate;
	float stateTax;
	float fedTax;

	cout << fixed << setprecision(2) << showpoint;

	// Fill in the code to open payfile and attach it to the physical file
	// named payroll.dat
    payfile.open("payroll.dat", ios::in);
	// Fill in code to write a conditional statement to check if payfile
	// does not exist.
	if (payfile.fail())
	{
		cout << "Error opening file. \n";
		cout << "It may not exist where indicated" << endl;
		return 1;
	}

    else
    {
    cout << "Payrate Hours GrossPay	NetPay" << endl << endl;
    // Fill in code to prime the read for the payfile file.

	// Fill in code to write a loop condition to run while payfile has more
	// data to process.
    fstream outfile("pay.out", ios::out);
	while (payfile)
	{
		payfile >> payRate >> hours >> stateTax >> fedTax;

		gross = payRate * hours;

		net = gross - (gross * stateTax) - (gross * fedTax);

		cout << payRate << setw(15) << hours << setw(12) << gross
			 << setw(12) << net << endl;

    outfile << payRate << " " << hours <<" "<< gross << " " << net << endl ;
    }
       // payfile.close();
        //payfile.open("payroll.dat", ios::in);
        //while (payfile)
        //{
            // Fill in the code to finish this with the appropriate variable to be input
         //payfile >> payRate >> hours >> gross >> net;


        //}
        payfile.close();
        outfile.clear();

    }


	return 0;
}
