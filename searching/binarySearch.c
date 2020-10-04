#include <stdio.h>

void printArray(int* input, int num)
{
    int i = 0;
    for(i = 0; i < num; i++)
    {
        printf("%d ", input[i]);
    }
    printf("\n");
    return;
}

int binarySearch(int* input, int num, int target)
{
    int head = 0;
    int tail = num - 1;
    int mid = ((unsigned)(head + tail)) >> 1; /* prevent overflow */

    while(input[mid] != target)
    {
        if(head >= tail)
        {
            printf("not in this array!\n");
            return -1;
        }
        if(input[mid] < target)
        {
            head = mid + 1;
        }
        else
        {
            tail = mid - 1;
        }
        mid = ((unsigned)(head + tail)) >> 1;

    }
    return mid;
}

int main(void)
{
    int input[9] = {2, 4, 5, 8, 9, 13, 17, 55, 109};
    int target_index = 0;

    printArray(input, 9);
    target_index = binarySearch(input, 9, 13);
    printf("target_index: %d\n", target_index);

    return 0;
}


