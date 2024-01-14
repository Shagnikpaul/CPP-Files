#include <stdio.h>
#include <string.h>
int main() {
    int numAtThousands = 9;
    int numAtHundreds = 1;
    int numAtTens = 5;
    int numAtDigits = 9; 

    char* wordThousands;

    switch (numAtThousands) {
        case 0:
            wordThousands = "";
            break;
        case 1:
            wordThousands = "one thousand";
            break;
        case 2:
            wordThousands = "two thousand";
            break;
        case 3:
            wordThousands = "three thousand";
            break;
        case 4:
            wordThousands = "four thousand";
            break;
        case 5:
            wordThousands = "five thousand";
            break;
        case 6:
            wordThousands = "six thousand";
            break;
        case 7:
            wordThousands = "seven thousand";
            break;
        case 8:
            wordThousands = "eight thousand";
            break;
        case 9:
            wordThousands = "nine thousand";
            break;
        default:
            wordThousands = "Invalid input";
    }

    char* wordHundreds;

    switch (numAtHundreds) {
        case 0:
            wordHundreds = "";
            break;
        case 1:
            wordHundreds = "one hundred";
            break;
        case 2:
            wordHundreds = "two hundred";
            break;
        case 3:
            wordHundreds = "three hundred";
            break;
        case 4:
            wordHundreds = "four hundred";
            break;
        case 5:
            wordHundreds = "five hundred";
            break;
        case 6:
            wordHundreds = "six hundred";
            break;
        case 7:
            wordHundreds = "seven hundred";
            break;
        case 8:
            wordHundreds = "eight hundred";
            break;
        case 9:
            wordHundreds = "nine hundred";
            break;
        default:
            wordHundreds = "Invalid input";
    }

    char* wordTens;


    switch (numAtTens) {
        case 0:
            wordTens = "";
            break;
        case 1:
            wordTens = "";
            switch (numAtDigits)
            {
            case 1:
                wordTens = "eleven";
                break;
            case 2:
                wordTens = "twelve";
                break;    
            case 3:
                wordTens = "thirteen";
                break;
            case 4:
                wordTens = "fourteen";
                break;
            case 5:
                wordTens = "fifteen";
                break;
            case 6:
                wordTens = "sixteen";
                break;
            case 7:
                wordTens = "seventeen";
                break;
            case 8:
                wordTens = "eighteen";
                break;
            case 9:
                wordTens = "nineteen";
                break;
            default:
                break;
            }
            break;
        case 2:
            wordTens = "twenty";
            break;
        case 3:
            wordTens = "thirty";
            break;
        case 4:
            wordTens = "fourty";
            break;
        case 5:
            wordTens = "fifty";
            break;
        case 6:
            wordTens = "sixty";
            break;
        case 7:
            wordTens = "seventy";
            break;
        case 8:
            wordTens = "eighty";
            break;
        case 9:
            wordTens = "ninety";
            break;
        default:
            wordTens = "Invalid input";
    }
    char* wordDigits;
    if(numAtTens != 1)
    {
        

    switch (numAtDigits) {
        case 0:
            wordDigits = "";
            break;
        case 1:
            wordDigits = "one";
            break;
        case 2:
            wordDigits = "two";
            break;
        case 3:
            wordDigits = "three";
            break;
        case 4:
            wordDigits = "four";
            break;
        case 5:
            wordDigits = "five";
            break;
        case 6:
            wordDigits = "six";
            break;
        case 7:
            wordDigits = "seven";
            break;
        case 8:
            wordDigits = "eight";
            break;
        case 9:
            wordDigits = "nine";
            break;
        default:
            wordDigits = "Invalid input";
    }}
    else{
        wordDigits = "";
    }

printf("%s %s %s %s",wordThousands,wordHundreds,wordTens,wordDigits);

    

    return 0;

}