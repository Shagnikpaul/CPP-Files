/*
    23BCT0266
*/

#include <iostream>
#include <queue>
using namespace std;

void printFrameStatus(int *f, int m)
{
    for (int j = 0; j < m; j++)
        if (f[j] != -1)
            cout << f[j] << " ";
        else
            cout << "- ";
    cout << endl;
}

int main()
{
    int n, m;
    cout << "Enter the no of page references : ";
    cin >> n;
    int a[100];
    cout << "Enter the sequence of page references : ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Enter the frame size :  ";
    cin >> m;

    int f[50];
    for (int i = 0; i < m; i++)
        f[i] = -1;
    int fault = 0;
    queue<int> q;
    cout << "Frame status after each page reference: \n";
    for (int i = 0; i < n; i++)
    {
        int x = a[i], ok = 0;
        for (int j = 0; j < m; j++)
            if (f[j] == x)
                ok = 1;

        if (!ok)
        {
            fault++;
            if (q.size() < m)
            {
                for (int j = 0; j < m; j++)
                    if (f[j] == -1)
                    {
                        f[j] = x;
                        break;
                    }
                q.push(x);
            }
            else
            {
                int r = q.front();
                q.pop();
                for (int j = 0; j < m; j++)
                    if (f[j] == r)
                    {
                        f[j] = x;
                        break;
                    }
                q.push(x);
            }
        }

        printFrameStatus(f, m);
    }
    cout << "\nTotal page faults : " << fault;
    cout << "\nTotal page hits : " << (n - fault);

    cout << "\nPercentage of page faults : " << (((float)fault / (float)n) * 100.0) << "%";
}
