#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cout << "No of page elements in the sequence : ";
    cin >> n;
    int pages[100];
    cout << "Enter the sequence : ";
    for (int i = 0; i < n; i++)
        cin >> pages[i];
    cout << "No of page table size : ";
    cin >> m;

    int frames[50];
    for (int i = 0; i < m; i++)
        frames[i] = -1;

    int faults = 0, hits = 0;

    for (int i = 0; i < n; i++)
    {
        int p = pages[i];
        bool found = false;
        for (int j = 0; j < m; j++)
            if (frames[j] == p)
                found = true;

        if (!found)
        {
            faults++;
            int pos = -1;
            for (int j = 0; j < m; j++)
                if (frames[j] == -1)
                {
                    pos = j;
                    break;
                }

            if (pos == -1)
            {
                int far = -1, victim = -1;
                for (int j = 0; j < m; j++)
                {
                    int k;
                    for (k = i + 1; k < n; k++)
                        if (pages[k] == frames[j])
                            break;
                    if (k == n)
                    {
                        victim = j;
                        break;
                    }
                    if (k > far)
                    {
                        far = k;
                        victim = j;
                    }
                }
                pos = victim;
            }
            frames[pos] = p;
        }
        else
            hits++;

        for (int j = 0; j < m; j++)
            cout << (frames[j] == -1 ? "- " : to_string(frames[j]) + " ");
        cout << endl;
    }

    cout << "Faults: " << faults << "\nHits: " << hits
         << "\nFault %: " << (faults * 100.0 / n)
         << "\nHit %: " << (hits * 100.0 / n);
}
