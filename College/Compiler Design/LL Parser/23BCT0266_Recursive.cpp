/*
    23BCT0266

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class RecursiveDescentParser
{
private:
    string input;
    int position;
    int parseLevel;

    void printIndent()
    {
        for (int i = 0; i < parseLevel; i++)
            cout << "  ";
    }

    void enterRule(const string &rule)
    {
        printIndent();
        cout << "Entering " << rule << " at position " << position;
        if (position < input.length())
            cout << " (current char: '" << input[position] << "')";
        cout << endl;
        parseLevel++;
    }

    void exitRule(const string &rule, bool success)
    {
        parseLevel--;
        printIndent();
        cout << "Exiting " << rule << " - " << (success ? "SUCCESS" : "FAILED") << endl;
    }

    bool match(char expected)
    {
        if (position < input.length() && input[position] == expected)
        {
            printIndent();
            cout << "Matched '" << expected << "' at position " << position << endl;
            position++;
            return true;
        }
        return false;
    }

public:
    RecursiveDescentParser(const string &str) : input(str), position(0), parseLevel(0) {}

    bool parseQ()
    {
        enterRule("Q");
        int startPos = position;
        if (parseA() && match('b') && parseQ_prime())
        {
            exitRule("Q", true);
            return true;
        }
        position = startPos;
        if (parseA() && parseB() && parseQ_prime())
        {
            exitRule("Q", true);
            return true;
        }
        position = startPos;
        exitRule("Q", false);
        return false;
    }

    bool parseQ_prime()
    {
        enterRule("Q'");
        int startPos = position;
        if (parseA() && parseB() && parseQ_prime())
        {
            exitRule("Q'", true);
            return true;
        }
        position = startPos;
        exitRule("Q'", true);
        return true;
    }

    bool parseA()
    {
        enterRule("A");
        int startPos = position;
        if (parseB() && parseA_prime())
        {
            exitRule("A", true);
            return true;
        }
        position = startPos;
        exitRule("A", false);
        return false;
    }

    bool parseA_prime()
    {
        enterRule("A'");
        int startPos = position;
        if (match('b') && parseA_prime())
        {
            exitRule("A'", true);
            return true;
        }
        position = startPos;
        exitRule("A'", true);
        return true;
    }

    bool parseB()
    {
        enterRule("B");
        int startPos = position;
        if (match('a') && match('b'))
        {
            exitRule("B", true);
            return true;
        }
        position = startPos;
        exitRule("B", false);
        return false;
    }

    bool parse()
    {
        cout << "Starting parse of string: \"" << input << "\"" << endl;
        cout << "===============================================" << endl;
        bool result = parseQ();
        cout << "===============================================" << endl;
        if (result && position == input.length())
        {
            cout << "Parse SUCCESSFUL! Entire string consumed." << endl;
            return true;
        }
        else if (result)
        {
            cout << "Parse FAILED! String partially consumed. Remaining: \""
                 << input.substr(position) << "\"" << endl;
            return false;
        }
        else
        {
            cout << "Parse FAILED! Could not parse string." << endl;
            return false;
        }
    }

    void reset(const string &str)
    {
        input = str;
        position = 0;
        parseLevel = 0;
    }
};

int main()
{
    cout << "=================\n23BCT0266\n=================\n";
    string input;
    char choice;
    do
    {
        cout << "Enter a string to parse: ";
        cin >> input;
        RecursiveDescentParser parser(input);
        parser.parse();
        cout << endl;
        cout << "Do you want to parse another string? (y/n): ";
        cin >> choice;
        cout << endl;
    } while (choice == 'y' || choice == 'Y');
    cout << "Program Exited." << endl;
    return 0;
}
