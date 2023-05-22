#include<iostream>
using namespace std;

int main()
{
    std::string students[] = {"KK" , "KKw", "be", "no"};

    for(std::string k : students) {
      cout << k << ", ";
    }
    return 0;
}