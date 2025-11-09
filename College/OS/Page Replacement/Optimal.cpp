#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cout << "No of page elements in the sequence : ";
    cin >> n; // Total number of pages in the reference string

    int pages[100];
    cout << "Enter the sequence : ";
    for (int i = 0; i < n; i++)
        cin >> pages[i]; // Input the page reference string

    cout << "No of page table size : ";
    cin >> m; // Total number of frames available in memory

    int frames[50];
    for (int i = 0; i < m; i++)
        frames[i] = -1; // Initialize all frames as empty (-1)

    int faults = 0, hits = 0; // Counters for page faults and hits

    // Loop through each page in the reference string
    for (int i = 0; i < n; i++)
    {
        int p = pages[i];   // Current page to be referenced
        bool found = false; // Flag to check if page is already in memory

        // Step 1: Check if the page is already present in any frame
        for (int j = 0; j < m; j++)
            if (frames[j] == p)
                found = true; // Page hit

        // Step 2: If page not found, a page fault occurs
        if (!found)
        {
            faults++;

            int pos = -1; // Position to replace or insert new page

            // Step 3: Check if there is any empty frame available
            for (int j = 0; j < m; j++)
                if (frames[j] == -1)
                {
                    pos = j; // Found an empty frame
                    break;
                }

            // Step 4: If no empty frame, use Optimal Replacement logic
            if (pos == -1)
            {
                int far = -1;    // Tracks farthest future use of a page
                int victim = -1; // Index of frame to be replaced

                // For each page currently in frame
                for (int j = 0; j < m; j++)
                {
                    int k;
                    // Find the next occurrence of frames[j] in the future
                    for (k = i + 1; k < n; k++)
                        if (pages[k] == frames[j])
                            break;

                    // If the page is never used again, replace it immediately
                    if (k == n)
                    {
                        victim = j;
                        break;
                    }

                    // Otherwise, choose the page used farthest in the future
                    if (k > far)
                    {
                        far = k;
                        victim = j;
                    }
                }
                pos = victim; // Page to be replaced
            }

            // Step 5: Replace or insert the new page
            frames[pos] = p;
        }
        else
            hits++; // Page was already present, no fault

        // Step 6: Print current state of frames after each reference
        for (int j = 0; j < m; j++)
            cout << (frames[j] == -1 ? "- " : to_string(frames[j]) + " ");
        cout << endl;
    }

    // Step 7: Print final statistics
    cout << "Faults: " << faults << "\nHits: " << hits
         << "\nFault %: " << (faults * 100.0 / n)
         << "\nHit %: " << (hits * 100.0 / n);
}
