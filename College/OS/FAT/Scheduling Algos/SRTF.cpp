#include <algorithm>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Process
{
    int i;
    int a;
    int b;
    int rb;

    bool operator()(const Process &a, const Process &b)
    {
        return a.a < b.a;
    }
};

struct CompJ
{
    bool operator()(const Process &a, const Process &b)
    {
        return a.rb > b.rb;
    }
};

int main()
{
    int n;
    cout << "Enter the no. of processes : ";
    cin >> n;

    int ct[n];
    int tat[n];
    int wt[n];

    vector<Process> l;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival and burst time for Process " << (i + 1) << ": ";
        int a, b;
        cin >> a >> b;
        l.push_back({i, a, b, b});
    }

    sort(l.begin(), l.end(), Process());

    queue<Process> q;

    for (int i = 0; i < n; i++)
    {
        q.push(l.at(i));
    }

    int now = q.front().a;

    priority_queue<Process, vector<Process>, CompJ> p;

    while (!(p.empty() && q.empty()))
    {
        while (!q.empty() && q.front().a <= now)
        {
            p.push(q.front());
            q.pop();
        }

        Process s = p.top();
        p.pop();

        s.rb--;
        now++;
        if (s.rb == 0)
        {
            ct[s.i] = now;
            tat[s.i] = ct[s.i] - s.a;
            wt[s.i] = tat[s.i] - s.b;
        }
        else
        {
            p.push(s);
        }
    }

    cout << "\nCompletion times : ";
    for (int i = 0; i < n; i++)
    {
        cout << ct[i] << "\n";
    }

    cout << "\nTurn around times : ";
    for (int i = 0; i < n; i++)
    {
        cout << tat[i] << "\n";
    }

    cout << "\nWaiting times times : ";
    for (int i = 0; i < n; i++)
    {
        cout << wt[i] << "\n";
    }

    return 0;
}