#include <bits/stdc++.h>
using namespace std;

struct Compare
{
    bool operator()(vector<int> *a, vector<int> *b)
    {
        if ((*a)[3] == (*b)[3])
            return (*a)[1] > (*b)[1];
        return (*a)[3] > (*b)[3];
    }
};

int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<vector<int>> processes(n);
    vector<int> completion(n, 0), tat(n, 0), wt(n, 0), origBT(n, 0);

    for (int i = 0; i < n; i++)
    {
        int at, bt, pr;
        cout << "Enter arrival, burst, priority for P" << i + 1 << ": ";
        cin >> at >> bt >> pr;
        processes[i] = {i + 1, at, bt, pr};
        origBT[i] = bt;
    }

    sort(processes.begin(), processes.end(),
         [](vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; });

    priority_queue<vector<int> *, vector<vector<int> *>, Compare> pq;

    int t = 0;
    int k = 0;
    int completed = 0;

    while (!pq.empty() || k < n)
    {
        while (k < n && processes[k][1] <= t)
        {
            pq.push(&processes[k]);
            k++;
        }

        if (!pq.empty())
        {
            vector<int> *cur = pq.top();
            pq.pop();

            (*cur)[2]--;

            if ((*cur)[2] == 0)
            {
                int pid = (*cur)[0] - 1;
                completion[pid] = t + 1;
                tat[pid] = completion[pid] - (*cur)[1];
                wt[pid] = tat[pid] - origBT[pid];
                completed++;
            }
            else
            {
                pq.push(cur);
            }
        }
        t++;
    }

    double avgTAT = 0, avgWT = 0;
    cout << "\nCompletion Time\n";
    for (int i = 0; i < n; i++)
        cout << "Process " << processes[i][0] << "\t" << completion[processes[i][0] - 1] << "\n";

    cout << "\nTurnaround Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Process " << processes[i][0] << "\t" << tat[processes[i][0] - 1] << "\n";
        avgTAT += tat[processes[i][0] - 1];
    }

    cout << "\nWaiting Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Process " << processes[i][0] << "\t" << wt[processes[i][0] - 1] << "\n";
        avgWT += wt[processes[i][0] - 1];
    }

    cout << "Average Waiting Time = " << avgWT / n << "\n";
}
