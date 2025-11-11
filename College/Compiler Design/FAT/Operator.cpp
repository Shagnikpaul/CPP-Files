#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Precedence of operators
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Check if operator
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Display stack contents
void showStack(stack<char> st)
{
    string s = "";
    while (!st.empty())
    {
        s = st.top() + s;
        st.pop();
    }
    cout << s;
}

int main()
{
    string input;
    cout << "Enter expression: ";
    getline(cin, input);
    input += "$"; // end marker

    stack<char> st;
    st.push('$');

    cout << "\n--- Operator Precedence Parsing ---\n";

    int i = 0;
    while (i < input.size())
    {
        char current = input[i];
        if (current == ' ')
        {
            i++;
            continue;
        }

        cout << "Stack: ";
        showStack(st);
        cout << "   Input: " << current << "   ";

        if (current == '$' && st.top() == '$')
        {
            cout << "\n✅ Accepted!\n";
            break;
        }

        // Operand (id or number)
        if (isalnum(current))
        {
            cout << "Shift\n";
            st.push('E'); // push as expression
            i++;
        }

        else if (current == '(')
        {
            cout << "Shift\n";
            st.push('(');
            i++;
        }

        else if (current == ')')
        {
            cout << "Reduce\n";
            while (!st.empty() && st.top() != '(')
                st.pop();
            if (!st.empty())
                st.pop(); // remove '('
            st.push('E');
            i++;
        }

        else if (isOperator(current))
        {
            // Find topmost operator on stack
            char topOp = 0;
            stack<char> temp = st;
            while (!temp.empty())
            {
                if (isOperator(temp.top()))
                {
                    topOp = temp.top();
                    break;
                }
                temp.pop();
            }

            // Compare precedence
            if (topOp == 0 || precedence(current) > precedence(topOp))
            {
                cout << "Shift\n";
                st.push(current);
                i++;
            }
            else
            {
                cout << "Reduce\n";
                if (!st.empty())
                    st.pop(); // pop E
                if (!st.empty() && isOperator(st.top()))
                    st.pop();
                if (!st.empty() && st.top() == 'E')
                    st.pop();
                st.push('E');
            }
        }

        else if (current == '$')
        {
            if (st.size() == 2 && st.top() == 'E')
            {
                cout << "\n✅ Accepted!\n";
                break;
            }
            else
            {
                cout << "Reduce\n";
                if (!st.empty())
                    st.pop();
                st.push('E');
            }
        }

        else
        {
            cout << "❌ Invalid symbol: " << current << endl;
            break;
        }
    }

    return 0;
}
