#include <bits/stdc++.h>
#include<iostream>
using namespace std;
template <class T>
class NumberList
 {
     private:
         struct ListNode
         {
             T value;
             struct ListNode *next;
         };

         ListNode *head;
     public:
        NumberList()
        {
            head = nullptr;
        }
        ~NumberList();
        void appending(T);
        void inserting(T);
        void deleteing(T);
        NumberList(const T &);
        void print();
        void Reverse();
        T  Search(T);
        void insertByPos(T,T);
        void RemoveByPos(T);
        T largestElement();
        T smallestElement();

 };
 template <class T>
 void NumberList<T>:: appending(T val)
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
template <class T>
void NumberList<T>:: inserting(T val)
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
template <class T>
void NumberList<T>:: deleteing (T val)
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

template <class T>
void NumberList<T>::print()
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
template <class T>
NumberList<T>:: NumberList(const T &copyed)
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
template <class T>
void NumberList<T>::Reverse()
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
template <class T>
T NumberList<T>::Search(T val)
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
template <class T>
void NumberList<T>::insertByPos(T val, T pos)
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
            newNode1 = newNode1->next;
        }
        newNode->next = newNode1->next;
        newNode1-> next = newNode;

    }
template <class T>
void NumberList<T>::RemoveByPos(T pos)
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
template <class T>
NumberList<T>:: ~NumberList()
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
template <class T>
T NumberList<T>:: largestElement()
{

    int max_ = INT_MIN;
    while (head != NULL) {
        if (max_ < head->value)
            max_ = head->value;
        head = head-> next;
    }
    return max_;
}
template <class T>
T NumberList<T>:: smallestElement()
{
    int min_ = INT_MAX;
    while (head != NULL)
        {
        if (min_ > head->value)
            min_ = head->value;

        head = head->next;
    }
    return min_;
}


int main ()
{

    NumberList<int> TheLinked;
    int n,data,total;
    double average;
    cout << "Enter the number of month of rainfall: ";
    cin >> n;
    total = 0;
    for (int i=0;i < n; i++)
    {
        cout << "Enter the TOTAL rainfall in " << i+1<< "th month ";
        cin >> data;
        TheLinked.insertByPos(data,i);
        total = total + data;
    }
        int max_, min_;
        cout<< endl << "The total rainfall for the year :" ;
        TheLinked.print();
        max_ = TheLinked.largestElement();
        min_ = TheLinked.smallestElement();
        cout<< "The highest rainfall amounts is: " << max_<< endl;
        cout<< "The lowest rainfall amounts is: :" << min_<< endl;

        cout << setprecision(2) << fixed << showpoint;
        average = total/n;
        cout << "The average rainfall amounts is: " << average;
    return 0;
}
