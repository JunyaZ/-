#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

// Junya Zhao

int main()
{
	fstream inFile("proverb.txt", ios::in);
	long offset;
	char ch;
	char more;

	do
	{
		// Fill in the code to write to the screen
		// the current read position (with label)
        long whereIm = inFile.tellp();
        cout << "The real position is currently at byte: " << whereIm <<endl;
		cout << "Enter an offset from the current read position: ";
		cin >> offset;
        //	Fill in the code to move the read position “offset” bytes
		//	from the CURRENT read position.
        inFile.seekg(offset-1, ios::cur);
        //	Fill in the code to get one byte of information from the file
		//	and place it in the variable "ch".
        inFile.seekg(1L, ios::cur);
        inFile.get(ch);


		cout << "The character read is " << ch << endl;
		cout << "If you would like to input another offset enter a Y"
			 << endl;
		cin >> more;

		// Fill in the code to clear the eof flag.
        inFile.clear();

	} while (toupper(more) == 'Y');

	inFile.close();

	return 0;
}
