#include <iostream>
#include <iomanip>
using namespace std;

// This program uses a structure to hold data about a rectangle

// Junya Zhao

// Fill in code to declare a structure named rectangle which has
// members length, width, area, and perimeter all of which are floats

int main()
{
	// Fill in code to define a rectangle variable named box
    struct box{ float length;
                float width;
                float area;
                float perimeter;
            };
    box rectangle;

	cout << "Enter the length of a rectangle: ";

	cin >> rectangle.length;// Fill in code to read in the length member of box

	cout << "Enter the width of a rectangle: ";

	cin >> rectangle.width;// Fill in code to read in the width member of box

	cout << endl << endl;

	rectangle.area= rectangle.width * rectangle.length;// Fill in code to compute the area member of box

	rectangle.perimeter = 2*( (rectangle.width)+(rectangle.length)); // Fill in code to compute the perimeter member of box

	cout << fixed << showpoint << setprecision(2);

	cout << " The area of rectangle is : " << rectangle.area <<endl;// Fill in code to output the area with an appropriate message

	cout << " The perimeter of rectangke is : " << rectangle.perimeter << endl; // Fill in code to output the perimeter with an appropriate message

    if (rectangle.length == rectangle.width)
	cout << " The rectangle is squre ." << endl;

	return 0;
}


