#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct Process
{
    int i;
    int a;
    int b;

    bool operator()(const Process &a, const Process &b)
    {
        return a.a < b.a;
    }
};

int main()
{
    int n;
    cout << "Enter the number of processes : ";
    cin >> n;

    vector<Process> q;
    int ct[n];
    int tat[n];
    int wt[n];
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cout << "Enter arrival and burst time for process " << (i + 1) << ": ";
        cin >> a >> b;
        q.push_back({i, a, b});
    }

    sort(q.begin(), q.end(), Process());
    int now = q.at(0).a;
    for (int i = 0; i < n; i++)
    {
        ct[i] = now + q.at(i).b;
        now = ct[i];
        tat[i] = ct[i] - q.at(i).a;
        wt[i] = tat[i] - q.at(i).b;
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
}