#include <stdio.h>

int freq[5] = {0}; // Array to hold frequencies of each coin

int coinChange(int n, const int* c, int i, int size) {
    if (n == 0) return 0;
    else if (i >= size) return -1; // Check for valid index
    else if (c[i] <= n) {
        freq[i]++;
        return 1 + coinChange(n - c[i], c, i, size);
    } else {
        return coinChange(n, c, i + 1, size);
    }
}

int main() {
    int n = 87;
    int c[] = {50, 25, 10, 5, 1};
    int size = sizeof(c) / sizeof(c[0]);

    int numCoins = coinChange(n, c, 0, size);
    if (numCoins == -1) {
        printf("No combination of coins can make the amount.\n");
    } else {
        printf("numCoins = %d\n", numCoins);

        for (int i = 0; i < size; i++) {
            printf("%d ", freq[i]);
        }
        printf("\n");
    }

    return 0;
}
