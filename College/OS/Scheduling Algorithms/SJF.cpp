#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct Process
{
    int id;
    int arrivalTime;
    int burstTime;
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
        p.push_back({i, at, bt});
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
        cout << "Running process " << j.id << "\n";
        ct[j.id] = currentTime + j.burstTime;
        tat[j.id] = ct[j.id] - j.arrivalTime;
        wt[j.id] = tat[j.id] - j.burstTime;

        currentTime += j.burstTime;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     p.at(i).completionTime = currentTime + p.at(i).burstTime;
    //     p.at(i).turnAroundTime = p.at(i).completionTime - p.at(i).arrivalTime;
    //     p.at(i).waitingTime = p.at(i).turnAroundTime - p.at(i).burstTime;

    //     currentTime = p.at(i).completionTime;
    // }

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