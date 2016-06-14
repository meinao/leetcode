#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void helper(
    vector<int>& result,
    unordered_set<int>& sofar, 
    const unordered_set<int>& candidates) {
    if (candidates.size() == 0) {
        for (auto elem : result) {
            cout << elem << ",";
        }
        cout << endl;
        return;
    }
    for (auto candidate: candidates) {
        unordered_set<int> new_candidates = candidates;
        new_candidates.erase(candidate);
        for (auto elem: result) {
            int new_candidate = abs(elem - candidate);
            if (new_candidate != candidate && sofar.find(new_candidate) == sofar.end()) {
                new_candidates.insert(new_candidate);
            }
        }
        result.push_back(candidate);
        sofar.insert(candidate);
        helper(result, sofar, new_candidates);
        result.pop_back();
        sofar.erase(candidate);
    }
}

void subtractGame(const pair<int, int>& p) {
    unordered_set<int> sofar = {p.first, p.second};
    unordered_set<int> candidates = {abs(p.first - p.second)};
    vector<int> result = {p.first, p.second};
    helper(result, sofar, candidates);
}

int main() {
    int a;
    int b;
    cin >> a;
    cin >> b;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    subtractGame(make_pair(a, b));
    return 0;
}
