/***************************************
A function that returns the intersection of two vectors of strings:
The intersection of two vectors contains the common elements that appear in both vectors. 
The test program prompts a user to enter two vectors, each with five strings, and displays
their intersection
****************************************/


#include<vector>
#include<iostream>
#include<string>
using namespace std;


vector<string> intersect(const vector<string> & v1, const vector<string> & v2)
{
	vector<string> v;

	for(int i=0;i<v1.size();i++)
	{
		for(int j=0;j<v2.size();j++)
		{
			if(v1[i] == v2[j])
			{
				v.push_back(v1[i]);
				break;
			}
		}
	}
	return v;

}

int main()
{
	vector<string> v1, v2;
	string str;
	cout<<"Enter five strings for vector 1: "<<endl;
	for(int i=0;i<5;i++)
	{
		cin>>str;
		v1.push_back(str);
	}
	cout<<"Enter five strings for vector 2: "<<endl;
	for(int i=0;i<5;i++)
	{
		cin>>str;
		v2.push_back(str);
	}
	vector<string> v = intersect(v1, v2);
	cout<<"The common strings ( the intersection ):";
	for(int i=0;i<v.size();i++)
	{
		cout<<" "<<v[i];
	}
	cout<<endl;
}

/*
Atlanta  Dallas Chicago Boston Denver
Dallas Tampa Miami Boston Richmond

*/
