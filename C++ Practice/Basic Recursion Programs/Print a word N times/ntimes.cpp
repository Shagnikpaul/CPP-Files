#include "vector"
#include "string"
#include <iostream>
using namespace std;

vector<string> rec(int n,vector<string> s)
{
	cout << "running \n";
    if(n==0)
	{
		return s;
	}
	else
	{
		s[s.size()-n] = "Coding Ninjas ";
		rec((n-1), s);
	}
}


vector<string> printNTimes(int n) {
	vector<string> s(n);
	s = rec(n,s);
	return s;
}




using namespace std;
int main()
{
    
    printNTimes(6);

}

