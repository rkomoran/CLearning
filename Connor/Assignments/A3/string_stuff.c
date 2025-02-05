#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Need to provide a string.\n");
        return EXIT_FAILURE;
    }

   char * string = argv[1];

   printf("Uppercase: ");
   for (int i = 0; string[i] != '\0'; i++)
   {
       if (string[i] >= 'a' && string[i] <= 'z')
       {
           putchar(string[i] - 32);
       }
       else
       {
           putchar(string[i]);
       }
   }
   printf("\n");
    
   printf("Lowecase: ");
   for (int i = 0; string[i] != '\0'; i++)
   {
       if (string[i] >= 'A' && string[i] <= 'Z')
       {
           putchar(string[i] + 32);
       }
       else
       {
           putchar(string[i]);
       }
   }
   printf("\n");

   int chCount = 0;
   char ch;
   printf("Please input a character to count: ");
   if (scanf("%c", &ch) != 1)
   {
       fprintf(stderr, "Input read failed.\n");
       return EXIT_FAILURE;
   }

   for (int i = 0; string[i] != '\0'; i++)
   {
       if (string[i] == ch)
       {
           chCount++;
       }
   }
   printf("Count: %d\n", chCount);

   char delimiter;
   printf("Please input a single character delimiter: ");
    
   // i god damn hate it when this happens
   getchar();
   
   if (scanf("%c", &delimiter) != 1)
   {
       fprintf(stderr, "Input read failed.\n");
       return EXIT_FAILURE;
   }

   char * temp = string;
   while(*temp != '\0')
   {
       if (*temp == delimiter)
       {
           printf("\n");
       }
       else
       {
           putchar(*temp);
       }
       temp++;
   }
   printf("\n");

   printf("Please input a substring to search for: ");
   char * subString = malloc(sizeof(char) * 100);

   if(scanf("%s", subString) != 1)
   {
       fprintf(stderr, "Input read failed.\n");
       return EXIT_FAILURE;
   }

   int found = 0;
      
   for (int i = 0; string[i] != '\0'; i++)
   {
       int j = 0;
       while(subString[j] != '\0' && string[i + j] != '\0' && string[i + j] == subString[j])
       {
           j++;
       }
       if(subString[j] == '\0')
       {
           found = 1;
           break;
       }
   }

   if (found)
   {
       printf("TRUE\n");
   }
   else
   {
       printf("FALSE\n");
   }

   free(subString);
} 
