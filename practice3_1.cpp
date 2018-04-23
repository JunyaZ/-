/*******************************
This program to calculate the mean, variance, and standard deviation 
of the values stored in a vector and a driver to test your functions

Letter grades are sometimes assigned numeric score by using the grading 
system commonly called grading on a curve. In this scheme, a letter grade 
is assigned to a numeric score according to the following table, where m is 
the mean score and σ (sigma) is the standard deviation.
*******************************/
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<sstream>
#include<math.h>
using namespace std;


double mean(vector<double> v)
{
	double sum = 0;
	for(int i=0;i<v.size();i++)
	{
		sum += v[i];
	}
	sum /= v.size();
	return sum;
}

double variance(vector<double> v)
{
	double m = mean(v);
	double sum = 0;
	for(int i=0;i<v.size();i++)
	{
		sum += (v[i] - m) * (v[i] - m);
	}
	sum /= v.size();
	return sum;
}

double standard_deviation(vector<double> v)
{
	return sqrt(variance(v));
}

char charScore(double x, double m, double sd)
{
	if(x<m-3*sd/2)
	{
		return 'F';
	}
	else if(x<m-sd/2)
	{
		return 'D';
	}
	else if(x<m+sd/2)
	{
		return 'C';
	}
	else if(x<m+3*sd/2)
	{
		return 'B';
	}
	else
	{
		return 'A';
	}
}

int main()
{
	while(1)
	{
		cout<<endl;
		cout<<"Please input a list of students scores : ";
		vector<double> v;
		string str = "";
		getline(cin, str);
		istringstream in(str);
		double x;
		while(in>>x)
		{
			v.push_back(x);
		}
		cout<<setiosflags(ios::fixed);
		cout<<setprecision(0);
		cout<<"The mean of numbers is "<<mean(v)<<endl;
		cout<<"The variance of numbers is "<<variance(v)<<endl;
		cout<<setiosflags(ios::fixed);
		cout<<setprecision(1);
		cout<<"The standard deviation of numbers is "<<standard_deviation(v)<<endl;
		cout<<endl;
		for(int i=0;i<v.size();i++)
		{
			cout<<"student "<<(i+1)<<" score is "<<charScore(v[i], mean(v), standard_deviation(v))<<endl;
		}
		cout<<"Do you want to continue: ";
		getline(cin, str);
		if(!(str=="y"))
		{
			break;
		}
	}

}

/*
45 23 67 12 87 34 56 76 45 23 67 12 87 34 56 76

98 78 67 45 67 98 78 67 45 67

*/


