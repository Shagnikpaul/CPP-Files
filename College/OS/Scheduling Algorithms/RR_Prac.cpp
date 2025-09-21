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

int main()
{

    int n;
    cout << "Enter the number of process: ";
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
    cout << "Enter the time quantum: ";
    int quan;
    cin >> quan;

    sort(p.begin(), p.end(), Process());

    queue<Process> q;
    for (int i = 0; i < n; i++)
    {
        q.push(p.at(i));
    }

    queue<Process> readyQueue;
    int currentTime = q.front().arrivalTime;
    while (!(q.empty() && readyQueue.empty()))
    {
        while (!q.empty() && q.front().arrivalTime <= currentTime)
        {
            readyQueue.push(q.front());
            q.pop();
        }

        Process s = readyQueue.front();
        readyQueue.pop();
        if (s.remainingBurstTime <= quan)
        {
            currentTime += s.remainingBurstTime;
            s.remainingBurstTime = 0;
            ct[s.id] = currentTime;
            tat[s.id] = ct[s.id] - s.arrivalTime;
            wt[s.id] = tat[s.id] - s.burstTime;
            while (!q.empty() && q.front().arrivalTime <= currentTime)
            {
                readyQueue.push(q.front());
                q.pop();
            }
        }
        else
        {
            s.remainingBurstTime -= quan;
            currentTime += quan;
            while (!q.empty() && q.front().arrivalTime <= currentTime)
            {
                readyQueue.push(q.front());
                q.pop();
            }
            readyQueue.push(s);
        }
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
    return 0;
}