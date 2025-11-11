#include <bits/stdc++.h>
using namespace std;

// return precedence of operator
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// apply operator on two operands
double applyOp(double a, double b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
        {
            cout << "Error: Division by zero\n";
            exit(1);
        }
        return a / b;
    }
    return 0;
}

// evaluate an expression without parentheses
double evaluate(const string &expr)
{
    stack<double> values; // numbers
    stack<char> ops;      // operators

    for (int i = 0; i < expr.length(); i++)
    {
        char c = expr[i];

        // skip spaces
        if (c == ' ')
            continue;

        // if number, parse full number
        if (isdigit(c))
        {
            double val = 0;
            while (i < expr.length() && isdigit(expr[i]))
            {
                val = val * 10 + (expr[i] - '0');
                i++;
            }
            i--; // step back
            values.push(val);
        }

        // if operator
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            while (!ops.empty() && precedence(ops.top()) >= precedence(c))
            {
                double b = values.top();
                values.pop();
                double a = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(a, b, op));
            }
            ops.push(c);
        }
    }

    // apply remaining ops
    while (!ops.empty())
    {
        double b = values.top();
        values.pop();
        double a = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        values.push(applyOp(a, b, op));
    }

    return values.top();
}

int main()
{
    string expr;
    cout << "Enter expression (no parentheses): ";
    getline(cin, expr);

    cout << "Result = " << evaluate(expr) << endl;
    return 0;
}
