#include <stdio.h>
#include <stdlib.h>

char mostCommon(char letters[], int size){
	int count[26] = {0};

	int i;  
    printf("***************\n");
	for (i = 0; i < size; i++){
        count[letters[i] - 97]++;
	}

	int mostCommonLetter = 'a';
	int mostCommonNum = count[0];


	for (i = 1; i < size; i++){
		if(mostCommonNum > count[i]){
			mostCommonLetter = letters[i];
			mostCommonNum = count[i];
		}
	}

	return mostCommonLetter;
}

int main(int argc, char ** argv){
	int count = 0;
	scanf("%d", &count); 

    if (count < 0)
    {
        fprintf(stderr, "Must supply a positive number\n");
        return EXIT_FAILURE;
    }

	char data[count];

	int i = 0;
	while(i < count){
		char readIn = ' ';
		scanf("\n%c", &readIn);
        data[i] = readIn;
		i = i + 1;
	}

	printf("Most Common Letter is: %c\n", mostCommon(data, count));

	return EXIT_SUCCESS;

}
