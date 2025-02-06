#include <stdio.h>
#include <stdlib.h>

// randomly select a 5-letter word from a word doc.
// store it as the "secret" word

#define MAXLEN 6
#define MAXWORDS 100


//TODO implement rand to select secret word. incorportate file output. make a Makefile
void read_words(char * filepointer, char ** buffer, int * words);
int main(int argc, char ** argv)
{
    
    char ** buffer = malloc(sizeof(char *) * MAXLEN);
    for (int i = 0; i < MAXLEN; i++)
    {
        *(buffer + i) = malloc(sizeof(char) * MAXWORDS);
    }
    int words = 0;

    read_words(argv[1], buffer, &words);
    if (words < 2)
    {
        fprintf(stderr, "Must be >2 words");
        EXIT_FAILURE;
    }
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
