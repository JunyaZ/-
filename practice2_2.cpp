/*******************************************************************
1.partitions the list using the first element, called a pivot
2.After the partition, the elements in the list are rearranged 
so that all the elements before the pivot are less than or equal
to the pivot and the elements after the pivot are greater than the pivot. 
The function also returns the index where the pivot is located in the new list. 
Implement the function in a way that takes size number of comparisons.
Write a test program that prompts the user to enter a list and displays the list after the partition. Here is a sample run. 
ps: the first number in the input indicates the number of the elements in the list. Assume the maximum list size is 10.
========================================================
looks like
Enter list: 8 10 1 5 16 61 9 11 1
After the partition, the list is: 9 1 5 1 10 61 11 16
=====================================================

*********************************************************************/
#include <iostream>
#include <string>

using namespace std;
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int* partition(int* data, int size)
{
	int pivot = data[0];
	int* result = new int[size];
	int leftIndex = 0;
	int rightIndex = size;
	int index = 0;
	for (int i = size - 1; i >= 0; i--) {
		if (data[i] < pivot)
		{
			result[leftIndex] = data[i];
			leftIndex++;
		}
		else if (data[i] > pivot)
		{
			rightIndex--;
			result[rightIndex] = data[i];
		}
		else if (data[i] == pivot)
		{
			index = abs((leftIndex + rightIndex) / 2);
			result[index] = data[i];
		}
	}

	return result;

}

int main()
{
   int Index;
   cout << "Enter the size of you list : ";
   cin >> Index;   
   if (Index <=10)
   {
	   int* data = new int[Index];
	   for (int i = 0; i < Index; i++)
	   {
		   //cout << "\nEnter a value" << i + 1 << ": " << endl;
		   cin >> data[i];
	   }

	   cout << "Result array  is : \n" << endl;
	   int* result = partition(data, Index);
		   for (size_t i = 0; i < Index; i++)
		   {
			   cout << *(result + i) <<"\t";
		   }
		   //cout << "Result is : "<<result << endl;
	   delete(data);
	   
   }
    else cout << "Error : The size of your list shoule be less than 10!";

	system("pause");
	return 0;
	
}
