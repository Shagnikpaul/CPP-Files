#include <iostream>
#include <string>

using namespace std;

int countStepsToReduce(string str, char infectedLetter)
{
    int count = 0;

    while (true)
    {
        int pos = str.find(infectedLetter); // Find the first occurrence of infectedLetter

        // If the infectedLetter is found and has a left character to remove
        if (pos != string::npos && pos > 0)
        {
            str.erase(pos - 1, 1); // Remove the character left of infectedLetter
            count++;               // Increment step count
        }
        else
        {
            break; // Stop if no more deletions can be performed
        }
    }

    return count;
}

int main()
{
    int n = 7;
    string input = "abcdaed";
    char infectedLetter = 'd';

    int result = countStepsToReduce(input, infectedLetter);

    cout << "Count: " << result << endl;
    return 0;
}
