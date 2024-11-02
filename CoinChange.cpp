#include <iostream>
#include <vector>

using namespace std;

vector<int> freq(5, 0); // Vector to hold frequencies of each coin

int coinChange(int n, const vector<int>& c, int i) {
    if (n == 0) return 0;
    else if (i >= c.size()) return -1; // Check for valid index
    else if (c[i] <= n) {
        freq[i]++;
        return 1 + coinChange(n - c[i], c, i);
    } else {
        return coinChange(n, c, i + 1);
    }
}

int main() {
    int n = 87;
    vector<int> c = {50, 25, 10, 5, 1};

    int numCoins = coinChange(n, c, 0);
    if (numCoins == -1) {
        cout << "No combination of coins can make the amount." << endl;
    } else {
        cout << "numCoins = " << numCoins << endl;

        for (size_t i = 0; i < c.size(); i++) {
            cout << freq[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
