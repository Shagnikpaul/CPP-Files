/*
23BCT0266

*/


#include <bits/stdc++.h>
using namespace std;

int precedence(char op)
{
    if (op == '*')
        return 2;
    if (op == '+')
        return 1;
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
        else if (expr[i] == '+' || expr[i] == '*')
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
            cerr << "Invalid character: " << expr[i] << "\n";
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
            long long val = stoll(tok);
            st.push(val);
            cout << "F -> id  (F.val = " << val << ")\n";
            cout << "T -> F   (T.val = " << val << ")\n";
            cout << "E -> T   (E.val = " << val << ")\n";
        }
        else if (tok == "*")
        {
            long long b = st.top();
            st.pop();
            long long a = st.top();
            st.pop();
            long long res = a * b;
            st.push(res);
            cout << "T -> T * F  (T.val = " << res << ")\n";
        }
        else if (tok == "+")
        {
            long long b = st.top();
            st.pop();
            long long a = st.top();
            st.pop();
            long long res = a + b;
            st.push(res);
            cout << "E -> E + T  (E.val = " << res << ")\n";
        }
    }
    return st.top();
}

int main()
{
    cout << "\n\n 23BCT0266 \n\n";
    cout << "Enter expression (digits, +, *):\n";
    string expr;
    getline(cin, expr);

    vector<string> postfix = infixToPostfix(expr);
    long long result = evalPostfix(postfix);

    cout << "\nValue = " << result << "\n";
    return 0;
}
