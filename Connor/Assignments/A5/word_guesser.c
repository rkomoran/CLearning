#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// randomly select a 5-letter word from a word doc.
// store it as the "secret" word

#define MAXLEN 6
#define MAXWORDS 100

//TODO create game loop, incorporate game logic. incorportate file output. make a Makefile
void read_words(char * filepointer, char ** buffer, int * words);
void hint_generator(char * secret, char * guess, char * feedback);
void write_file(FILE *file, int attempt, char * guess);

int main(int argc, char ** argv)
{
    if(argc != 3)
    {
        fprintf(stderr, "Please provide a word file, and output file.\n");
        return EXIT_FAILURE;
    }
    
    srand(time(NULL));

    char ** buffer = malloc(sizeof(char *) * MAXWORDS);
    int words = 0;
    for (int i = 0; i < MAXLEN; i++)
    {
        *(buffer + i) = malloc(sizeof(char) * MAXLEN);
    }

    read_words(argv[1], buffer, &words);
    if (words < 2)
    {
        fprintf(stderr, "Must be >2 words");
        EXIT_FAILURE;
    }

    char * secret_word = malloc(sizeof(char) * MAXLEN);
    strcpy(secret_word, buffer[rand() % words]);
    printf("Secret word: %s\n", secret_word);
        
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
       perror("Error opening word file");
       exit(1);
    }
    
    char * guess = malloc(sizeof(char) * MAXLEN);
    char * feedback = malloc(sizeof(char) * MAXLEN);
    int attempt = 1;

    printf("Guess the %d-letter word!\n", MAXLEN - 1);
    
    while(1)
    {
        printf("Enter a guess:\n");
        fgets(guess, MAXLEN, stdin);
        guess[strcspn(guess, "\n")] = '\0'; // Remove newline if present

        // Flush buffer if input was too long
        int c;
        while ((c = getchar()) != '\n' && c != EOF); 
        
        if (strlen(guess) != MAXLEN - 1)
        {
            printf("Please enter exactly 5 letters.\n");
            continue;
        }

        hint_generator(secret_word, guess, feedback);
        printf("%s\n", feedback);
        write_file(output, attempt, guess);        

        if (strcmp(feedback, "*****") == 0)
        {
            printf("Congratulations! You got it!\n");
            break;
        }
        attempt++;
    }

    fclose(output);
    return EXIT_SUCCESS;
}

void read_words(char * file, char ** buffer, int * words)
{
    FILE * fptr = fopen(file, "r");

    if(fptr == NULL)
    {
        perror("Error opening world file");
        exit(1);
    }

    while(*words < MAXWORDS && fscanf(fptr, "%5s\n", buffer[*words]) == 1)
    {
        printf("%s\n", buffer[*words]);
        (*words)++;
    }

    fclose(fptr);
}

void hint_generator(char * secret, char * guess, char * feedback)
{
    for (int i = 0; i < MAXLEN - 1; i++)
    {
        if (*(guess + i) == *(secret + i))
        {
            *(feedback + i) = '*';
        }
        else if (*(guess + i) < *(secret + i))
        {
            *(feedback + i) = '+';
        }
        else
        {
            *(feedback + i) = '-';
        }
    }

    *(feedback + MAXLEN - 1) = '\0';
}

void eraseMemory(char ** arr, int row)
{
    for (int i = 0; i < row; i++)
    {
        free(*(arr + i));
    }
    free(arr);
}

void printArray(char ** arr, int row)
{
    printf("Printing array..\n");
    for (int i = 0; i < row; i++)
    {
        printf("%s\n", *(arr + i));
    }
}

void write_file(FILE *file, int attempt, char * guess)
{
    fprintf(file, "%d: %s\n", attempt, guess);
}
