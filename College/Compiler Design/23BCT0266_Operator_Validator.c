#include <stdio.h>

int isValidOperator(const char *token)
{
    // List of valid C operators
    const char *validOperatorList[] = {
        "+", "-", "*", "/", "%", "++", "--", "==", "!=", ">", "<", ">=", "<=", "=",
        "+=", "-=", "*=", "/=", "%=", "&", "|", "^", "~", "<<", ">>", "<<=", ">>=",
        "&=", "|=", "^=", "&&", "||", "!", ".", "->", "?", ":", "sizeof", ","};
    int numOperators = sizeof(validOperatorList) / sizeof(validOperatorList[0]);

    for (int i = 0; i < numOperators; i++)
    {
        int j = 0;
        while (token[j] == validOperatorList[i][j])
        {
            if (token[j] == '\0')
                break;
            j++;
        }
        if (token[j] == '\0' && validOperatorList[i][j] == '\0')
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    FILE *file = fopen("test2.txt", "r");
    printf("\n\t\t\t-------23BCT0266-------\n\n\n");
   

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        int i = 0;
        while (line[i] != '\0' && line[i] != '\n')
        {
            char token[100];
            int k = 0;

            while (line[i] == ' ' || line[i] == '\t')
                i++;

            while (line[i] != '\0' && line[i] != '\n' && line[i] != ' ' && line[i] != '\t')
            {
                token[k++] = line[i++];
            }
            token[k] = '\0';

            if (k > 0)
            {
                if (isValidOperator(token))
                {
                    printf("'%s' is a Valid Operator.\n", token);
                }
                else
                {
                    printf("'%s' is not a valid Operator.\n", token);
                }
            }
        }
    }
    return 0;
}
