#include <stdio.h>
#include <cstring>

int isLetter(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int isKeyword(const char *token)
{
    const char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "inline", "int", "long", "register", "restrict", "return", "short", "signed",
        "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void",
        "volatile", "while", "_Bool", "_Complex", "_Imaginary"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < numKeywords; i++)
    {
        if (strcmp(token, keywords[i]) == 0)
            return 1;
    }
    return 0;
}
int isDigit(char c)
{
    return (c >= '0' && c <= '9');
}

int isUnderscore(char c)
{
    return (c == '_');
}

int isValidIdentifier(char *token)
{
    if (!(isLetter(token[0]) || isUnderscore(token[0])))
        return 0;

    for (int i = 1; token[i] != '\0'; i++)
    {
        if (!(isLetter(token[i]) || isDigit(token[i]) || isUnderscore(token[i])))
            return 0;
    }
    return 1;
}

int isValidConstant(char *token)
{
    int i = 0;
    while (token[i] != '\0')
    {
        if (!isDigit(token[i]))
            return 0;
        i++;
    }
    return (i > 0);
}

int main()
{
    FILE *file = fopen("test.txt", "r");
    char line[256];
    int validLength = 20;
    while (fgets(line, sizeof(line), file))
    {
        int i = 0;

        while (line[i] != '\0' && line[i] != '\n')
        {
            char token[100];
            int k = 0;

            while (line[i] == ' ' || line[i] == ';' || line[i] == '=' || line[i] == ',' || line[i] == '(' || line[i] == ')' || line[i] == '+' || line[i] == '-')
            {
                i++;
            }

            while (line[i] != '\0' && line[i] != '\n' &&
                   line[i] != ' ' && line[i] != ';' && line[i] != '=' && line[i] != ',' &&
                   line[i] != '(' && line[i] != ')' && line[i] != '+' && line[i] != '-')
            {
                token[k++] = line[i++];
            }
            token[k] = '\0';

            if (k > 0)
            {
                if (isValidIdentifier(token))
                {
                    if (strlen(token) <= validLength)
                    {
                        if (!isKeyword(token))
                            printf("'%s' is a valid identifier.\n", token);
                        else
                            printf("'%s' is not a valid identifier since its a C keyword.\n", token);
                    }
                    else
                    {
                        printf("'%s' is not a valid identifier since exceeds valid max of length %d.\n", token, validLength);
                    }
                }
                else if (isValidConstant(token))
                {
                    if (strlen(token) <= validLength)
                    printf("'%s' is a valid constant.\n", token);
                    else {
                        printf("'%s' is not a valid constant since exceeds valid max of length %d.\n", token, validLength);
                    }
                }
                else
                {
                    printf("'%s' is niether a valid constant nor a valid identifier.\n", token);
                }
            }
        }
    }

    return 0;
}
