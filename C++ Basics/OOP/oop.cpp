#include <iostream>
using namespace std;

class JOE {
    private:
    char full_name[100];
    int age;
    float salary;
    public:
    int getAge()
    {
        return age;
    }
    int getSalary()
    {
        return salary;
    }
    void setAge(int x)
    {
        age = x;
    }
    void setSalary(int x)
    {
        salary = x;
    }
};



int main()
{
     JOE j1;
     j1.setAge(21);
     cout << j1.getAge() << endl;
     cout << "size of JOE "<< sizeof(j1) << "\n";







     // dynamic allocation in heap
     JOE *j2 = new JOE;
     cout << (*j2).getAge() << endl;
}