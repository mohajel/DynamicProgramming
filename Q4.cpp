
//Q4 answer
//coin change problem
//time complexity: O(d*n)
//space complexity: O(d*n) or can be reduced to O(d)

#include <bits/stdc++.h>
using namespace std;

int coinchange(vector<int>& a, int sum, int n,
            vector<vector<int> >& dp)
{
    if (sum == 0)
        return dp[n][sum] = 1;
    if (n == 0)
        return 0;
    if (dp[n][sum] != -1)
        return dp[n][sum];
    if (a[n - 1] <= sum) {
        // Either Pick this coin or not
        return dp[n][sum] = coinchange(a, sum - a[n - 1], n, dp)
                        + coinchange(a, sum, n - 1, dp);
    }
    else // We have no option but to leave this coin
        return dp[n][sum] = coinchange(a, sum, n - 1, dp);
}
int main()
{
    int sum = 12;
    vector<int> v = { 1, 2, 3 };
    int n = v.size();
    vector<vector<int> > dp(n + 1, vector<int>(sum + 1, -1));
    int res = coinchange(v, sum, n, dp);
    cout << res << endl;
}
