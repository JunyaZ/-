/*==============================================================
 Created by: Junya Zhao
 Last modified date :	02/17/2018
 Program:  Airport information
 
The program that uses a structure to store 
the following information for a particular month at the local airport:
•	Total number of planes that landed
•	Total number of planes that departed
•	Greatest number of planes that landed in a given day that month
•	Least number of planes that landed in a given day that month
The program have an array of twelve structures to hold travel information 
for the entire year. The program prompt the user to enter data for each month. 
Once all data is entered, the program calculate and output the average monthly 
number of landing planes, the average monthly number of departing planes,
the total number of landing and departing planes for the year, 
and the greatest and least number of planes that landed on any one day (and which month it occurred in).
===============================================================*/
#include <iostream>
#include<string>
#include <vector>
using namespace std;

//declare a structure called Airport that has four members:
// num_landed, num_departed, Greatest_num, Least_num;
struct Airport
{
    int num_landed;
    int num_departed;
    int Greatest_num;
    int Least_num;
};

 //declare a enumerator have 12 numbers
 enum
{
    January, February, March, April, May, June,
    July, August, September, October, November,December

};
//declare a vector hold the name of Month
static const std::vector<string> Month {"January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November","December"};

int main()
{
    Airport info[12];  // declare a array that is Airport data type
    int Max = info[January].num_landed;
    int Min = info[January].num_landed;
    int Total_land=0;
    int Total_depar=0;
    float average1, average2;
    cout << "Enter the data for each MONTH:" << endl;

    for(int i = January; i<= December; i++)
    // for loop to enter and calculate information for each month :
    {
        cout << "Enter the TOTAL number of planes that LANDED in "<< Month[i] << ":" ;
        cin >> info[i].num_landed;
        cout << " Enter the TOTAL number of planes  that DEPARTED in " << Month[i] << ":";
        cin >> info[i].num_departed;
        cout << "Enter the GREATEST number of planes that LANDED in " << Month[i]  << ":" ;
        cin >> info[i].Greatest_num;
        cout << "Enter the LEAST number of planes that LANDED in " << Month[i] << ":";
        cin >> info[i].Greatest_num;

        // comupte the total number of landing, departing,
        Total_land += info[i].num_landed;
        Total_depar += info[i].num_departed;
        // comupte the average number of landing, departing,
        average1 = Total_land/12;
        average2 = Total_depar/12;
        if (info[i].num_landed > Max) Max = info[i].num_landed ;

        if (info[i].num_landed < Min) Min = info[i].num_landed ;


    }
        //cout the monthly information :
         cout << " The AVERAGE monthly number of landing planes :" << average1<< endl;
         cout << " The AVERAGE monthly number of departing planes :" << average2 << endl;
         cout << " The TOTAL number of landing planes in this year : "<< Total_land << endl;
         cout << " The TOTAL number of departing planes in this year : "<< Total_depar<< endl;

        cout << " The greatest number of landed planes in whole year is :"  << Max << endl;
        cout << " The least number of landed planes is whole year is :" << Min << endl;
}
