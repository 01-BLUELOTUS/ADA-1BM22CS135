#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Merge(int a[], int low, int mid, int high, int n) {
    int i, j, k;
    int b[n];
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

void mergeSort(int a[], int low, int high, int n){
    if(low<high){
        int mid=(low+high)/2;
        mergeSort(a,low,mid,n);
        mergeSort(a,mid+1,high,n);
        Merge(a,low,mid,high,n);
    }

}

int main() {
    int i, n;
    clock_t start, end;

    printf("Enter the size of the array:");
    scanf("%d", &n);
    int a[n];
    srand(time(NULL));
    for (int i=0;i<n;i++)
        a[i]=rand()%100;
    start=clock();
    mergeSort(a, 0,n-1, n);
    end = clock();

    if(n<=50)
    {
        printf("Sorted array:\n");
        for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
        printf("\n");
    }

    printf("\nTime taken:%f",((double)(end - start)) / CLOCKS_PER_SEC);

    return 0;
}
