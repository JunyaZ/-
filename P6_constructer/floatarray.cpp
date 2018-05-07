// This program reads floating point data from a data file and places those
// values into the private data member called values (a floating point array)
// of the FloatList class. Those values are then printed to the screen.
// The input is done by a member function called GetList. The output
// is done by a member function called PrintList. The amount of data read in
// is stored in the private data member called length. The member function
// GetList is called first so that length can be initialized to zero.

// Jumya Zhao

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX_LENGTH=50;// MAX_LENGTH contains the maximum length of our list
class FloatList					// Declares a class that contains an array of								// floating point numbers
{
public:
	void getList(ifstream&);	// Member function that gets data from a file
	void printList(); //const;		// Member function that prints data from that
	float Showaverage(); 							// file to the screen.

	FloatList();				// constructor that sets length to 0.
	~FloatList();				// destructor

private:
	int length;					//	Holds the number of elements in the array
	float values[MAX_LENGTH];	//	The array of values

};

int main()
{
	ifstream tempData;	// Defines a data file
	FloatList temperatures;// Fill in the code to define an object called list of the class FloatList
	cout << fixed << showpoint;
	cout << setprecision(2);
	tempData.open("temperatures.txt");
    temperatures.getList(tempData);// Fill in the code that calls the getList function.
    temperatures.printList();// Fill in the code that calls the printList function.
    cout  << " The average temperature is " << temperatures.Showaverage();
	return 0;
}

FloatList::FloatList()
{
	length =0;// fill in the code to complete this constructor that
	// sets the private data member length to 0
}

// Fill in the entire code for the getList function
// The getList function reads the data values from a data file
// into the values array of the class FloatList
void FloatList::getList(ifstream &filename)
{
    int i =0;
    while (filename)
        {
        filename >> values[i];
        i++;
        }
    length = i-1;
}
// Fill in the entire code for the printList function
// The printList function prints to the screen the data in
// the values array of the class FloatList
void FloatList:: printList()
{
    for (int i = 0; i< length; i++)
    {
         cout << values[i]<< endl;
    }
}
float FloatList::Showaverage()
{
    float sum, avg;
    for (int i = 0; i < length; i++)
    {
        sum += values[i];
    }
    avg = sum/length;

    return avg;
}

FloatList:: ~FloatList(void)
{
}
