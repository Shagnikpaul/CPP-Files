/*

    23BCT0266
*/


#include <bits/stdc++.h>
using namespace std;

static const string TER = "+*()i$";

static map<char, map<char, char>> P = {
    {'+', {{'+', '>'}, {'*', '<'}, {'(', '<'}, {')', '>'}, {'i', '<'}, {'$', '>'}}},
    {'*', {{'+', '>'}, {'*', '>'}, {'(', '<'}, {')', '>'}, {'i', '<'}, {'$', '>'}}},
    {'(', {{'+', '<'}, {'*', '<'}, {'(', '<'}, {')', '='}, {'i', '<'}, {'$', ' '}}},
    {')', {{'+', '>'}, {'*', '>'}, {')', '>'}, {'$', '>'}}},
    {'i', {{'+', '>'}, {'*', '>'}, {')', '>'}, {'$', '>'}}},
    {'$', {{'+', '<'}, {'*', '<'}, {'(', '<'}, {'i', '<'}, {'$', '='}}}};

static bool isTerminal(char c) { return TER.find(c) != string::npos; }

static int topTerminalIndex(const vector<char> &st)
{
    for (int i = (int)st.size() - 1; i >= 0; --i)
        if (isTerminal(st[i]))
            return i;
    return -1;
}

static string stackStr(const vector<char> &st)
{
    string s;
    for (char c : st)
    {
        if (c == 'i')
            s += "i";
        else if (c == 'N')
            s += "E";
        else
            s.push_back(c);
    }
    return s;
}

static bool reduceOnce(vector<char> &st, string &action)
{
    if (!st.empty() && st.back() == 'i')
    {
        st.pop_back();
        st.push_back('N');
        action += "Reduce id -> N";
        return true;
    }
    if (st.size() >= 3 &&
        st[st.size() - 3] == '(' && st[st.size() - 2] == 'N' && st[st.size() - 1] == ')')
    {
        st.pop_back();
        st.pop_back();
        st.pop_back();
        st.push_back('N');
        action += "Reduce (E) -> N";
        return true;
    }
    if (st.size() >= 3 &&
        st[st.size() - 3] == 'N' && st[st.size() - 2] == '*' && st[st.size() - 1] == 'N')
    {
        st.pop_back();
        st.pop_back();
        st.pop_back();
        st.push_back('N');
        action += "Reduce N*N -> N";
        return true;
    }
    if (st.size() >= 3 &&
        st[st.size() - 3] == 'N' && st[st.size() - 2] == '+' && st[st.size() - 1] == 'N')
    {
        st.pop_back();
        st.pop_back();
        st.pop_back();
        st.push_back('N');
        action += "Reduce N+N -> N";
        return true;
    }
    return false;
}

static vector<char> tokenize(const string &s)
{
    vector<char> t;
    for (size_t i = 0; i < s.size();)
    {
        if (isspace((unsigned char)s[i]))
        {
            ++i;
            continue;
        }
        if (i + 1 < s.size() && s.substr(i, 2) == "id")
        {
            t.push_back('i');
            i += 2;
            continue;
        }
        char c = s[i];
        if (c == '+' || c == '*' || c == '(' || c == ')')
        {
            t.push_back(c);
            ++i;
            continue;
        }
        throw runtime_error(string("Unexpected character: ") + c);
    }
    t.push_back('$');
    return t;
}

static void parse(const string &in)
{
    vector<char> input = tokenize(in);
    vector<char> st;
    st.push_back('$');

    cout << "\n--- Operator Precedence Parsing ---\n";
    cout << left << setw(16) << "Stack" << setw(24) << "Input" << "Action\n";

    size_t ip = 0;
    while (true)
    {
        if (st.size() == 2 && st[0] == '$' && st[1] == 'N' && input[ip] == '$')
        {
            cout << left << setw(16) << stackStr(st)
                 << setw(24) << string(1, input[ip]) << "Accepted\n";
            break;
        }
        int ti = topTerminalIndex(st);
        if (ti < 0)
        {
            cerr << "No terminal on stack — invalid state\n";
            return;
        }
        char a = st[ti];
        char b = input[ip];

        string rest;
        for (size_t k = ip; k < input.size(); ++k)
        {
            if (input[k] == 'i')
                rest += "id";
            else
                rest.push_back(input[k]);
        }
        cout << left << setw(16) << stackStr(st) << setw(24) << rest;

        if (!P.count(a) || !P[a].count(b))
        {
            cout << "Error: no precedence between '" << a << "' and '" << b << "'\n";
            return;
        }
        char rel = P[a][b];

        if (rel == '<' || rel == '=')
        {
            cout << "Shift " << (b == 'i' ? "id" : string(1, b)) << "\n";
            st.push_back(b);
            ++ip;
        }
        else if (rel == '>')
        {
            string act;
            if (!reduceOnce(st, act))
            {
                cout << "Error: no handle to reduce\n";
                return;
            }
            cout << act << "\n";
        }
        else
        {
            cout << "Error: invalid precedence\n";
            return;
        }
    }
}

int main()
{
    try
    {
        string s;
        cout << "==============\n23BCT0266\n==============\n";
        cout << "Enter an expression (use 'id' for identifiers): ";
        getline(cin, s);
        parse(s);
    }
    catch (const exception &e)
    {
        cerr << "Failure: " << e.what() << "\n";
    }
    return 0;
}
