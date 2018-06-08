#include <iostream>
#include <ctime>
#include <string>

using namespace std;

const int NUMBER_OF_PERSONS = 1000;

int timeVisiting(float a, float b)
{
    static bool first = true;
    if (first)
    {
        srand( time(NULL) ); //seeding for the first time only!
        first = false;
    }
   return a + ((float) rand()) / (( b + 1 ) - a);
}

class Person
{
    public:
        float timeArrival;
        int floor;
        float stayTime;
        float leaveTime;
};

class ElevatorQueue
{
    public:
    ElevatorQueue(Person *);
    ElevatorQueue(const ElevatorQueue&);
    void DisplayPerson(int);
    Person getPerson(int);
    void ChangeFloorNumber(int,int);

    private:
    Person *people;

};
    ElevatorQueue::ElevatorQueue(Person *values)
    {
        people = new Person [NUMBER_OF_PERSONS];
        for(int i =0; i < NUMBER_OF_PERSONS ; i++)
        {
            people = new Person;
        }

        people = values;
    }

    ElevatorQueue::ElevatorQueue(const ElevatorQueue &obj)
    {
        people = new Person [NUMBER_OF_PERSONS];
        for(int i =0; i < NUMBER_OF_PERSONS ; i++)
        {
            people[i] = obj.people[i];
        }
    }

    void ElevatorQueue::DisplayPerson(int index)
    {
        Person p =  people[index];
        cout << "Floor : " << p.floor <<endl;
        cout << "Time Arrival : " << p.timeArrival <<endl;
        cout << "Leave Time : " << p.leaveTime <<endl;
        cout << "Stay Time : " << p.stayTime <<endl;
        cout << endl;
        cout << endl;
    }

    void ElevatorQueue::ChangeFloorNumber(int index, int floorNumber)
    {
        people[index].floor = floorNumber;
        cout << "Floor number changed to " << people[index].floor << endl;
    }


    Person ElevatorQueue::getPerson(int index)
    {
        Person p = people[index];
        return p;
    }


int main()
{
    Person people[NUMBER_OF_PERSONS];
    for(int i = 0; i < NUMBER_OF_PERSONS; i++)
    {
        Person p;
        p.floor = rand() %10 + 1;
        p.timeArrival = ((float)rand()) /10;
        p.leaveTime = ((float)rand()) /20;
        p.stayTime = timeVisiting(p.timeArrival, p.leaveTime);
        people[i] = p;
    }

    ElevatorQueue obj1 (people);
    ElevatorQueue obj2 = obj1;

    //Change an individual person data
    int index = 10, floor= 19;
    obj1.ChangeFloorNumber(index, floor);

    cout << endl;
    cout << "Object 1 "<< endl;
    obj1.DisplayPerson(index);

    cout << "Object 2 "<< endl;
    obj2.DisplayPerson(index);

}
