#include <iostream>
#include <vector>

class Game {
private:
    std::vector<std::vector<int>> matrix;
    int m;
    int n;
    int path_len = 0;
    void dfs(int i, int j, std::vector<std::vector<bool>>& visited, std::vector<std::vector<int>>& len_matrix);
public:
    int find_longest_increasing_path();
    Game(const std::vector<std::vector<int>>& a_matrix): 
     matrix(a_matrix), 
     m(a_matrix.size()),
     n(m==0?0:a_matrix[0].size())
     {};
};

