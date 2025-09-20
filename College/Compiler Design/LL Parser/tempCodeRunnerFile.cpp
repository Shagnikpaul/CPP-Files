/*
    23BCT0266

*/



#include <bits/stdc++.h>
using namespace std;

map<string, map<string, vector<string>>> parsingTable;

bool isTerminal(const string &sym)
{
    return !(sym == "E" || sym == "E'" || sym == "T" || sym == "T'" || sym == "F");
}

vector<string> tokenize(const string &s)
{
    vector<string> tokens;
    string temp;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (isspace(c))
            continue;
        if (isalpha(c))
        {
            temp = "";
            while (i < s.size() && isalnum(s[i]))
            {
                temp += s[i];
                i++;
            }
            i--;
            tokens.push_back("id");
        }
        else if (c == '+' || c == '*' || c == '(' || c == ')')
        {
            tokens.push_back(string(1, c));
        }
        else
        {
            cout << "Invalid character in input: " << c << "\n";
            exit(0);
        }
    }
    tokens.push_back("$");
    return tokens;
}

int main()
{
    parsingTable["E"]["("] = {"T", "E'"};
    parsingTable["E"]["id"] = {"T", "E'"};

    parsingTable["E'"]["+"] = {"+", "T", "E'"};
    parsingTable["E'"][")"] = {"ε"};
    parsingTable["E'"]["$"] = {"ε"};

    parsingTable["T"]["("] = {"F", "T'"};
    parsingTable["T"]["id"] = {"F", "T'"};

    parsingTable["T'"]["*"] = {"*", "F", "T'"};
    parsingTable["T'"]["+"] = {"ε"};
    parsingTable["T'"][")"] = {"ε"};
    parsingTable["T'"]["$"] = {"ε"};

    parsingTable["F"]["("] = {"(", "E", ")"};
    parsingTable["F"]["id"] = {"id"};

    cout << "Enter the input expression:\n";
    string expr;
    getline(cin, expr);

    vector<string> input = tokenize(expr);

    stack<string> st;
    st.push("$");
    st.push("E");

    int ip = 0;
    cout << "\nParsing Steps:\n";
    while (!st.empty())
    {
        string top = st.top();
        string cur = input[ip];

        cout << "Stack top: " << top << " | Current input: " << cur << "\n";

        if (isTerminal(top))
        {
            if (top == cur)
            {
                st.pop();
                ip++;
            }
            else if (top == "ε")
            {
                st.pop();
            }
            else
            {
                cout << "Error: unexpected symbol!\n";
                return 0;
            }
        }
        else
        {
            if (parsingTable[top].find(cur) != parsingTable[top].end())
            {
                st.pop();
                vector<string> prod = parsingTable[top][cur];
                if (!(prod.size() == 1 && prod[0] == "ε"))
                {
                    for (int i = prod.size() - 1; i >= 0; i--)
                        st.push(prod[i]);
                }
                cout << top << " -> ";
                for (auto &p : prod)
                    cout << p << " ";
                cout << "\n";
            }
            else
            {
                cout << "Error: no rule for [" << top << "," << cur << "]\n";
                return 0;
            }
        }
    }

    if (ip == input.size())
        cout << "\nString Accepted \n";
    else
        cout << "\nString Rejected\n";

    return 0;
}
