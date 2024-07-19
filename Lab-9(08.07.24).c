#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void main() {
    int n, w;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the Weight Capacity: ");
    scanf("%d", &w);

    int weight[n], value[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the weight and value of item %d: ", i + 1);
        scanf("%d %d", &weight[i], &value[i]);
    }

    int m[n + 1][w + 1];

    // Initialize the DP table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (i == 0 || j == 0)
                m[i][j] = 0;
            else {
                if (j - weight[i - 1] >= 0)
                    m[i][j] = max(m[i - 1][j], value[i - 1] + m[i - 1][j - weight[i - 1]]);
                else
                    m[i][j] = m[i - 1][j];
            }
        }
    }

    // Print the DP table
    printf("\nDP Table:\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    // Backtracking to find the selected items
    int maxVal = m[n][w];
    printf("\nMaximum value possible: %d\n", maxVal);

    int val = maxVal, weigh = w;
    for (int i = n; i > 0 && val > 0; i--) {
        if (val != m[i - 1][weigh]) { // Item i was included
            printf("Selected item %d\tweight: %d\tvalue: %d\n", i, weight[i - 1], value[i - 1]);
            val -= value[i - 1];
            weigh -= weight[i - 1];
        }
    }
}










#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void printSelectedItems(int **dp, int *wt, int n, int W) {
    int i = n, w = W;
    int *selectedItems = (int *)malloc(n * sizeof(int));
    int count = 0;

    while (i > 0 && w > 0) {
        if (dp[i][w] != dp[i - 1][w]) {
            selectedItems[count++] = i - 1;
            w -= wt[i - 1];
        }
        i--;
    }

    printf("Items selected in the optimal solution: ");
    for (int j = count - 1; j >= 0; j--) {
        printf("%d ", selectedItems[j]);
    }
    printf("\n");

    free(selectedItems);
}

int knapSack(int W, int *wt, int *val, int n) {
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((W + 1) * sizeof(int));
    }

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printSelectedItems(dp, wt, n, W);

    int maxProfit = dp[n][W];

    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);

    return maxProfit;
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int *profit = (int *)malloc(n * sizeof(int));
    int *weight = (int *)malloc(n * sizeof(int));

    printf("Enter the profit of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &profit[i]);
    }

    printf("Enter the weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }

    printf("Enter the maximum weight capacity of the knapsack: ");
    scanf("%d", &W);

    printf("Maximum profit: %d\n", knapSack(W, weight, profit, n));

    free(profit);
    free(weight);

    return 0;
}

