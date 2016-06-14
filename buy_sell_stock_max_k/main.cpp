#include <vector>
#include <iostream>

using namespace std;

int get_max_profit(int k, const vector<int>& prices) {
    if (k < 1 || prices.size() < 2) {
        return 0;
    }
    int n = prices.size();
    int res = 0;
    if (n < 2*k) {
        for (int i=1; i<n; ++i) {
            if (prices[i] > prices[i-1]) {
                res += prices[i] - prices[i-1];
            }
        }
        return res;
    }

    vector<vector<int>> buy(k+1, vector<int>(n, 0));
    vector<vector<int>> sell(k+1, vector<int>(n, 0));
    for (int i=1; i<k+1; ++i) {
        buy[i][0] = -prices[0];
    }

    for (int i=1; i<k+1; ++i) {
        for (int j=1; j<n; ++j) {
            buy[i][j] = max(sell[i-1][j-1] - prices[j], buy[i][j-1]);
            sell[i][j] = max(sell[i][j-1], buy[i][j-1] + prices[j]);
        }
    }
    return sell[k][n-1];
}
int main() {
    vector<int> vec = {1, 3, 2, 9, 1, 6, 10, 45, 2, 4, 8};
    int max_profit = get_max_profit(3, vec);
    cout << "max_profit: " << max_profit << endl;
    return 0;
}
