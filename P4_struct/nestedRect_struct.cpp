#include <iostream>
#include <iomanip>
using namespace std;

/*This program uses a structure to hold data about a rectangle
 It calculates the area and perimeter of a box*/

// Junya Zhao
struct dimensions //declare a structure named dimensions that contains 2 float members, length and width

{
    float length;
    float width;
};

struct rectangle //declare a structure named rectangle that contains 3 members, area, perimeter, and sizes.
{
    float area;
    float perimeter;
    dimensions sizes;
};

int main()
{
	rectangle box;// Fill in code to define a rectangle structure variable named box.
	cout << "Enter the length of a rectangle: ";
    cin >> box.sizes.length;
	// Fill in code to read in the length to the appropriate location
	cout << "Enter the width of a rectangle: ";
    cin >> box.sizes.width;
	// Fill in code to read in the width to the appropriate location
	cout << endl << endl;
	box.area = box.sizes.length * box.sizes.width; // compute the area
	box.perimeter = 2*(box.sizes.length+ box.sizes.width);//  compute the perimeter
	cout << fixed << showpoint << setprecision(2);

	cout << "The area of the rectangle is " << box.area << endl;

	cout << "The perimeter of the rectangle is " << box.perimeter<< endl;

	return 0;
}
