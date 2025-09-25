#include <bits/stdc++.h>
using namespace std;

struct ASTNode
{
    string val;
    ASTNode *l, *r;
    ASTNode(string v) : val(v), l(nullptr), r(nullptr) {}
};

void displayTree(ASTNode *node, string prefix = "", bool leftChild = true)
{
    if (!node)
        return;
    cout << prefix;
    if (!prefix.empty())
        cout << (leftChild ? "|-- " : "`-- ");
    cout << node->val << "\n";
    if (node->l || node->r)
    {
        if (node->l)
            displayTree(node->l, prefix + (leftChild ? "|   " : "    "), true);
        if (node->r)
            displayTree(node->r, prefix + (leftChild ? "|   " : "    "), false);
    }
}

int tempIndex = 1;
string emitTAC(ASTNode *node)
{
    if (!node->l && !node->r)
        return node->val;
    string leftVar = emitTAC(node->l);
    string rightVar = emitTAC(node->r);
    string tmp = "t" + to_string(tempIndex++);
    cout << tmp << " = " << leftVar << " " << node->val << " " << rightVar << endl;
    return tmp;
}

int opPriority(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

ASTNode *constructAST(const string &expr)
{
    stack<ASTNode *> vals;
    stack<char> ops;
    for (char ch : expr)
    {
        if (ch == ' ')
            continue;
        if (isdigit(ch))
            vals.push(new ASTNode(string(1, ch)));
        else if (ch == '(')
            ops.push(ch);
        else if (ch == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                ASTNode *r = vals.top();
                vals.pop();
                ASTNode *l = vals.top();
                vals.pop();
                char op = ops.top();
                ops.pop();
                ASTNode *n = new ASTNode(string(1, op));
                n->l = l;
                n->r = r;
                vals.push(n);
            }
            ops.pop();
        }
        else
        {
            while (!ops.empty() && opPriority(ops.top()) >= opPriority(ch))
            {
                ASTNode *r = vals.top();
                vals.pop();
                ASTNode *l = vals.top();
                vals.pop();
                char op = ops.top();
                ops.pop();
                ASTNode *n = new ASTNode(string(1, op));
                n->l = l;
                n->r = r;
                vals.push(n);
            }
            ops.push(ch);
        }
    }
    while (!ops.empty())
    {
        ASTNode *r = vals.top();
        vals.pop();
        ASTNode *l = vals.top();
        vals.pop();
        char op = ops.top();
        ops.pop();
        ASTNode *n = new ASTNode(string(1, op));
        n->l = l;
        n->r = r;
        vals.push(n);
    }
    return vals.top();
}

int main()
{
    string input;
    cout << "\n\n23BCT0266\n\nEnter expression: ";
    getline(cin, input);

    ASTNode *root = constructAST(input);
    cout << "\nAbstract Syntax Tree of the expression " << input << "\n";
    displayTree(root);

    cout << "\nThree Address Code\n";
    string lastTemp = emitTAC(root);
    cout << "ans = " << lastTemp << "\n";

    return 0;
}
