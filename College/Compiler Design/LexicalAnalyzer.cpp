#include <iostream>
#include <fstream>
#include <string>


using namespace std;

bool isKeyword(const string &token)
{
    return (
        token == "auto" || token == "break" || token == "case" || token == "char" ||
        token == "const" || token == "continue" || token == "default" || token == "do" ||
        token == "double" || token == "else" || token == "enum" || token == "extern" ||
        token == "float" || token == "for" || token == "goto" || token == "if" ||
        token == "inline" || token == "int" || token == "long" || token == "register" ||
        token == "restrict" || token == "return" || token == "short" || token == "signed" ||
        token == "sizeof" || token == "static" || token == "struct" || token == "switch" ||
        token == "typedef" || token == "union" || token == "unsigned" || token == "void" ||
        token == "volatile" || token == "while" || token == "_Bool" ||
        token == "_Complex" || token == "_Imaginary");
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
    ifstream file("test.txt");
    if (!file.is_open())
    {
        cout << "Error opening file.\n";
        return 1;
    }

    string s;
    int ignoreLine = 0;
    int lineNumber = 0;

    while (getline(file, s))
    {

        for (int j = 0; j < (int)s.size(); j++)
        {
            if (j + 1 < (int)s.size() && s[j] == '/' && s[j + 1] == '/')
                break; // single-line comment, ignore rest

            if (j + 1 < (int)s.size() && s[j] == '/' && s[j + 1] == '*')
            {
                ignoreLine = 1;
                j += 2;
            }

            if (j + 1 < (int)s.size() && s[j] == '*' && s[j + 1] == '/')
            {
                ignoreLine = 0;
                j += 2;
                continue;
            }

            if (ignoreLine)
                continue;

            // ---- TOKEN DETECTION ----
            if (!isDelimiter(s[j]) && s[j] != ' ')
            {
                string token = "";

                // Identifier or keyword
                if (isalpha(s[j]))
                {
                    while (j < (int)s.length() && (isalnum(s[j]) || s[j] == '_'))
                    {
                        token += s[j];
                        j++;
                    }
                    j--;

                    if (isKeyword(token))
                        cout << token << " -> Keyword" << endl;
                    else
                        cout << token << " -> Identifier" << endl;
                }

                // Number
                else if (isdigit(s[j]))
                {
                    while (j < (int)s.length() && isdigit(s[j]))
                    {
                        token += s[j];
                        j++;
                    }
                    j--;
                    cout << token << " -> Number" << endl;
                }

                // Two-character operators
                else if (j + 1 < (int)s.length())
                {
                    string twoCharOp = "";
                    twoCharOp += s[j];
                    twoCharOp += s[j + 1];

                    if (twoCharOp == "==" || twoCharOp == "!=" || twoCharOp == "<=" ||
                        twoCharOp == ">=" || twoCharOp == "&&" || twoCharOp == "||" ||
                        twoCharOp == "++" || twoCharOp == "--" || twoCharOp == "+=" ||
                        twoCharOp == "-=" || twoCharOp == "*=" || twoCharOp == "/=")
                    {
                        cout << twoCharOp << " -> Operator" << endl;
                        j++;
                        continue;
                    }
                }

                // Single-character operator
                if (isOperator(s[j]))
                {
                    cout << s[j] << " -> Operator" << endl;
                }

                // Delimiter
                else if (isDelimiter(s[j]))
                {
                    if (s[j] != ' ' && s[j] != '\n' && s[j] != '\t')
                        cout << s[j] << " -> Delimiter" << endl;
                }
            }
        }
    }

    file.close();
    return 0;
}
