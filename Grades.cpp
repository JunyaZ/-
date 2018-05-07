#include <fstream> // FILL IN DIRECTIVE FOR FILES
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// This program reads records from a file. The file contains the
// following: student’s name, two test grades and final exam grade.
// It then prints this information to the screen.

// Junya  Zhao
const int NAMESIZE = 15;
const int MAXRECORDS = 50;

struct Grades	// declares a structure
{
	char name[NAMESIZE + 1];
	int test1;
	int test2;
	int final;
	char letter;
};

typedef struct Grades gradeType;
// This makes gradeType a data type
// that holds MAXRECORDS
// Grades structures.
void ReadIt(ifstream &,gradeType *, int &);
// FIll IN THE CODE FOR THE PROTOTYPE OF THE FUNCTION ReadIt
// WHERE THE FIRST ARGUMENT IS AN INPUT FILE, THE SECOND IS THE
// ARRAY OF RECORDS, AND THE THIRD WILL HOLD THE NUMBER OF RECORDS
// CURRENTLY IN THE ARRAY.
char letter(int ,int , int );
int main()
{
	ifstream indata;

	indata.open("graderoll.dat");

	int numRecord;	// number of records read in

	gradeType studentRecord[MAXRECORDS];

	if (!indata)
	{
		cout << "Error opening file. \n";
		cout << "It may not exist where indicated" << endl;

		return 1;
	}

	// FILL IN THE CODE TO CALL THE FUNCTION ReadIt.
    ReadIt( indata, studentRecord, numRecord);
	// output the information
	for (int count = 0; count < numRecord; count++)
	{
		 cout << studentRecord[count].name << setw(10)
			 << studentRecord[count].test1
			 << setw(10) << studentRecord[count].test2;
		cout << setw(10) << studentRecord[count].final << endl;
		studentRecord[count].letter = letter(studentRecord[count].test1,studentRecord[count].test2,studentRecord[count].final);
	}

	// Exercise 2
	cout<<endl;
	for (int count = 0; count < numRecord; count++)
	{
		 cout << studentRecord[count].name << setw(10)
			 << studentRecord[count].test1
			 << setw(10) << studentRecord[count].test2
			 << setw(10) << studentRecord[count].final;
		cout << setw(10) << studentRecord[count].letter<< endl;
	}
	return 0;
}

//**************************************************************
//	readIt
//
//	task:	  This procedure reads records into an array of
//	          records from an input file and keeps track of the
//	          total number of records
//	data in:  data file containing information to be placed in
//	          the array
//	data out: an array of records and the number of records
//
//**************************************************************

void ReadIt(ifstream &inData, gradeType *gradeRec, int &total)
            // FILL IN THE CODE FOR THE FORMAL PARAMETERS AND THEIR
	        // DATA	TYPES.
	        // inData, gradeRec and total are the formal parameters
	        // total is passed by reference)
{
	total = 0;

	inData.get(gradeRec[total].name, NAMESIZE);

	while (inData)
	{
		// FILL IN THE CODE TO READ test1
        inData >> gradeRec[total].test1;
		// FILL IN THE CODE TO READ test2
        inData >> gradeRec[total].test2;
		// FILL IN THE CODE TO READ final
        inData >> gradeRec[total].final;
		total++;	// add one to total

		// FILL IN THE CODE TO CONSUME THE END OF LINE
		char ch;
		inData.get(ch);
		// FILL IN THE CODE TO READ name
		inData.get(gradeRec[total].name, NAMESIZE);
	}
}
char letter(int test1,int test2, int final)
{
	int avg = 0.3*test1 + 0.3*test2 +0.4*final;
	if(avg>=90)
		return 'A';
	if(avg>=80)
		return 'B';
	if(avg>=70)
		return 'C';
	if(avg>=60)
		return 'D';
	return 'F';
}
