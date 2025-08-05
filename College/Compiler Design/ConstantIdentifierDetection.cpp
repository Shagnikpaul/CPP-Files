#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool isKeyword(const string &token)
{
    if (
        token == "auto" || token == "break" || token == "case" || token == "char" ||
        token == "const" || token == "continue" || token == "default" || token == "do" ||
        token == "double" || token == "else" || token == "enum" || token == "extern" ||
        token == "float" || token == "for" || token == "goto" || token == "if" ||
        token == "inline" || token == "int" || token == "long" || token == "register" ||
        token == "restrict" || token == "return" || token == "short" || token == "signed" ||
        token == "sizeof" || token == "static" || token == "struct" || token == "switch" ||
        token == "typedef" || token == "union" || token == "unsigned" || token == "void" ||
        token == "volatile" || token == "while" || token == "_Bool" ||
        token == "_Complex" || token == "_Imaginary")
        return true;

    return false;
}

bool isDelimiter(char ch)
{
    return ch == ' ' || ch == ',' || ch == ';' || ch == '(' || ch == ')' ||
           ch == '{' || ch == '}' || ch == '[' || ch == ']' || ch == '\n' || ch == '\t';
}

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '>' || ch == '<';
}

int main()
{

    string s;
    int ignoreLine = 0;
    ifstream file("test.txt");
    int i = 0;
    while (getline(file, s))
    {

        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '/' && s[j + 1] == '/')
            {
                // ignore the line
                // cout << "ignored line " << (i + 1) << endl;
                break;
            }

            if (s[j] == '/' && s[j + 1] == '*')
            {
                ignoreLine = 1;
                // cout << "started ignoring from line " << (i + 1) << endl;
            }

            if (s[j] == '*' && s[j + 1] == '/')
            {
                ignoreLine = 0;
                j += 2;
                // cout << "stopped ignoring from line " << (i + 1) << endl;
            }

            if (ignoreLine)
                continue;
            else
            {
                // scan ...
                if (s[j] != '\n' && s[j] != ' ')

                {
                    string token = "";
                    if (isalpha(s[j]))
                    {
                        token = "";
                        while (j < s.length() && (isalnum(s[j]) || s[j] == '_'))
                        {
                            token += s[j];
                            j++;
                        }

                        if (isKeyword(token))
                        {
                            cout << token << " is not a valid identifier since it is a keyword" << endl;
                        }
                        else
                        {
                            cout << token << " is a valid identifier" << endl;
                        }
                    }
                    else if (isdigit(s[j]))
                    {
                        token = "";
                        int dotCount = 0;
                        while (j < s.length() && (isdigit(s[j]) || s[j] == '.'))
                        {
                            if (s[j] == '.')
                            {
                                dotCount++;
                            }
                            token += s[j];
                            j++;
                        }
                        if (dotCount <= 1)
                        {
                            cout << token << " is a valid constant " << endl;
                        }
                        else
                        {
                            cout << token << " is a invalid constant " << endl;
                        }
                        // cout << "Number: " << token << endl;
                    }

                    if (j + 1 < s.length())
                    {
                        string twoCharOp = "";
                        twoCharOp += s[j];
                        twoCharOp += s[j + 1];

                        // Check for 2-character operators
                        if (twoCharOp == "==" || twoCharOp == "!=" || twoCharOp == "<=" ||
                            twoCharOp == ">=" || twoCharOp == "&&" || twoCharOp == "||" ||
                            twoCharOp == "++" || twoCharOp == "--" || twoCharOp == "+=" ||
                            twoCharOp == "-=" || twoCharOp == "*=" || twoCharOp == "/=")
                        {
                            // cout << "Operator: " << twoCharOp << endl;

                            j += 2;
                            continue;
                        }
                    }

                    // If it's a single-character operator
                    if (isOperator(s[j]))
                    {

                        // cout << "Operator: " << s[j] << endl;
                    }

                    // If delimiter
                    else if (isDelimiter(s[j]))
                    {
                        if (s[j] != ' ' && s[j] != '\n' && s[j] != '\t')
                        {

                            // cout << "Delimiter: " << s[j] << endl;
                        }
                    }
                }
            }
        }
        // cout << "Line " << i + 1 << ": " << s << endl;
        i++;
    }
}
