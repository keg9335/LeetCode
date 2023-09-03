class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int* dp = new int[amount+1];
        for (int i=0; i < amount+1; i++) {
            dp[i] = INT_MAX;
        }
        dp[0] = 0;
        for (auto coin : coins) {
            for (int i=coin; i < amount+1; i++) {
                if (dp[i - coin] != INT_MAX)
                dp[i] = min(dp[i], dp[i-coin] + 1);
            }
        }
        return dp[amount]==INT_MAX? -1 : dp[amount];
    }
};