#include <vector>
#include <iostream>
#include "game.h"

using namespace std;
int main() {
    vector<vector<int>> matrix = {{9,9,4},{6,6,8},{2,1,1}};
    Game game(matrix);
    cout << game.find_longest_increasing_path() << endl;
    return 0;
}
