#include "testLibrary.h"

void testBothFunctions(char *sentence);

static void
removeDoubleWhiteSpaces_(const char *pwInputString, char *outputString);

static void
invertSentenceOrder_(const char *pwInputString, char *outputString);

static int
splitSentence_(const char *pwInputString, char (*outputMatrix)[MAX_SIZE_OF_STRING + 1]);



int main()
{
    testBothFunctions("a   ");
    testBothFunctions("      ");
    testBothFunctions("a  b c");
    testBothFunctions("1 2 3 4 5 6 7 8 9 10");
    testBothFunctions("essa    frase tem   muitos espaços    vazios");

    return 0;
}

/*-----------------------------------------------------------*/
static void
removeDoubleWhiteSpaces_(const char *pwInputString, char *outputString)
{
    int spaceCounter = 0;
    int indexWord = 0;

    char word[MAX_SIZE_OF_STRING + 1];

    for (int index = 0; pwInputString[index] != '\0'; index++)
    {
        if (' ' == pwInputString[index])
        {
            spaceCounter++;
        }
        else
        {
            spaceCounter = 0;
        }
        if (spaceCounter < 2)
        {
            word[indexWord] = pwInputString[index];
            indexWord++;
        }
    }

    word[indexWord] = '\0';
    strcpy(outputString, word);
}

/*-----------------------------------------------------------*/
static void
invertSentenceOrder_(const char *pwInputString, char *outputString)
{
    int wordCount = 0;
    int pwInputStringIndex = -1;

    char wordList[MAX_SIZE_OF_STRING + 1][MAX_SIZE_OF_STRING + 1];

    wordCount = splitSentence_(pwInputString, wordList);

    if (wordCount == 0)
    {
        strcpy(outputString, pwInputString);
        return;
    }

    for (int line = (wordCount - 1); line >= 0; line--)
    {
        for (int column = 0; wordList[line][column] != '\0'; column++)
        {
            pwInputStringIndex++;
            outputString[pwInputStringIndex] = wordList[line][column];
        }
        pwInputStringIndex++;
        if (line > 0)
        {
            outputString[pwInputStringIndex] = ' ';
        }
    }
}

/*-----------------------------------------------------------*/
static int
splitSentence_(const char *pwInputString, char (*outputMatrix)[MAX_SIZE_OF_STRING + 1])
{
    int wordCount = 0;
    bool notAWord = false;

    char word[MAX_SIZE_OF_STRING + 1];

    for (int index = 0;; index++)
    {
        for (int i = 0;; i++)
        {
            if (' ' == pwInputString[index] || '\0' == pwInputString[index])
            {
                word[i] = '\0';
                if (0 == i)
                {
                    notAWord = true;
                }
                break;
            }

            word[i] = pwInputString[index];
            index++;
        }

        if (notAWord)
        {
            break;
        }

        strcpy(outputMatrix[wordCount], word);
        wordCount++;

        if ('\0' == pwInputString[index])
        {
            break;
        }
    }

    return wordCount;
}

/*-----------------------------------------------------------*/
void testBothFunctions(char *sentence)
{
    char pwInputString[MAX_SIZE_OF_STRING + 1];
    char outputString[MAX_SIZE_OF_STRING + 1];
    char outputStringInverted[MAX_SIZE_OF_STRING + 1];

    strcpy(pwInputString, sentence);

    removeDoubleWhiteSpaces_(pwInputString, outputString);
    invertSentenceOrder_(outputString, outputStringInverted);

    printf("%s\n", outputStringInverted);

    /*
    memset(pwInputString, 0x00, sizeof(pwInputString));
    memset(outputString, 0x00, sizeof(outputString));
    memset(outputStringInverted, 0x00, sizeof(outputStringInverted));
    */
}
