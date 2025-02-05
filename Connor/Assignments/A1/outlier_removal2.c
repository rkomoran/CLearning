#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float sum(float *array, int size)
{
    float total = 0;
    for (int i = 0; i < size; i++)
    {
        total += array[i];
    }
    return total;
}

float calculate_mean(float sum, int size)
{
    return sum / size;
}

float calculate_deviation(float *array, int size, float mean)
{
    float values = 0;
    for (int i = 0; i < size; i++)
    {
        values += pow(array[i] - mean, 2);
    }
    
    float variance = values / size;
    float standardDeviation = sqrt(variance);
    return standardDeviation;
}

void print_outliers(float *array, int size, float mean, float deviation)
{
    // Correct bounds calculation
    float upperb = mean + 2 * deviation;
    float lowerb = mean - 2 * deviation;

    printf("upperb: %f\nlowerb: %f\n", upperb, lowerb);
    
    printf("\nOutliers:\n");
    for (int i = 0; i < size; i++)
    {
       // Outliers should be outside the bounds
       if (array[i] < lowerb || array[i] > upperb)
       {
           printf("%f ", array[i]);
       }
    }
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <size>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int size = strtol(argv[1], NULL, 10);
    if (size <= 0)
    {
        fprintf(stderr, "Number must be greater than 0\n");
        return EXIT_FAILURE;
    }

    float *array = (float *)malloc(size * sizeof(float));
    if (array == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    float nums = 0;
    int i = 0;

    while (i < size)
    {
        if (scanf("%f", &nums) == 1)
        {
            array[i] = nums; 
            i++;
        }
        else
        {
            fprintf(stderr, "Issue reading in the number\n");
            free(array);
            return EXIT_FAILURE;
        }
    }

    float total_sum = sum(array, size);
    printf("Total sum: %f\n", total_sum);

    float mean = calculate_mean(total_sum, size);
    printf("Mean: %f\n", mean);

    float standardDeviation = calculate_deviation(array, size, mean);
    printf("Standard deviation: %f\n", standardDeviation);
    
    print_outliers(array, size, mean, standardDeviation);

    // Freeing memory
    free(array);
    return EXIT_SUCCESS;
}

