#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to return precedence of operators
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to check if a character is an operator
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int main()
{
    string expr;
    cout << "Enter an expression: ";
    getline(cin, expr);

    stack<string> st;  // stack to hold operands and temporaries
    stack<char> op;    // stack to hold operators
    int tempCount = 0; // for generating t1, t2, ...

    for (int i = 0; i < expr.size(); i++)
    {
        char c = expr[i];
        if (c == ' ' || c == '\t')
            continue; // ignore spaces

        if (isalnum(c)) // operand (variable or number)
        {
            string operand(1, c);
            st.push(operand);
        }
        else if (isOperator(c))
        {
            // Handle operator precedence
            while (!op.empty() && precedence(op.top()) >= precedence(c))
            {
                string right = st.top();
                st.pop();
                string left = st.top();
                st.pop();
                char oper = op.top();
                op.pop();

                string temp = "t" + to_string(tempCount++);
                cout << temp << " = " << left << " " << oper << " " << right << endl;
                st.push(temp);
            }
            op.push(c);
        }
    }

    // Process remaining operators
    while (!op.empty())
    {
        string right = st.top();
        st.pop();
        string left = st.top();
        st.pop();
        char oper = op.top();
        op.pop();

        string temp = "t" + to_string(tempCount++);
        cout << temp << " = " << left << " " << oper << " " << right << endl;
        st.push(temp);
    }

    cout << "\nFinal Result stored in: " << st.top() << endl;
    return 0;
}
