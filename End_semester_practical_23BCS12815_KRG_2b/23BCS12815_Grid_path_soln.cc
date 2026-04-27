#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 3;

    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0},
        
    };

    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    if (grid[0][0] == 0)
        dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (grid[i][j] == 1) {
                dp[i][j] = 0;
                continue;
            }

            if (i > 0)
                dp[i][j] += dp[i - 1][j];

            if (j > 0)
                dp[i][j] += dp[i][j - 1];
        }
    }

    cout << dp[n - 1][n - 1] << endl;

    return 0;
}
