#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;  
    int j = high;

    while (i <= j) 
    {
        while (i <= high && arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);  
    return j;
}

void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() 
{
    clock_t start, end;
    int n;
    printf("Enter the number of array elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));  
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    
    srand(time(NULL));  
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;

    start = clock(); 
    quickSort(arr, 0, n - 1);
    end = clock();   

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    if(n<=50)
    {
        printf("Sorted array:\n");
        for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
        printf("\n");
    }

    printf("Time taken: %f seconds\n", time_taken);

    free(arr);  
    return 0;
}
