#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Merge(int a[], int low, int mid, int high) {
    int i, j, k;
    int b[100];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }
    for (; i <= mid; i++) {
        b[k++] = a[i];
    }
    for (; j <= high; j++) {
        b[k++] = a[j];
    }
    for (i = low; i <= high; i++) {
        a[i] = b[i];
    }
}

void mergeSort(int a[], int low, int high){
    if(low<high){
        int mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        Merge(a,low,mid,high);
    }

}

int main() {
    int a[20], i, n;
    clock_t start, end;

    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    start = clock();
    mergeSort(a, 0,n-1);
    end = clock();

    printf("Array elements after sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by merge sort: %0.3f milliseconds", time_taken);

    return 0;
}
