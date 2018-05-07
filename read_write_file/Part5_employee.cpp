//This program that will read records from employee.in file and store them in a binary file.
//That file will then be used as input to create an output file of the information.
//The data file contains employee information consisting of name, social security, department ID, years employed, and salary.
//In addition to displaying the information of each record
//the program will also calculate the average salary and years employed of all the records.
//This additional information is stored in the same output file.

// Junya Zhao

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

const int NAMESIZE = 15;
const int SSN_size =9;


struct employee  // declare an struct hold the employee information
{
    char first_name[NAMESIZE + 1];
    char last_name[NAMESIZE + 1];
	char SSN[SSN_size];
	int depar_id;
	int years;
	float salary;
};

int main()
{

    employee person[4];
	fstream employeeIN;
	ofstream employeeOUT;
	employeeIN.open("employee.in",ios::in);
	employeeOUT.open("employee.out",ios::out);
    float totalSalary;
    float totalYear;
    float avg_salary;
	float avg_year;

    cout <<  "employee_name" << " " << "SSN " <<" "<< "department_id" << " " << "Years" << " "<< " Salary " <<endl;

   do
{
      for (int i= 0;i < 4; i++)
     {
        employeeIN >> person[i].first_name >> person[i].last_name >> person[i].SSN >> person[i].depar_id >> person[i].years >> person[i].salary;
        totalSalary += person[i].salary;
		totalYear += person[i].years;
        cout << person[i].first_name<< setw (12) << person[i].last_name << setw(12) << person[i].SSN
         << setw(12) << person[i].depar_id << setw(12)<< person[i].years << setw(12)<< person[i].salary << setw(12) << endl;
     }
     employeeIN.read((char *) (&person), sizeof(person));
     avg_salary = totalSalary/4;
     avg_year = totalYear/4;

     for( int j=0; j <4 ;j++)
     {
        employeeOUT << person[j].first_name<< setw (12) << person[j].last_name<< setw(12) << person[j].SSN
         << setw(12) << person[j].depar_id << setw(12)<< person[j].years << setw(12)<< person[j].salary << setw(12) << endl;
        char ch;
        employeeIN.get(ch);
        employeeIN.get(ch);
     }


    cout << "Avg_salary" << " " <<" Avg_year" << endl;
    cout << avg_salary << setw(12)<< avg_year << endl;\

    employeeOUT << "Avg_salary" << " " <<" Avg_year" << endl;
    employeeOUT << avg_salary << setw(12)<< avg_year << endl;
}
    while(employeeIN);

    employeeIN.close();
    employeeOUT.close();

	return 0;
}


