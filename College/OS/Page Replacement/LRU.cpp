/*
    23BCT0266 - LRU Page Replacement
*/

#include <iostream>
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

    int f[50], lastUsed[50];
    for (int i = 0; i < m; i++)
    {
        f[i] = -1;
        lastUsed[i] = -1;
    }

    int fault = 0;

    cout << "\nFrame status after each page reference:\n";
    for (int i = 0; i < n; i++)
    {
        int x = a[i], ok = 0;

        // Check if page already in frame (HIT)
        for (int j = 0; j < m; j++)
        {
            if (f[j] == x)
            {
                ok = 1;
                lastUsed[j] = i; // update last used time
                break;
            }
        }

        // Page fault
        if (!ok)
        {
            fault++;
            int pos = -1;

            // Find an empty slot first
            for (int j = 0; j < m; j++)
            {
                if (f[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            // If no empty slot, replace least recently used page
            if (pos == -1)
            {
                int lru = 0;
                for (int j = 1; j < m; j++)
                {
                    if (lastUsed[j] < lastUsed[lru]) // smallest lastused means least recently used...
                        lru = j;
                }
                pos = lru;
            }

            f[pos] = x;
            lastUsed[pos] = i; // update time
        }
        printFrameStatus(f, m);
    }

    cout << "\nTotal page faults : " << fault;
    cout << "\nTotal page hits : " << (n - fault);
    cout << "\nPercentage of page faults : " << (((float)fault / (float)n) * 100.0) << "%";
}
