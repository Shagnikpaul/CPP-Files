#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct Process
{
    int id;
    int arrivalTime;
    int burstTime;
    int priority;

    bool operator()(const Process &a, const Process &b)
    {
        return a.arrivalTime < b.arrivalTime;
    }
};

struct compPrio
{
    bool operator()(const Process &a, const Process &b)
    {
        return a.priority > b.priority;
    }
};

int main()
{
    int n;
    cout << "Enter the number of processe: ";
    cin >> n;

    vector<Process> p;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the arrival burst and priority of Process " << (i + 1) << ": ";
        int at, bt, pp;
        cin >> at >> bt >> pp;
        p.push_back({i, at, bt, pp});
    }

    sort(p.begin(), p.end(), Process());
    int ct[n];
    int wt[n];
    int tat[n];
    queue<Process> q;
    for (int i = 0; i < n; i++)
    {
        q.push(p.at(i));
    }
    priority_queue<Process, vector<Process>, compPrio> pq;
    int currentTime = q.front().arrivalTime;

    while (!(q.empty() && pq.empty()))
    {
        while (!q.empty() && q.front().arrivalTime <= currentTime)
        {
            pq.push(q.front());
            q.pop();
        }
        Process s = pq.top();
        pq.pop();
        currentTime += s.burstTime;
        ct[s.id] = currentTime;
        tat[s.id] = ct[s.id] - s.arrivalTime;
        wt[s.id] = tat[s.id] - s.burstTime;
    }

    cout
        << "ALl the completion times : \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Process " << (i + 1) << ": " << ct[i] << "\n";
    }

    cout << "ALl the turnaround times : \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Process " << (i + 1) << ": " << tat[i] << "\n";
    }
}