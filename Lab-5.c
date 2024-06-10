#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void generatePermutations(int n);
void printPermutation(int *permutation, int n);
bool mobileEle(int *permutation, bool *direction, int n, int pos);
void swap(int *a, int *b);
void swapBool(bool *a, bool *b);

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    generatePermutations(n);
    return 0;
}

void generatePermutations(int n) {
    int *permutation = malloc(n * sizeof(int));
    bool *direction = malloc(n * sizeof(bool));
    for (int i = 0; i < n; i++) {
        permutation[i] = i + 1;
        direction[i] = false;
    }

    bool morePermutations = true;
    while (morePermutations) {
        printPermutation(permutation, n);
        int mobileIndex = -1;
        for (int i = 0; i < n; i++) {
            if (mobileEle(permutation, direction, n, i)) {
                if (mobileIndex == -1 || permutation[i] > permutation[mobileIndex]) {
                    mobileIndex = i;
                }
            }
        }
        if (mobileIndex == -1) {
            morePermutations = false;
            break;
        }
        int swapIndex = mobileIndex + (direction[mobileIndex] ? 1 : -1);
        swap(&permutation[mobileIndex], &permutation[swapIndex]);
        swapBool(&direction[mobileIndex], &direction[swapIndex]);
        for (int i = 0; i < n; i++) {
            if (permutation[i] > permutation[swapIndex]) {
                direction[i] = !direction[i];
            }
        }
    }
    free(permutation);
    free(direction);
}
void printPermutation(int *permutation, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", permutation[i]);
    }
    printf("\n");
}

bool mobileEle(int *permutation, bool *direction, int n, int pos) {
    if (direction[pos] == false && pos != 0 && permutation[pos] > permutation[pos - 1]) {
        return true;
    }
    if (direction[pos] == true && pos != n - 1 && permutation[pos] > permutation[pos + 1]) {
        return true;
    }
    return false;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapBool(bool *a, bool *b) {
    bool temp = *a;
    *a = *b;
    *b = temp;
}
