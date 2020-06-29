#include <stdio.h>
#include <stdlib.h>


void main()
{
    //Variables
    char letter;
    char *randWord;
    int guesses = 5;

    //Words
    char words [5][8] =
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
    int randVal = rand()%(sizeof(words)-1 + 1) + 1;
    randWord = words[randVal];

    printf("%s %d\n", randWord, randVal);

    /*for (int i = 5; i>=1; i--)
    {
        printf("You have %d guesses left\n", i);

        printf("Pick a letter:");
        letter = getchar();

        printf("You entered: ");
        putchar(letter);
    }*/

    while ((letter = getchar()) != EOF && guesses > 0)
    {
        if (letter != 0x0Ad)
        {
            printf("%d guesses left\n", guesses);
            printf("You entered: %c\n", letter);
            guesses--;
        }
        letter = fgetc(stdin);

    }
    printf("No guesses left, you lost");

}
