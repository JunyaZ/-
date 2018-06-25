#include <iostream>
#include<string>
#include<stack>
using namespace std;
struct inventory
{
    int serialNum;
    string manufacDate;
    int lotNum;
};

template<class T>
class DynStack
{
  struct StackNode
  {
        T inventory;
        StackNode *next;
  };
        StackNode * top;

public:
    DynStack()
    {
        top= nullptr;
    }
    ~DynStack();
    void display();
    bool isEmpty();
    void push(T);
    void pop(T);
};

template<class T>
void DynStack<T>:: display()
{
    StackNode *nodePtr; // To move through the list
    nodePtr = top; //Position nodePtr at the head of the list.
    //While nodePtr points to a node, traverse the list.
    while (nodePtr!= NULL)
    {
        cout << "The Serial number is :";
        cout << nodePtr ->inventory.serialNum << endl;
        cout << "The manufactured date is :";
        cout << nodePtr-> inventory.manufacDate << endl;
        cout << "The lot number is :";
        cout << nodePtr-> inventory.lotNum << endl; //Display the value in this node.

        nodePtr = nodePtr-> next;// Move to the next node.
        cout << " " ;
    }
    cout<< endl;
}

template<class T>
bool DynStack<T>:: isEmpty()
{
    bool status;
    if(!top)
        status = true;
    else
        status = false;
    return status;
}

template<class T>
void DynStack<T>:: push(T val)
{
    StackNode * newnode = nullptr;
    newnode = new StackNode;
    newnode -> inventory = val;
    if(isEmpty())
    {
        top= newnode;
        newnode -> next = nullptr;
    }
    else
    {
        newnode-> next = top;
        top= newnode;
    }
}
template<class T>
void DynStack<T>::pop(T val)
{
    StackNode * temp = nullptr;
    if(isEmpty())
    {
        cout << " The stack is empty.\n";
    }
    else
    {
        val = top-> inventory;
        temp = top-> next;
        delete top;
        top= temp;
    }
}

template<class T>
DynStack<T>::~DynStack()
{
    StackNode * nodeptr = nullptr;
    StackNode * nextnode = nullptr;
    nodeptr = top;
    while (nodeptr != nullptr)
    {
        nextnode = nodeptr -> next;
        delete nodeptr;
        nodeptr = nextnode;
    }
}

int main()
{
    int Serial, lot;
    string date;
    int num,Times,Input;
    DynStack <inventory> NewObj;
    inventory newInventory;
    cout  << " ============Welcome !!==============" << endl;
    cout  << " Please Enter How many times you want to edit our inventory management system:";
    cin >> Times;
    for(int counter=0;counter< Times;counter ++)
    {
        cout << " If you want to add a part to inventory, Please enter 1" << endl;
        cout << "If you want to take a part from inventory, Please enter 2"<< endl;
        cin >> Input;
        switch (Input)
        {
            case 1:
                {
                    cout << "How many inventory you want to add ?" << endl;
                    cin >> num;
                    for (int i=0; i< num;  i++)
                    {
                        cout << "Please Enter the Serial number :";
                        cin >> Serial;
                        newInventory.serialNum = Serial;
                        cout <<"Please Enter the manufactured date :";
                        cin >> date;
                        newInventory.manufacDate =date;
                        cout <<"Please Enter the lot number :";
                        cin >> lot;
                        newInventory.lotNum = lot;
                        NewObj.push(newInventory);
                     }
                }
                break;
            case 2:
                {
                if (NewObj.isEmpty())
                    cout << " There is no Inventory, Please add first!" << endl;
                else
                {
                    NewObj.pop(newInventory);
                    cout << " The deleted Inventory is:"<< endl;
                    cout << "serialNum:"<< newInventory.serialNum << endl;
                    cout <<"manufacDate"<< newInventory.manufacDate<<endl;
                    cout << "lotNum" << newInventory.lotNum<< endl;
                }
                }

        }
    }
    cout << " The contents of the member values of all the objects that remain on the stack"<< endl;
    NewObj.display();

}
