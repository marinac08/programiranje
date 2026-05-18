#include <bits/stdc++.h>
using namespace std;

void solve() {
    int h, w;
    if (!(cin >> h >> w)) return;
    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dp(h, vector<int>(w, 0));
    for (int j = 0; j < w; ++j) {
        dp[0][j] = grid[0][j];
    }
    for (int i = 1; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int top = dp[i-1][j];
            int top_left = (j > 0) ? dp[i-1][j-1] : 0;
            int top_right = (j < w - 1) ? dp[i-1][j+1] : 0;
            dp[i][j] = grid[i][j] + max({top_left, top, top_right});
        }
    }
    int max_stones = 0;
    for (int j = 0; j < w; ++j) {
        max_stones = max(max_stones, dp[h-1][j]);
    }

    cout << max_stones << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
