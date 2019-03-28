
In this lab, design linked list class to hold a series of integers. The class should have member functions for appending, inserting and deleting nodes. Don’t forget to add a destructor that destroys the list. 
1.	Add a print member function which should display all the values in the linked list. 
2.	Add a copy constructor
3.	Add a member function named reverse that rearranges the nodes in the list so their order is reversed. 
4.	Add a member function named search that returns the position of specific value, x, in the linked list. The first node in the list is at position 0, the second node is at position 1 and so on. If x is not found on the list, the search should return -1.
5.	Add a member function named insertByPos for inserting a new item at a specified position. A position of 0 means that the value will become the first item on the list, a position of 1 means the value will become the second item on the list, and so on. A position equal to or greater than the length of the list means the value is placed at the end of the list.
6.	Add a member function named RemoveByPos for deleting a node at a specified position. A value of 0 for the position means the first node in the list ( the current head) is deleted. The function does nothing if the specified position is greater than or equal to the length of the list.
7.	Change the above class you defined to a list class template. ( Note: you need to modify all the constructors, member functions to work well with the list class template)
8.	Write a driver program (test program) to demonstrate all the member functions in your class working.
9.	Modify the above driver or test program that lets the user decide how many months of data will be entered. Then the user enter the total rainfall for each month into a linked list object you created based the class defined. The program should calculate and display the total rainfall for the year, the average monthly rainfall, and the months with the highest and lowest amounts.
 

