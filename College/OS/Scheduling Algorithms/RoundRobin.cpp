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
    cout << "Enter the time quantum: ";
    int quan;
    cin >> quan;
    sort(p.begin(), p.end(), Process());
    queue<Process> q;
    for (int i = 0; i < n; i++)
    {
        q.push(p.at(i));
        // cout << "Process " << " " << i << " " << p.at(i).arrivalTime;
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

        Process pc = readyQueue.front();
        readyQueue.pop();
        if (pc.remainingBurstTime <= quan)
        {
            currentTime += pc.remainingBurstTime;
            ct[pc.id] = currentTime;
            tat[pc.id] = ct[pc.id] - pc.arrivalTime;
            wt[pc.id] = tat[pc.id] - pc.burstTime;
            pc.remainingBurstTime = 0;
            while (!q.empty() && q.front().arrivalTime <= currentTime)
            {
                readyQueue.push(q.front());
                q.pop();
            }
        }
        else
        {
            pc.remainingBurstTime -= quan;
            currentTime += quan;
            while (!q.empty() && q.front().arrivalTime <= currentTime)
            {
                readyQueue.push(q.front());
                q.pop();
            }
            readyQueue.push(pc);
        }
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