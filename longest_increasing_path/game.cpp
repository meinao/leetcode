#include "game.h"
using namespace std;
void Game::dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<int>>& len_matrix) {
    int res = 0;
    if (i!=0 && matrix[i-1][j] > matrix[i][j]) {
        if (!visited[i-1][j]) {
            dfs(i-1, j, visited, len_matrix);
        }
        res = max(res, len_matrix[i-1][j]);
    }
    if (j!=0 && matrix[i][j-1] > matrix[i][j]) {
        if (!visited[i][j-1]){
            dfs(i, j-1, visited, len_matrix);
        }
        res = max(res, len_matrix[i][j-1]);
    }

    if (i<m-1 && matrix[i+1][j] > matrix[i][j]) {
        if (!visited[i+1][j]) {
            dfs(i+1, j, visited, len_matrix);
        }
        res = max(res, len_matrix[i+1][j]);
    }
    
    if (j<n-1 && matrix[i][j+1] > matrix[i][j]) {
        if (!visited[i][j+1]) {
            dfs(i, j+1, visited, len_matrix);
        }
        res = max(res, len_matrix[i][j+1]);
    }

    visited[i][j] = true;
    len_matrix[i][j] = res + 1;
}

int Game::find_longest_increasing_path() {
    if (path_len != 0) {
        return path_len;
    }

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<vector<int>> len_matrix(m, vector<int>(n, 0));
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            if (!visited[i][j]) {
                dfs(i, j, visited, len_matrix);
                path_len = max(path_len, len_matrix[i][j]);
            }
        }
    }

    return path_len;
}
