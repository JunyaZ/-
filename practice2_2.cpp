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
