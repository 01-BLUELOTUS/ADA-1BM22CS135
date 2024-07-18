#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int profit, weight;
} item;

int compare(const void* a, const void* b) {
    item* itemA = (item*)a;
    item* itemB = (item*)b;
    double ratioA = (double)itemA->profit / itemA->weight;
    double ratioB = (double)itemB->profit / itemB->weight;
    if (ratioA > ratioB)
        return -1;
    else if (ratioA < ratioB)
        return 1;
    else
        return 0;
}

double F_Knapsack(int W, item arr[], int N) {
    qsort(arr, N, sizeof(item), compare);
    double finalvalue = 0.0;
    for (int i = 0; i < N; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalvalue += arr[i].profit;
            printf("Added object %d (%d, %d) completely in the bag. Space left: %d.\n",
                   i + 1, arr[i].weight, arr[i].profit, W);
        } else {
            finalvalue += arr[i].profit * ((double)W / arr[i].weight);
            printf("Added %d%% (%d, %d) of object %d in the bag.\n",
                   (int)(((double)W / arr[i].weight) * 100), arr[i].weight, arr[i].profit, i + 1);
            break;
        }
    }
    return finalvalue;
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    item arr[n];
    printf("Enter profits and weights for each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d, ", &arr[i].profit, &arr[i].weight);
    }
    int W;
    printf("Enter the maximum weight of the knapsack: ");
    scanf("%d", &W);
    printf("Maximum value in the knapsack: %.2f\n", F_Knapsack(W, arr, n));
    return 0;
}
