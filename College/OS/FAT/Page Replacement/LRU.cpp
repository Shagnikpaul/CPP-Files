#include <iostream>
using namespace std;

void pri(int *f, int m)
{
    for (int i = 0; i < m; i++)
    {
        if (f[i] == -1)
        {
            cout << "_, ";
        }
        else
        {
            cout << f[i] << ", ";
        }
    }
    cout << "\n";
}
int main()
{
    int n;
    cout << "Total frames to insert : ";
    cin >> n;
    int m;
    cout << "Total frames size : ";
    cin >> m;

    int seq[n];
    int f[m];

    cout << "Enter the sequence of frame access : ";
    for (int i = 0; i < n; i++)
    {
        cin >> seq[i];
    }

    for (int i = 0; i < m; i++)
    {
        f[i] = -1;
    }

    int fault = 0;

    int last[m];

    for (int i = 0; i < n; i++)
    {
        int ok = 0;
        for (int j = 0; j < m; j++)
        {
            if (f[j] == seq[i])
            {
                last[j] = i;
                ok = 1;
                break;
            }
        }

        if (!ok)
        {
            fault++;
            int done = 0;
            for (int j = 0; j < m; j++)
            {
                if (f[j] == -1)
                {
                    f[j] = seq[i];
                    done = 1;
                    last[j] = i;
                    break;
                }
            }
            if (!done)
            {
                int pos = -1;
                int minI = 99999;
                for (int j = 0; j < m; j++)
                {
                    if (last[j] < minI)
                    {
                        minI = last[j];
                        pos = j;
                    }
                }
                f[pos] = seq[i];
                last[pos] = i;
            }
        }
        pri(f, m);
    }
    cout << "\nTotal faults  : " << fault;
    double fP = (float)fault / (float)n;
    cout << "F % : " << fP * 100;
    return 0;
}