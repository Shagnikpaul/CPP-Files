/*
23BCT0266
*/

#include <bits/stdc++.h>
using namespace std;

int precedence(char op)
{
    if (op == '*')
        return 1;
    if (op == '+')
        return 2;
    if (op == '-')
        return 2;
    if (op == '/')
        return 2;
    return 0;
}

vector<string> infixToPostfix(const string &expr)
{
    vector<string> output;
    stack<char> ops;
    for (int i = 0; i < (int)expr.size();)
    {
        if (isspace(expr[i]))
        {
            i++;
            continue;
        }

        if (isdigit(expr[i]))
        {
            string num;
            while (i < (int)expr.size() && isdigit(expr[i]))
            {
                num.push_back(expr[i]);
                i++;
            }
            output.push_back(num);
        }
        else if (strchr("+-*/", expr[i]))
        {
            char op = expr[i];
            while (!ops.empty() && precedence(ops.top()) >= precedence(op))
            {
                output.push_back(string(1, ops.top()));
                ops.pop();
            }
            ops.push(op);
            i++;
        }
        else
        {
            cerr << "Invalid char " << expr[i] << "\n";
            exit(1);
        }
    }
    while (!ops.empty())
    {
        output.push_back(string(1, ops.top()));
        ops.pop();
    }
    return output;
}

long long evalPostfix(const vector<string> &postfix)
{
    stack<long long> st;
    for (auto &tok : postfix)
    {
        if (isdigit(tok[0]))
        {
            st.push(stoll(tok));
            cout << "F -> id, F.val = " << tok << "\n";
        }
        else
        {
            long long b = st.top();
            st.pop();
            long long a = st.top();
            st.pop();
            long long res = 0;
            if (tok == "+")
            {
                res = a + b;
                cout << "T -> T + F, T.val = " << a << " + " << b << " = " << res << "\n";
            }
            else if (tok == "-")
            {
                res = a - b;
                cout << "T -> T - F , T.val = " << a << " - " << b << " = " << res << "\n";
            }
            else if (tok == "*")
            {
                res = a * b;
                cout << "E -> E * T , E.val = " << a << " * " << b << " = " << res << "\n";
            }
            else if (tok == "/")
            {
                res = a / b;
                cout << "T -> T / F, T.val = " << a << " / " << b << " = " << res << "\n";
            }
            st.push(res);
        }
    }
    return st.top();
}

int main()
{
    string expr = "8 # 12 & 4 # 16 & 12 # 4 & 2";
    long long target = 512;

    vector<char> ops = {'+', '-', '*', '/'};
    char correctCandidate = 0;
    cout << "\n\n23BCT0266\n\n";
    for (char candidate : ops)
    {
        cout << "\n=== Trying &: " << candidate << " ===\n";
        string trial = expr;
        for (char &c : trial)
        {
            if (c == '#')
                c = '*';
            if (c == '&')
                c = candidate;
        }

        auto postfix = infixToPostfix(trial);
        long long val = evalPostfix(postfix);

        cout << "Final Value = " << val;
        if (val == target)
        {
            cout << "  (CORRECT VALUE) ";
            correctCandidate = candidate;
        }
        cout << "\n";
    }

    if (correctCandidate != 0)
    {
        string newExpr = "12#6 & 4#8 & 4#6 & 2";
        cout << "\n=== Evaluating new expression with &: " << correctCandidate << " ===\n";
        for (char &c : newExpr)
        {
            if (c == '#')
                c = '*';
            if (c == '&')
                c = correctCandidate;
        }

        cout << "Expression after replacement: " << newExpr << "\n\n";

        auto postfix = infixToPostfix(newExpr);
        long long newVal = evalPostfix(postfix);
        cout << "\nFinal Value of new expression = " << newVal << "\n";
    }
    else
    {
        cout << "No correct & operator found.\n";
    }
}
