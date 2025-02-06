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
int main(int argc, char ** argv)
{
    if(argc != 2)
    {
        fprintf(stderr, "Please provide a word file, and output file.\n");
        return EXIT_FAILURE;
    }
    
    srand(time(NULL));

    char ** buffer = malloc(sizeof(char *) * MAXLEN);
    int words = 0;
    for (int i = 0; i < MAXLEN; i++)
    {
        *(buffer + i) = malloc(sizeof(char) * MAXWORDS);
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

void print_words(char * file);

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
