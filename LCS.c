#include <stdio.h>
#include <string.h>

void LCS(const char *s1, int m, const char *s2, int n) {
    int dp[m + 1][n + 1];
    int i, j;

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i][j - 1] > dp[i - 1][j]) ? dp[i][j - 1] : dp[i - 1][j];
            }
        }
    }

    int lcslen = dp[m][n];

    char lcs[lcslen + 1];
    lcs[lcslen] = '\0';

    i = m;
    j = n;
    int k = lcslen - 1;

    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i - 1][j]) {
            i--;
        } else if (dp[i][j] == dp[i][j - 1]) {
            j--;
        } else {
            lcs[k] = s1[i - 1];
            k--;
            i--;
            j--;
        }
    }

    printf("LCS LENGTH: %d\n", lcslen);
    printf("LCS: %s\n", lcs);
}

int main() {
    const char *str1 = "ACGTCCGCTCG";
    const char *str2 = "ATCTCT";

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    LCS(str1, len1, str2, len2);

    return 0;
}
