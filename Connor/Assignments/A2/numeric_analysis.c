// this program must use the below function signatures, and cannot use indexes to access array elements
// ***all work must be done with pointer arithmetic***
#include <stdio.h>
#include <stdlib.h>

void printArray(float * array, int size)
{
    float *ptr = array;
    for (int i = 0; i < size; i++)
    {
        printf("%.2f ", *ptr);
        ptr++;
    }
    printf("\n");
}

// type here describes whether the sort will be h -> l (type > 0) or l -> h (type <= 0)
void insertionSort(float * array, int size, int type)
{
    for (int i = 1; i < size; i++)
    {
        float key = *(array + i);
        int j = i - 1;

        if (type > 0)
        {
            while (j >= 0 && *(array + j) < key)
            {
                *(array + j + 1) = *(array + j);
                j--;
            }
        }
        else
        {
            while (j >= 0 && *(array + j) > key)
            {
                *(array + j + 1) = *(array + j);
                j--;
            }
        }

        *(array + j + 1) = key;
    }
}
float median(float * array, int size)
{
    // should not affect original array, let's make a copy
    float *copy = malloc(size * sizeof(float));
    for (int i = 0; i < size; i++)
    {
        *(copy + i) = *(array + i);
    }
    insertionSort(copy, size, 0);

    int middle = (int) size / 2;
    
    float med;
    if (size % 2 == 0)
    {
        med = (*(copy + size / 2 - 1) + *(copy + size / 2)) / 2.0;
    }
    else
    {
        med = *(copy + size / 2);
    }
    free(copy);
    return med;
}
int binarySearch(float * array, int size, float search)
{
    // create copy
    float *copy = malloc(size * sizeof(float));
    for (int i = 0; i < size; i++)
    {
        *(copy + i) = *(array + i);
    }
    insertionSort(copy, size, 0);

    int low = 0, high = size - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (*(copy + mid) == search)
        {
            free(copy);
            return 1;
        }
        if (*(copy + mid) < search)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    free(copy);
    return -1;
}

int match(float * array1, int size1, float * array2, int size2)
{
    int count = 0;
    int j = 0;
    int i = 0;
    
    float *copy = malloc(size1 * sizeof(float));
    for (int i = 0; i < size1; i++)
    {
        *(copy + i) = *(array1 + i);
    }
    insertionSort(copy, size1, 0);

    float *copy2 = malloc(size2 * sizeof(float));
    for (int i = 0; i < size2; i++)
    {
        *(copy2 + i) = *(array2 + i);
    }
    insertionSort(copy2, size2, 0);
    
    while (i < size1 && j < size2)
    {
        if (*(copy + i) == *(copy2 + j))
        {
            i++;
            j++;
            count++;
        }
        else if (*(copy + i) < *(copy2 + j))
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return count;
}

void applyMultiplier(float * array, int size, float multiplier)
{
    for (int i = 0; i < size; i++)
    {
        *(array + i) *= multiplier;
    }
}

int main (int argc, char ** argv)
{
    float arr1[] = {5.5, 2.2, 8.8, 4.4, 7.7};
    float arr2[] = {8.8, 2.2, 3.3, 6.6};

    int size1 = sizeof(arr1)/sizeof(float);
    int size2 = sizeof(arr2)/sizeof(float);

    printf("original arr1: ");
    printArray(arr1, size1);
    insertionSort(arr1, size1, 1);
    printf("sorted arr1 (desc): ");
    printArray(arr1, size1);
    

    printf("original arr2: ");
    printArray(arr2, size2);
    insertionSort(arr2, size2, 1);
    printf("sorted arr2 (desc): ");
    printArray(arr2, size2);

    float med = median(arr1, size1);
    printf("Median of arr1: %.2f\n", med);

    float med2 = median(arr2, size2);
    printf("Median of arr2: %.2f\n", med2);

    int found = binarySearch(arr1, size1, 4.4);
    printf("Binary search for 4.4: %s\n", found == 1 ? "Found." : "Not found.");
    
    int found2 = binarySearch(arr1, size1, 4.5);
    printf("Binary search for 4.5: %s\n", found2 == 1 ? "Found." : "Not found.");
    
    int matches = match(arr1, size1, arr2, size2);
    printf("Matches between arr1 & arr2: %d\n", matches);

    applyMultiplier(arr1, size1, 2.0);
    printf("Arr1 after multiplier (2.0): ");
    printArray(arr1, size1);
}
