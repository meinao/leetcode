#include <vector>
#include <iostream>
using namespace std;
int get_max_profit(const vector<int>& prices) {
    int n = prices.size();
    if (n < 2) {
        return 0;
    }

    int buy = -prices[0];
    int sell = 0;
    for (int i=1; i<n; ++i) {
        sell = max(buy + prices[i], sell);
        buy = max(buy, -prices[i]);
    }
    return sell;
}

int main() {
    vector<int> vec = {2, 5, 3, 8, 3, 9, 2, 1, 11};
    cout << get_max_profit(vec) << endl;
}
