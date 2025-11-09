#include <iostream>

using namespace std;

int main()
{

    int n;
    cout << "Enter the no of processes ... ";
    cin >> n;
    int m;
    cout << "Enter the no of type of processes... ";
    cin >> m;

    int allo[n][m];
    int max[n][m];
    int need[n][m];
    int work[m];
    int available[m];

    int done[n];
    for (int i = 0; i < n; i++)
        done[i] = 0;

    cout << "Enter the allocation matrix : ";
    for (int i = 0; i < n; i++)
    {
        cout << "Process " << (i) << ": ";
        for (int j = 0; j < m; j++)
        {
            cin >> allo[i][j];
        }
    }

    cout << "Enter the max matrix : ";
    for (int i = 0; i < n; i++)
    {
        cout << "Process " << (i) << ": ";
        for (int j = 0; j < m; j++)
        {
            cin >> max[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allo[i][j];
        }
    }

    cout << "Enter the available resources : ";
    for (int i = 0; i < m; i++)
    {
        cin >> available[i];
        work[i] = available[i];
    }

    int doneCount = 0;
    int unsafe = 0;

    while ((doneCount != n) && !unsafe)
    {
        int isAssigned = 0;
        for (int i = 0; i < n; i++)
        {
            if (done[i])
                continue;
            int compi = 1;
            for (int j = 0; j < m; j++)
            {
                if (need[i][j] > work[j])
                {
                    compi = 0;
                    break;
                }
            }
            if (compi)
            {
                cout << "Ran Process " << (i + 1) << "\n";
                done[i] = 1;
                isAssigned = 1;
                doneCount++;
                for (int j = 0; j < m; j++)
                {
                    work[j] += allo[i][j];
                }
                break;
            }
        }
        if (isAssigned)
        {
            continue;
        }
        else
        {
            unsafe = 1;
            break;
        }
    }

    if (unsafe)
    {
        cout << "Cant generate safe sequence...";
    }

    cout << "Any additional req ?? type its no. else -1: ";
    int p;
    cin >> p;
    if (p >= 1 && p <= n)
    {
        p--;
        cout << "Enter the resources for the request : ";
        int req[m];
        for (int i = 0; i < m; i++)
        {
            cin >> req[i];
        }

        for (int i = 0; i < m; i++)
        {
            if (req[i] > need[p][i])
            {
                cout << "NUH UH MORE THAN NEEDED";
                return 0;
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (req[i] > available[i])
            {
                cout << "NUH UH MORE THAN AVAILABLE";
                return 0;
            }
        }

        for (int i = 0; i < m; i++)
        {
            need[p][i] -= req[i];
            available[i] -= req[i];
            allo[p][i] += req[i];
        }
        for (int i = 0; i < n; i++)
        {
            done[i] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            work[i] = available[i];
        }

        doneCount = 0;
        unsafe = 0;

        while ((doneCount != n) && !unsafe)
        {
            int isAssigned = 0;
            for (int i = 0; i < n; i++)
            {
                if (done[i])
                    continue;
                int compi = 1;
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        compi = 0;
                        break;
                    }
                }
                if (compi)
                {
                    cout << "\nRan Process " << (i + 1) << "\n";
                    done[i] = 1;
                    isAssigned = 1;
                    doneCount++;
                    for (int j = 0; j < m; j++)
                    {
                        work[j] += allo[i][j];
                    }
                    break;
                }
            }
            if (isAssigned)
            {
                continue;
            }
            else
            {
                unsafe = 1;
                break;
            }
        }
    }

    return 0;
}