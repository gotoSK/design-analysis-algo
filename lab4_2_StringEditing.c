#include <stdio.h>
#include <string.h>

// Utility function to find the minimum of three numbers
int min(int x, int y, int z) {
    if (x < y) {
        return (x < z) ? x : z;
    } else {
        return (y < z) ? y : z;
    }
}

int editDistDP(char *str1, char *str2, int m, int n) {
    // Create a table to store results of subproblems
    int dp[m + 1][n + 1];

    // Fill d[][] in bottom up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // If first string is empty, only option is to
            // insert all characters of the second string
            if (i == 0)
                dp[i][j] = j; // Min. operations = j

            // If the second string is empty, the only option is to
            // remove all characters of the second string
            else if (j == 0)
                dp[i][j] = i; // Min. operations = i

            // If last characters are the same, ignore the last char
            // and recur for the remaining string
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            // If the last character is different, consider
            // all possibilities and find the minimum
            else
                dp[i][j] = 1 + min(dp[i][j - 1],    // Insert
                                  dp[i - 1][j],    // Remove
                                  dp[i - 1][j - 1]); // Replace
        }
    }
    return dp[m][n];
}

// Driver code
int main() {
    // your code goes here
    char str1[] = "sunday";
    char str2[] = "saturday";
    printf("%d\n", editDistDP(str1, str2, strlen(str1), strlen(str2)));

    return 0;
}
