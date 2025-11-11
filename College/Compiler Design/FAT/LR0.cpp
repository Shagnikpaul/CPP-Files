#include <bits/stdc++.h>
using namespace std;

struct Action
{
    char type; // 's' = shift, 'r' = reduce, 'a' = accept
    int value; // next state or rule number
};

struct Rule
{
    string lhs;
    string rhs;
};

int main()
{
    // Define grammar rules
    vector<Rule> rules = {
        {"", ""},     // dummy 0
        {"E", "E+E"}, // r1
        {"E", "E*E"}, // r2
        {"E", "id"}   // r3
    };

    // Parsing table (state -> symbol -> Action)
    map<int, map<string, Action>> table;

    table[0]["id"] = {'s', 5};
    table[0]["E"] = {'s', 1};

    table[1]["+"] = {'s', 2};
    table[1]["*"] = {'s', 3};
    table[1]["$"] = {'a', 0};

    table[2]["id"] = {'s', 5};
    table[2]["E"] = {'s', 4};

    table[3]["id"] = {'s', 5};
    table[3]["E"] = {'s', 6};

    table[4]["+"] = {'r', 1};
    table[4]["*"] = {'r', 1};
    table[4]["$"] = {'r', 1};

    table[5]["+"] = {'r', 3};
    table[5]["*"] = {'r', 3};
    table[5]["$"] = {'r', 3};

    table[6]["+"] = {'r', 2};
    table[6]["*"] = {'r', 2};
    table[6]["$"] = {'r', 2};

    string input;
    cout << "Enter expression (e.g. id+id*id): ";
    cin >> input;
    input += '$';

    vector<int> stateStack = {0};
    vector<string> symbolStack;
    int i = 0;

    cout << left << setw(20) << "Stack"
         << setw(20) << "Input"
         << "Action" << endl;

    while (true)
    {
        int state = stateStack.back();
        string symbol;

        // read next token (id or operator)
        if (input.substr(i, 2) == "id")
        {
            symbol = "id";
        }
        else
        {
            symbol = string(1, input[i]);
        }

        Action act = table[state][symbol];

        cout << left;
        cout << setw(20);
        {
            string st;
            for (auto s : symbolStack)
                st += s;
            st += "(" + to_string(state) + ")";
            cout << st;
        }
        cout << setw(20) << input.substr(i);

        if (act.type == 's')
        {
            cout << "Shift " << act.value << endl;
            symbolStack.push_back(symbol);
            stateStack.push_back(act.value);
            if (symbol == "id")
                i += 2;
            else
                i++;
        }
        else if (act.type == 'r')
        {
            Rule r = rules[act.value];
            cout << "Reduce " << r.lhs << "->" << r.rhs << endl;

            // pop rhs symbols
            for (int k = 0; k < r.rhs.size();)
            {
                if (r.rhs.substr(k, 2) == "id")
                {
                    symbolStack.pop_back();
                    stateStack.pop_back();
                    k += 2;
                }
                else
                {
                    symbolStack.pop_back();
                    stateStack.pop_back();
                    k++;
                }
            }

            symbolStack.push_back(r.lhs);
            int s = stateStack.back();
            Action next = table[s][r.lhs];
            stateStack.push_back(next.value);
        }
        else if (act.type == 'a')
        {
            cout << "Accept" << endl;
            break;
        }
        else
        {
            cout << "Error" << endl;
            break;
        }
    }

    return 0;
}
