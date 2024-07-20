#include <iostream>
using namespace std;
class student
{
public:
    string name;
    int id;
    void get()
    {
        cout << "enter the name" << endl;
        cin >> name;
        cout << "enter the id" << endl;
        cin >> id;
    }
};
class studentmarks : public student
{
public:
    int s1, s2, s3;
    void marks()
    {
        cout << "enter the marks of s1" << endl;
        cin >> s1;
        cout << "enter the marks of s2" << endl;
        cin >> s2;
        cout << "enter the marks of s3" << endl;
        cin >> s3;
    }
};
class sportmark : public student
{
public:
    int s4;
    void sports()
    {
        cout << "enter the sports mark" << endl;
        cin >> s4;
    }
};
class result : public sportmark, public studentmarks
{
public:
    int re;
    void res()
    {
        re = s1 + s2 + s3 + s4;
    }
};
int main()
{
    result r;
    r.studentmarks::get();
    r.marks();
    r.sports();
    r.res();
    cout << "result = " << r.re << endl;
    return 0;
}