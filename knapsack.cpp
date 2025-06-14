#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int items, capacity;
    cin >> items >> capacity;
    vector<int> weights(items, 0);
    vector<int> values(items, 0);
    for (int i = 0; i < items; ++i) cin >> weights[i] >> values[i];
    vector<vector<int>> dp(items, vector<int>(capacity, 0));
    for(int i = 0; i < items; ++i) for(int j = 0; j < capacity; ++j) {
        if(i == 0)  if(weights[i] <= j) dp[i][j] = values[i];
        else if(weights[i] <= j) {
            dp[i][j] = max(dp[i - 1][j], dp[i-1][j-weights[i]] + values[i]);
        } else {
            dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[items - 1][capacity - 1];
    return 0;
}