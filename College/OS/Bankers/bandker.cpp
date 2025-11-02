/*
    23BCT0266
*/

#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cout << "Enter the number of processes : ";
    cin >> n;

    cout << "No of type of resources : ";
    cin >> m;

    int alloc[n][m];
    int max[n][m];
    int need[n][m];

    cout << "Enter the current Resources allocations for : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "For Process " << (i) << ": ";
        for (int j = 0; j < m; j++)
        {
            cin >> alloc[i][j];
        }
    }

    cout << "Enter the MAX Resources allocations for : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "For Process " << (i) << ": ";
        for (int j = 0; j < m; j++)
        {
            cin >> max[i][j];
        }
    }

    // need
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    cout << "NEED MATRIX  : \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << need[i][j] << " ";
        }
        cout << "\n";
    }

    int done[n];
    for (int i = 0; i < n; i++)
        done[i] = 0;

    int available[m];
    int work[m];
    cout << "Enter the available resources ";
    for (int i = 0; i < m; i++)
    {
        cin >> available[i];
    }
    int unsafe = 0;
    int doneCount = 0;

    int extraReq = 0;
    cout << "Does any one of the processes have additional request ? If yes enter the process number else -1 for none" << endl;
    cin >> extraReq;
    if (extraReq >= 0 && extraReq < n)
    {
        cout << "Enter the resources needed for the request ";
        int req[m];
        for (int i = 0; i < m; i++)
        {
            cin >> req[i];
        }

        for (int j = 0; j < m; j++)
        {
            if (req[j] > need[extraReq][j])
            {
                cout << "Error: Process has exceeded its maximum claim.\n";
                return 0;
            }
        }

        for (int j = 0; j < m; j++)
        {
            if (req[j] > available[j])
            {
                cout << "Resources not available. Process must wait.\n";
                return 0;
            }
        }

        for (int i = 0; i < m; i++)
        {
            available[i] -= req[i];
            alloc[extraReq][i] += req[i];
            need[extraReq][i] -= req[i];
        }
    }

    for (int i = 0; i < m; i++)
    {
        work[i] = available[i];
    }

    while (doneCount != n && !unsafe)
    {
        int isSafe = 0;
        for (int i = 0; i < n; i++)
        {
            if (done[i] == 0)
            {
                int canBeFulf = 1;
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        canBeFulf = 0;
                        break;
                    }
                }
                if (canBeFulf)
                {
                    // add to seq

                    for (int k = 0; k < m; k++)
                    {
                        work[k] += alloc[i][k];
                    }
                    cout << "Ran process " << i << endl;

                    isSafe = 1;
                    done[i] = 1;
                    doneCount++;
                    break;
                }
            }
        }
        if (!isSafe)
        {
            unsafe = 1;
            break;
        }
    }
    if (unsafe)
    {
        cout << "No the system is not in safe state" << endl;
    }
    if (doneCount == n)
    {
        cout << "Yes the system is in safe state and the above sequence is the safe sequence" << endl;
    }
}
