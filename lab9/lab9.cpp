
#include<iostream>
#include<string>
#include<sstream>
#include <stdio.h>
#include <ctype.h>
#include<set>
#include<unordered_set>
#include<map>

using namespace std;

void obtain_tokens(string Input, set<string>tokens, set<string> :: iterator it)
{

    string s;
    int count = 0;
    int i=0;
    for(int count= 0;Input[count];count++)
      {
        if (isalpha(Input[count]))
            cout<< Input[count];
        else
        {
            s= Input[count];
            tokens.insert(s);
        }
      }
      cout<< endl << "The set contains tokens:"<< endl;
    for (it = tokens.begin(); it!=  tokens.end(); it++)
    {
           cout << *it;
    }
    cout << endl;

}

void unordered_tokens(string Input, unordered_set<string>tokens,  unordered_set<string> :: iterator it)
{

    string s;
    int count = 0;
    for(int count= 0;Input[count];count++)
      {
        if (isalpha(Input[count]))
            cout<< Input[count];
        else
        {
            s= Input[count];
            tokens.insert(s);
        }
      }
      cout<< endl << "The unordered set contains tokens:"<< endl;
     for (it = tokens.begin(); it!=  tokens.end(); it++)
    {
           cout << *it;
    }
     cout << endl;
}

string  drop_tokens( set<string>tokens, set<string> :: iterator it, string Input)
{
     for(int count= 0;Input[count];count++)
  {
      string s;
      s= Input[count];
      it= tokens.find(s);
      if(it!= tokens.end())
	{
 	   Input.erase(Input[count]);
	}
    }
    return Input;
}

void count_occurrences(set<string>tokens,set<string> :: iterator it,string input)
{
    map<string, int> myMap;
    istringstream streamstring (input);
    while (streamstring)
    {
        string str;
        string substr;
        getline(streamstring,str,' ');
	    substr = drop_tokens(tokens,it,str);
        int i = 0;
        auto postion = input.find(substr, 0);
        while (postion != string::npos)
        {
            ++i;
            postion = input.find(substr, postion + 1);
        }

        if(substr.size() != 0)
            myMap[substr] = i;
    }
    for (const auto &iterators : myMap) {
        cout << iterators.first << "=" << iterators.second << '\n';
    }
}

int main ()
{

    string Input;
    set<string>tokens1={};
    set<string> :: iterator it1;
    unordered_set<string>tokens2={};
    unordered_set<string> :: iterator it2;

	cout<<"Enter Text: " <<endl;
	getline(cin,Input);
	cout<<"Entered Text is: " << Input <<endl;

	obtain_tokens(Input,tokens1,it1);
	unordered_tokens(Input,tokens2,it2);
    	count_occurrences(tokens1,it1,Input);

return 0;
}
