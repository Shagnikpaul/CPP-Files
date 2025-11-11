

#include <bits/stdc++.h>

using namespace std;

// Function to tokenize input (id, +, *, (, ), $)
vector<string> tokenize(const string &input)
{
    vector<string> tokens;
    for (int i = 0; i < input.size();)
    {
        if (isspace(input[i]))
        {
            i++;
            continue;
        }

        if (isalpha(input[i]))
        {
            tokens.push_back("id");
            while (isalnum(input[i]))
                i++; // skip variable name
        }
        else
        {
            string op(1, input[i]);
            tokens.push_back(op);
            i++;
        }
    }
    tokens.push_back("$"); // end marker
    return tokens;
}

int main()
{
    string input;
    cout << "Enter expression: ";
    getline(cin, input);

    vector<string> tokens = tokenize(input);
    stack<string> st;

    st.push("$");
    st.push("E");

    int i = 0;
    cout << "\n--- LL(1)-like Parsing Simulation ---\n";

    while (!st.empty())
    {
        string top = st.top();
        string current = tokens[i];

        cout << "Stack: ";
        stack<string> temp = st;
        vector<string> s;
        while (!temp.empty())
        {
            s.push_back(temp.top());
            temp.pop();
        }
        for (int j = s.size() - 1; j >= 0; j--)
            cout << s[j] << " ";
        cout << "    Input: " << current << endl;

        if (top == current && top == "$")
        {
            cout << "\n✅ Input accepted!\n";
            break;
        }
        else if (top == current)
        {
            st.pop();
            i++;
        }
        else if (top == "E")
        {
            cout << "Use Production: E -> T E'\n";
            st.pop();
            st.push("E'");
            st.push("T");
        }
        else if (top == "E'")
        {
            if (current == "+")
            {
                cout << "Use Production: E' -> + T E'\n";
                st.pop();
                st.push("E'");
                st.push("T");
                st.push("+");
            }
            else
            {
                cout << "Use Production: E' -> null\n";
                st.pop(); // epsilon
            }
        }
        else if (top == "T")
        {
            cout << "Use Production: T -> F T'\n";
            st.pop();
            st.push("T'");
            st.push("F");
        }
        else if (top == "T'")
        {
            if (current == "*")
            {
                cout << "Use Production: T' -> * F T'\n";
                st.pop();
                st.push("T'");
                st.push("F");
                st.push("*");
            }
            else
            {
                cout << "Use Production: T' -> null\n";
                st.pop();
            }
        }
        else if (top == "F")
        {
            if (current == "id")
            {
                cout << "Use Production: F -> id\n";
                st.pop();
                st.push("id");
            }
            else if (current == "(")
            {
                cout << "Use Production: F -> ( E )\n";
                st.pop();
                st.push(")");
                st.push("E");
                st.push("(");
            }
            else
            {
                cout << "❌ Error: invalid token for F\n";
                break;
            }
        }
        else
        {
            cout << "❌ Error: unexpected symbol " << top << endl;
            break;
        }
    }

    return 0;
}
