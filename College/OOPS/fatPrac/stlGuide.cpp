#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

int main()
{

    // ================= VECTOR =================
    vector<int> v = {1, 2, 3};

    v.push_back(4); // add at end
    v.pop_back();   // remove last

    cout << v[0] << endl; // random access

    for (int x : v)
        cout << x << " ";
    cout << endl;

    // ================= LIST =================
    list<int> l = {10, 20, 30};

    l.push_back(40); // insert at back
    l.push_front(5); // insert at front

    l.pop_back();
    l.pop_front();

    for (int x : l)
        cout << x << " ";
    cout << endl;

    // ================= DEQUE =================
    deque<int> d = {1, 2, 3};

    d.push_back(4);
    d.push_front(0);

    d.pop_back();
    d.pop_front();

    cout << d.front() << endl;
    cout << d.back() << endl;

    // ================= STACK =================
    stack<int> s;

    s.push(10);
    s.push(20);

    cout << s.top() << endl; // top element

    s.pop();

    cout << s.empty() << endl;

    // ================= QUEUE =================
    queue<int> q;

    q.push(1);
    q.push(2);

    cout << q.front() << endl;
    cout << q.back() << endl;

    q.pop();

    // ============ PRIORITY QUEUE =============
    priority_queue<int> pq;

    pq.push(5);
    pq.push(1);
    pq.push(10);

    cout << pq.top() << endl; // largest element

    pq.pop();

    // ================= SET =================
    set<int> st;

    st.insert(10);
    st.insert(20);
    st.insert(10); // duplicate ignored

    for (int x : st)
        cout << x << " ";
    cout << endl;

    if (st.find(20) != st.end())
        cout << "found" << endl;

    st.erase(10);

    // =============== MULTISET ===============
    multiset<int> ms;

    ms.insert(5);
    ms.insert(5);
    ms.insert(10);

    for (int x : ms)
        cout << x << " ";
    cout << endl;

    cout << ms.count(5) << endl; // frequency

    // ================= MAP =================
    map<int, string> mp;

    mp[1] = "one";
    mp[2] = "two";

    cout << mp[1] << endl;

    for (auto x : mp)
        cout << x.first << " " << x.second << endl;

    mp.erase(1);

    // ============== MULTIMAP ===============
    multimap<int, string> mm;

    mm.insert({1, "A"});
    mm.insert({1, "B"});

    for (auto x : mm)
        cout << x.first << " " << x.second << endl;

    // ============ VECTOR ITERATOR ===========
    vector<int>::iterator itr;

    for (itr = v.begin(); itr != v.end(); itr++)
        cout << *itr << " ";
    cout << endl;

    // ============== SIZE CHECK ==============
    cout << v.size() << endl;
    cout << v.empty() << endl;

    // ============ VECTOR SWAP ===============
    vector<int> a = {1, 2};
    vector<int> b = {7, 8};

    a.swap(b);

    for (int x : a)
        cout << x << " ";
    cout << endl;

    // ============ VECTOR ASSIGN =============
    vector<int> c;

    c.assign(5, 100); // five 100s

    for (int x : c)
        cout << x << " ";
    cout << endl;

    return 0;
}
