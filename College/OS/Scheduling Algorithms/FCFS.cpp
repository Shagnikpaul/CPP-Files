#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct Process
{
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
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

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the arrival time and burst time of the ";
        int at, bt;
        cin >> at >> bt;
        p.push_back({i, at, bt});
    }

    sort(p.begin(), p.end(), Process());
    int currentTime = p.at(0).arrivalTime;
    for (int i = 0; i < n; i++)
    {
        p.at(i).completionTime = currentTime + p.at(i).burstTime;
        p.at(i).turnAroundTime = p.at(i).completionTime - p.at(i).arrivalTime;
        p.at(i).waitingTime = p.at(i).turnAroundTime - p.at(i).burstTime;

        currentTime = p.at(i).completionTime;
    }

    cout << "ALl the completion times : \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Process " << (i + 1) << ": " << p.at(i).completionTime << "\n";
    }

    cout << "ALl the turnaround times : \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Process " << (i + 1) << ": " << p.at(i).turnAroundTime << "\n";
    }
}