#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct Process
{
    int i;
    int a;
    int b;
    int p;

    bool operator()(const Process &a, const Process &b)
    {
        return a.a < b.a;
    }
};

struct CompPri
{
    bool operator()(const Process &a, const Process &b)
    {
        return a.p > b.p; // lower num more priority
        // return a.p < b.p; //higher...
    }
};

int main()
{
    int n;
    cout << "Enter the number of processes : ";
    cin >> n;

    int ct[n];
    int tat[n];
    int wt[n];

    vector<Process> l;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival burst and priority for process " << (i + 1) << ": ";
        int a, b, p;
        cin >> a >> b >> p;
        l.push_back({i, a, b, p});
    }

    sort(l.begin(), l.end(), Process());
    queue<Process> q;
    for (int i = 0; i < n; i++)
    {
        q.push(l.at(i));
    }

    priority_queue<Process, vector<Process>, CompPri> p;
    int now = q.front().a;
    while (!(p.empty() && q.empty()))
    {
        while (!q.empty() && q.front().a <= now)
        {
            p.push(q.front());
            q.pop();
        }

        Process s = p.top();
        p.pop();

        ct[s.i] = now + s.b;
        tat[s.i] = ct[s.i] - s.a;
        wt[s.i] = tat[s.i] - s.b;

        now = ct[s.i];
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
