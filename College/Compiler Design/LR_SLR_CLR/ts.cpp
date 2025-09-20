/*
    23BCT0266

*/

#include <bits/stdc++.h>
using namespace std;

map<string, map<string, vector<string>>> table;

bool isTerm(const string &sym)
{
    return !(sym == "E" || sym == "E'" || sym == "T" || sym == "T'" || sym == "F");
}

vector<string> tokenize(const string &s)
{
    vector<string> toks;
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
            toks.push_back("id");
        }
        else if (c == '+' || c == '*' || c == '(' || c == ')')
        {
            toks.push_back(string(1, c));
        }
        else
        {
            cout << "Invalid character in expression: " << c << "\n";
            exit(0);
        }
    }
    toks.push_back("$");
    return toks;
}

int main()
{
    cout << "\n\n23BCT0266\n\n";
    table["E"]["("] = {"T", "E'"};
    table["E"]["id"] = {"T", "E'"};

    table["E'"]["+"] = {"+", "T", "E'"};
    table["E'"][")"] = {"eps"};
    table["E'"]["$"] = {"eps"};

    table["T"]["("] = {"F", "T'"};
    table["T"]["id"] = {"F", "T'"};

    table["T'"]["*"] = {"*", "F", "T'"};
    table["T'"]["+"] = {"eps"};
    table["T'"][")"] = {"eps"};
    table["T'"]["$"] = {"eps"};

    table["F"]["("] = {"(", "E", ")"};
    table["F"]["id"] = {"id"};

    cout << "Enter an expression to parse:\n";
    string expr;
    getline(cin, expr);

    vector<string> input = tokenize(expr);

    stack<string> st;
    st.push("$");
    st.push("E");

    int ip = 0;
    cout << "\nParsing process:\n";
    while (!st.empty())
    {
        string top = st.top();
        string cur = input[ip];

        cout << "[Top: " << top << " | Next: " << cur << "]\n";

        if (isTerm(top))
        {
            if (top == cur)
            {
                st.pop();
                ip++;
            }
            else if (top == "eps")
            {
                st.pop();
            }
            else
            {
                cout << "Parsing failed: unexpected symbol.\n";
                return 0;
            }
        }
        else
        {
            if (table[top].find(cur) != table[top].end())
            {
                st.pop();
                vector<string> prod = table[top][cur];
                if (!(prod.size() == 1 && prod[0] == "eps"))
                {
                    for (int i = prod.size() - 1; i >= 0; i--)
                        st.push(prod[i]);
                }
                cout << "Applied rule: " << top << " -> ";
                for (auto &p : prod)
                    cout << p << " ";
                cout << "\n";
            }
            else
            {
                cout << "Parsing failed: no rule for (" << top << ", " << cur << ")\n";
                return 0;
            }
        }
    }

    if (ip == input.size())
        cout << "\nExpression was parsed and accepted.\n";
    else
        cout << "\nExpression was parsed and rejected.\n";

    return 0;
}
