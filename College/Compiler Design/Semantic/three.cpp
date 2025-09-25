#include <bits/stdc++.h>
using namespace std;

// Convert infix to postfix with custom precedence
vector<string> infixToPostfixCustom(const string &expr, char candidate)
{
    vector<string> output;
    stack<char> ops;

    auto precedence = [&](char op) -> int
    {
        if (op == candidate)
            return 2; // & candidate: higher precedence
        if (op == '*')
            return 1; // # (multiply) lowest precedence
        if (op == '/')
            return 2; // just for safety if candidate is '/'
        if (op == '+')
            return 2; // same
        if (op == '-')
            return 2; // same
        return 0;
    };

    for (size_t i = 0; i < expr.size();)
    {
        char c = expr[i];
        if (isspace(c))
        {
            ++i;
            continue;
        }

        if (isdigit(c))
        {
            string num;
            while (i < expr.size() && isdigit(expr[i]))
            {
                num.push_back(expr[i]);
                ++i;
            }
            output.push_back(num);
        }
        else
        {
            char op = c;
            while (!ops.empty() && precedence(ops.top()) >= precedence(op))
            {
                output.push_back(string(1, ops.top()));
                ops.pop();
            }
            ops.push(op);
            ++i;
        }
    }

    while (!ops.empty())
    {
        output.push_back(string(1, ops.top()));
        ops.pop();
    }

    return output;
}

// Evaluate postfix
long long evalPostfix(const vector<string> &postfix)
{
    stack<long long> st;
    for (auto &tok : postfix)
    {
        if (isdigit(tok[0]))
        {
            st.push(stoll(tok));
        }
        else
        {
            long long b = st.top();
            st.pop();
            long long a = st.top();
            st.pop();
            long long res = 0;
            if (tok == "+")
                res = a + b;
            else if (tok == "-")
                res = a - b;
            else if (tok == "*")
                res = a * b;
            else if (tok == "/")
                res = a / b;
            st.push(res);
        }
    }
    return st.top();
}

int main()
{
    string expr = "8 # 12 & 4 # 16 & 12 # 4 & 2";
    long long target = 512;
    vector<char> candidates = {'+', '-', '*', '/'};

    for (char cand : candidates)
    {
        string trial = expr;
        // Replace symbols
        for (char &c : trial)
        {
            if (c == '#')
                c = '*'; // # is multiplication
            if (c == '&')
                c = cand; // candidate operator
        }

        auto postfix = infixToPostfixCustom(trial, cand);
        long long val = evalPostfix(postfix);

        cout << "Trying &: " << cand << " => " << val;
        if (val == target)
            cout << "  <-- MATCH ";
        cout << "\n";
    }
}
