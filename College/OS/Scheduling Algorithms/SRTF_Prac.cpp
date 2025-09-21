#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct Process
{
    int id;
    int arrivalTime;
    int burstTime;
    int remainingBurstTime;

    bool operator()(const Process &a, struct Process &b)
    {
        return a.arrivalTime < b.arrivalTime;
    }
};

struct compBurst
{
    bool operator()(const Process &a, struct Process &b)
    {
        return a.remainingBurstTime > b.remainingBurstTime;
    }
};

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    vector<Process> p;
    for (int i = 0; i < n; i++)
    {
        int at, bt;
        cout << "Enter the arrival and burst time of P" << (i + 1) << ": ";
        cin >> at >> bt;
        p.push_back({i, at, bt, bt});
        cout << "Added : " << p.at(i).id << "\n";
    }
    sort(p.begin(), p.end(), Process());
    for (int i = 0; i < n; i++)
    {

        cout << "\nProcess : " << p.at(i).id << "\n";
    }
    int ct[n];
    int wt[n];
    int tat[n];
    queue<Process> q;
    for (int i = 0; i < n; i++)
    {
        q.push(p.at(i));
    }
    priority_queue<Process, vector<Process>, compBurst> pq;
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
        s.remainingBurstTime--;
        currentTime++;
        if (s.remainingBurstTime == 0)
        {
            ct[s.id] = currentTime;
            tat[s.id] = ct[s.id] - s.arrivalTime;
            wt[s.id] = tat[s.id] - s.burstTime;
        }
        else
        {
            pq.push(s);
        }
    }
    cout << "ALl the completion times : \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Process " << (i + 1) << ": " << ct[i] << "\n";
    }

    cout << "ALl the turnaround times : \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Process " << (i + 1) << ": " << tat[i] << "\n";
    }
    return 0;
}