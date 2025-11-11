#include <iostream>
#include <fstream>



using namespace std;
int main()
{
    ifstream file("test.txt");
    
    
    string s;
    int isComment = 0;

    while(getline(file, s)) {
        for(int i=0;i<(int)s.size();i++) {
            
        }
    }
    return 0;
}