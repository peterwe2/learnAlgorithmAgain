#include <stdio.h>

int findMax(int* input, int num)
{
    int max = 0;
    int max_index = 0;
    int index = 0;
    for(index = 0; index < num; index++)
    {
        if(max < input[index])
        {
            max = input[index];
            max_index = index;
            // printf("line: %d <%s>\n", __LINE__, __FUNCTION__);
        }
    }
    return max_index;
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

void selectionSort(int* input, int num) /* O(n^2) */
{
    int max_index = 0;
    int index = 0;
    int tail_num = num - 1;
    for(index = 0; index < num; index++)
    {
        max_index = findMax(input, tail_num);
        swap((input + max_index), (input + tail_num)); /* swap from tail */
        tail_num--;
    }
}

void printArray(int *input, int num)
{
    for(int i = 0; i < num; i++)
    {
        printf("%d ", input[i]);
    }
    printf("\n");
}

int main(void)
{
    int array[5] = {6, 2, 9, 3, 8};
    printArray(array, 5);
    selectionSort(array, 5);
    printArray(array, 5);
    return 0;

}