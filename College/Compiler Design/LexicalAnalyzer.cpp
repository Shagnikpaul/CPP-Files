#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool isKeyword(const string &token)
{
    if (token == "int" || token == "if" || token == "else" ||
        token == "endif" || token == "print" || token == "then")
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
    vector<pair<string, int>> keywords;

    vector<pair<string, int>> identifiers;

    vector<pair<string, int>> numbers;

    vector<pair<char, int>> delimiters;

    vector<pair<string, int>> operators;
    vector<pair<char, int>> singleOperators;

    string s;
    int ignoreLine = 0;
    ifstream file("code.txt");
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
                            //cout << "Keyword: " << token << " at line no. " << (i + 1) << endl;
                            keywords.push_back({token, i + 1});
                        }

                        else
                        {
                            //cout << "Identifier: " << token << " at line no. " << (i + 1) << endl;
                            identifiers.push_back({token, i + 1});
                        }
                    }
                    else if (isdigit(s[j]))
                    {
                        token = "";
                        while (j < s.length() && isdigit(s[j]))
                        {
                            token += s[j];
                            j++;
                        }
                        numbers.push_back({token, i + 1});
                        //cout << "Number: " << token << endl;
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
                            //cout << "Operator: " << twoCharOp << endl;
                            operators.push_back({twoCharOp, i + 1});
                            j += 2;
                            continue;
                        }
                    }

                    // If it's a single-character operator
                    if (isOperator(s[j]))
                    {
                        singleOperators.push_back({s[j], i + 1});
                        //cout << "Operator: " << s[j] << endl;
                    }

                    // If delimiter
                    else if (isDelimiter(s[j]))
                    {
                        if (s[j] != ' ' && s[j] != '\n' && s[j] != '\t')
                        {
                            delimiters.push_back({s[j], i + 1});
                            //cout << "Delimiter: " << s[j] << endl;
                        }
                    }
                }
            }
        }
        // cout << "Line " << i + 1 << ": " << s << endl;
        i++;
    }

    cout << "\n\nKeyword list : " << endl;
    for (const auto &k : keywords)
    {
        cout << k.first << ", Line: " << k.second << endl;
    }

    cout << "\n\nIdentifiers list : " << endl;
    for (const auto &k : identifiers)
    {
        cout << k.first << ", Line: " << k.second << endl;
    }

    cout << "\n\nOperators list : " << endl;
    for (const auto &k : operators)
    {
        cout << k.first << ", Line: " << k.second << endl;
    }

    for (const auto &k : singleOperators)
    {
        cout << k.first << ", Line: " << k.second << endl;
    }

    cout << "\n\n Delimiters list : " << endl;
    for (const auto &k : delimiters)
    {
        cout << k.first << ", Line: " << k.second << endl;
    }

    cout << "\n\nNumbers list : " << endl;
    for (const auto &k : numbers)
    {
        cout << k.first << " Line: " << k.second << endl;
    }
}
