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
    bool operator()(const Process &a, const Process &b)
    {
        return a.arrivalTime < b.arrivalTime;
    }
};

struct PrioComp
{
    bool operator()(const Process &a, const Process &b)
    {
        return a.burstTime > b.burstTime;
    }
};

int main()
{
    int n;
    cout << "Enter the number of processes : ";
    cin >> n;

    vector<Process> p;
    int ct[n];
    int wt[n];
    int tat[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the arrival time and burst time of the ";
        int at, bt;
        cin >> at >> bt;
        p.push_back({i, at, bt, bt});
    }

    sort(p.begin(), p.end(), Process());
    queue<Process> q;
    for (int i = 0; i < n; i++)
    {
        q.push(p.at(i));
        // cout << "Process " << " " << i << " " << p.at(i).arrivalTime;
    }

    priority_queue<Process, vector<Process>, PrioComp> pq;

    int currentTime = q.front().arrivalTime;

    while (!(pq.empty() && q.empty()))
    {
        while (!q.empty() && q.front().arrivalTime <= currentTime)
        {
            pq.push(q.front());
            cout << "pushed " << q.front().id << "\n";
            q.pop();
        }

        Process j = pq.top();
        pq.pop();

        j.remainingBurstTime--;
        if (j.remainingBurstTime == 0)
        {
            ct[j.id] = currentTime+1;
            tat[j.id] = ct[j.id] - j.arrivalTime;
            wt[j.id] = tat[j.id] - j.burstTime;
        }
        else {
            pq.push(j);
        }

        currentTime++;
    }

    return 0;
}