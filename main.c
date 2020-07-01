#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //Variables
    const char *randWord;
    int guesses = 5;
    char *found;
    int numCorrect = 0;
    int oldCorrect = 0;
    int reguessed;


    //Words
    char words [][10] =
    {
        "chair",
        "table",
        "cheese",
        "computer",
        "test",
        "desk",
        "screen",
        "phone"
    };

    //Pick a random word
    int randVal = rand()%(7-1 + 1) + 1;
    randWord = words[randVal];
    printf("%s %d\n", randWord, randVal); //Show word for testing purposes

    //get word length
    char str[8];
    strcpy(str, randWord);
    int lengthWord = strlen(str);

    //store letters guesses
    char letterEntered;
    int letterGuessed[8] = { 0,0,0,0,0,0,0,0 };


    //Let user guess a letter
    while ((letterEntered = getchar()) != EOF && guesses > 0)
    {
        printf("hangman word: ");
        for (int i = 0; i < lengthWord; i++)
        {
            if (letterGuessed[i] == 1)
            {
                printf("%c",words[randVal][i]);
            }
            else
            {
                printf("_ ");
            }
        } printf("\n");


        if (letterEntered != 0x0Ad) //ENTER key
        {
            found = strchr(randWord, letterEntered);

            if (found)
            {

                printf("Found %c in word %s\n", letterEntered, randWord);
            }
            else
            {
                printf("Letter not found in word\n");
                guesses--;
            }
        }
        letterEntered = fgetc(stdin);
        printf("%d guesses left\n", guesses);

    }
    printf("No guesses left, you lost\n");
    printf("The word was: %s", randWord);
}
