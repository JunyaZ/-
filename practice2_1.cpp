/****************************************************
Two arrays list1 and list2 are strictly identical if they have the same 
length and list1[i] is equal to list2[i] for each i. 

The test program that prompts the user to enter two lists of integers
and displays whether the two are strictly identical. 
Assume the list size is a maximum of 10.
****************************************************/
#include <iostream>
#include <sstream>
using namespace std;
void readArray(int a[], int n);
bool strictlyEqual(const int list1[], const int list2[], int size);

int main()
{
    int Index;
    cout << "Enter the size of you list: ";
    cin >> Index;
    if (Index <=10)
    {
        int list1[Index], list2[Index];
        cout << "Enter a one list: " << endl;
        readArray(list1, Index);
        cout << "Enter another list: " << endl;
        readArray(list2, Index);

        if (strictlyEqual(list1, list2, Index))
            cout << "The two lists are indentical!" << endl;
        else
            cout << "The two lists are not indentical!" << endl;
    }

    else cout << "Error: The Maximum size of your lists is 10!";
}

bool strictlyEqual(const int list1[], const int list2[], int size)

{
         for (int i=0; i<size; i++)
         {
             if (list1[i]!=list2[i])
             {
                 return false;
                 break;
             }
         }
         return true;
    }


void readArray (int a[], int n)
{
        for( int i= 0; i < n; i++)
        {
            cin >> a[i];
        }
}
