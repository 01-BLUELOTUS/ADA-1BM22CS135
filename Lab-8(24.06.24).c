#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n/2-1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main() {
    clock_t start,end;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    srand(time(NULL));
    for (int i = 0; i < n; ++i)
        arr[i] = rand() % 100;

    start=clock();
    heapSort(arr, n);
    end=clock();

        if(n<=50)
    {
        printf("Heap Sorted array:\n");
        for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
        printf("\n");
    }

    printf("\nTime taken: %fs\n",((double)(end-start))/CLOCKS_PER_SEC);
}
