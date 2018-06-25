
#include<iostream>
using namespace std;
class NumberList
 {
     private:
         struct ListNode
         {
             int value;
             struct ListNode *next;
         };

         ListNode *head;
     public:
        NumberList()
        {
            head = nullptr;
        }
        ~NumberList();
        void appending(int);
        void inserting(int);
        void deleting(int);
        NumberList(const NumberList &);
        void print();
        void Reverse();
        int  Search(int);
        void insertByPos(int,int);
        void RemoveByPos(int);

 };
void NumberList:: appending(int val)
{
    ListNode * newnode;
    ListNode* nodeptr;
    newnode = new ListNode;
    newnode-> value = val;
    newnode-> next = nullptr;
    if(!head)
        head = newnode;
    else
    {
        nodeptr = head;
        while(nodeptr-> next)
            nodeptr = nodeptr-> next;
        nodeptr->next = newnode;

    }

}
void NumberList:: inserting(int val)
{
    ListNode* newnode;
    ListNode* nodeptr;
    ListNode* pre_node = nullptr;
    newnode = new ListNode;
    newnode-> value = val;
    if(!head)
    {
        head = newnode;
        newnode -> next =nullptr;
    }
    else
    {
        nodeptr = head;
        pre_node = nullptr;
        while(nodeptr != nullptr && nodeptr -> value <val)
        {
            pre_node = nodeptr;
            nodeptr = nodeptr->next;
        }
        if (pre_node ==nullptr)
        {
            head=newnode;
            newnode->next = nodeptr;
        }
        else
        {
            pre_node ->next = newnode;
            newnode-> next = nodeptr;
        }
    }
}

void NumberList:: deleting (int val)
{
    ListNode * nodeptr;
    ListNode * pre_node;
    if (!head)
        return;

    if (head-> value == val)
    {
        nodeptr = head->next;
        delete head;
        head= nodeptr;
    }
    else
    {
        nodeptr = head;
        while (nodeptr != nullptr && nodeptr -> value!= val)
        {
            pre_node = nodeptr;
            nodeptr = nodeptr->next;
        }
        if (nodeptr)
        {
            pre_node ->next = nodeptr-> next;
            delete nodeptr;
        }
    }
}
void NumberList::print()
{
    ListNode *nodePtr; // To move through the list
    nodePtr = head; //Position nodePtr at the head of the list.
    //While nodePtr points to a node, traverse the list.
    while (nodePtr!= NULL)
    {
        cout << nodePtr->value;//Display the value in this node.
        nodePtr = nodePtr->next;// Move to the next node.
        cout << " " ;
    }
    cout<< endl;
}

NumberList:: NumberList(const NumberList &copyed)
{
    ListNode * p1 = NULL;//current
    ListNode * p2 = NULL;//next

    if( copyed.head == NULL )
        head = NULL;

    else
    {
        head = new ListNode;
        head -> value = copyed.head -> value;
        p1 = head;
        p2 = copyed.head -> next;
    }

    while( p2 )
    {
        p1 -> next = new ListNode;
        p1 = p1 -> next;
        p1 -> value = p2 -> value;
        p2 = p2 -> next;
    }
    p1 -> next = NULL;
}

void NumberList::Reverse()
{
    ListNode *prev = NULL;
    ListNode *current = NULL;
    ListNode *next = NULL;
    current = head;
    if(head=NULL)
        return;
    while(current != NULL)
        {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
int  NumberList::Search(int val)
{

   int pos = 0;
   while (head != NULL && head->value != val) {
       pos++;
       head = head->next;
   }
   if (head == NULL)
       return -1;
   else
       return pos;
}

void NumberList::insertByPos(int val, int pos)
{

        ListNode *newNode = new ListNode;
        newNode->value = val;
        newNode->next =NULL;
        if(pos==0)
        {
                newNode-> next =head;
                head = newNode;
                return;
        }
        ListNode *newNode1= head;
        for (int i= 0;i<pos-1;i++)
        {
            if (newNode1->next == nullptr)
            {
                cout<< "The position does not exist, please enter another one!"<< endl;
                break;
            }

            newNode1 = newNode1->next;

        }
        newNode->next = newNode1->next;
        newNode1-> next = newNode;

    }

void NumberList::RemoveByPos(int pos)
{
    ListNode *nodePtr;
    ListNode *nodePtr1;
    nodePtr = head;
    if (pos==0)
    {
        head = nodePtr-> next;
        free(nodePtr);
        return;
    }
    int i=0;
    while(i< pos-1)
    {
        nodePtr = nodePtr-> next;
        nodePtr1 =nodePtr ->next;
        nodePtr -> next = nodePtr1-> next;
        free(nodePtr1);
        i++;
    }
}


NumberList:: ~NumberList()
{
    ListNode * nodePtr;
    ListNode * nextNode;
    nodePtr = head;
    while (nodePtr!= nullptr)
    {
        nextNode = nodePtr-> next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

int main ()
{
    NumberList TheLinked;
    //testing the function insertByPos
    TheLinked.insertByPos(2,0);
    TheLinked.insertByPos(3,1);
    TheLinked.insertByPos(4,2);
    TheLinked.insertByPos(5,2);
    cout << " The current Linked list is :";
    TheLinked.print();
    int num;
    cout << " Enter the size of values that you want to insert : ";
    cin >> num;
    for (int couter = 0; couter < num; couter ++)
    {
        int data, pos;
        cout << " Please Enter the value you want to insert :";
        cin >> data;
        cout << " Please Enter the position that you want to insert :";
        cin >> pos;

        TheLinked.insertByPos(data,pos);
    }
    /*
    TheLinked.insertByPos(2,0);
    TheLinked.insertByPos(3,1);
    TheLinked.insertByPos(4,2);
    TheLinked.insertByPos(5,2);
    TheLinked.insertByPos(11,0);
    */
    //testing the function print
    cout << " after inserted by position, the list are :";
    TheLinked.print();
    //testing the function instering
    int a;
    cout << " Please enter a value to insert: ";
    cin >> a;
    TheLinked.inserting(a);
    cout << " after inserting a value, the list are :";
    TheLinked.print();
    //testing the function appending
    int b;
    cout << " Please enter a value to append: ";
    cin>> b;
    TheLinked.appending(b);
    cout << " after appending a value, the list are :";
    TheLinked.print();
    //testing the function appending
    int c;
    cout << " Please enter a value in the list that you want to delete: ";
    cin >> c;
    TheLinked.deleting(c);
    cout << " after deleting  a value, the list are :";
    TheLinked.print();

    int n ;
    cout << "Enter the position of Node thst you want to delete :" ;
    cin >> n;
    TheLinked.RemoveByPos(n);
    TheLinked.print();
    cout<< " Reversed Link list: ";
    TheLinked.Reverse();
    TheLinked.print();
    int result;
    result =TheLinked.Search(11);
    cout << result;
    return 0;
}
