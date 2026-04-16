#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <set>
using namespace std;
int main()
{
    vector<int> nums;
    vector<int> nums1(21);

    // cout << "How many numbers do you have : ";
    // int n;
    // cin >> n;
    // cout << "Ok now enter " << n << " numbers" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Enter number " << (i + 1) << ": ";
    //     int x;
    //     cin >> x;
    //     nums.push_back(x);
    // }

    // cout << "\nYou entered the following numbers : " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Number " << (i + 1) << ": " << nums[i] << endl;
    // }

    // nums.pop_back();
    // cout << "\nYou entered the following numbers : " << endl;
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     cout << "Number " << (i + 1) << ": " << nums[i] << endl;
    // }

    list<int> l;

    l.push_back(2);
    l.push_front(1);
    l.back();
    l.front();
    l.pop_back();
    l.pop_front();
    for (int i : l)
    {
        cout << " " << i;
    }

    cout << "\nstack\n";
    stack<int> s;
    s.push(1);
    s.push(2);

    set<int> ss;
    ss.insert(34);
    ss.insert(34);
    ss.insert(342);
    for (auto i : ss)
    {
        cout << "set -> " << i << endl;
    }

    multiset<int> ms;
    ms.insert(10);
    ms.insert(10);
    ms.insert(5);

    for (int x : ms)
        cout << x << " ";
    cout << "there are total of " << ms.count(10) << " 10s in the set" << endl;

    
    nums.push_back(3);
    nums.push_back(34);
    nums.push_back(312);
    vector<int>::iterator it = nums.begin();
    while (it != nums.end())
    {
        cout << *it << endl;
        it++;
    }
}