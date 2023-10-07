#include <iostream>
#include <utility>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>> &board) {
        bool done = false;
        vector<vector<bool>> rows, columns, boxes;
        for (size_t i = 0; i < 9; i++) {
            rows.push_back(vector<bool>(9));
            columns.push_back(vector<bool>(9));
            boxes.push_back(vector<bool>(9));
        }
        vector<pair<size_t, size_t>> spaces;
        for (size_t i = 0; i < 9; i++) {
            for (size_t j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    spaces.push_back(make_pair(i, j));
                } else {
                    int digit = board[i][j] - '1';
                    size_t k = (i / 3) * 3 + j / 3;
                    rows[i][digit] = columns[j][digit] = boxes[k][digit] = true;
                }
            }
        }

        dfs(board, rows, columns, boxes, spaces, 0, done);
    }

private:
    void dfs(
        vector<vector<char>> &board,
        vector<vector<bool>> &rows,
        vector<vector<bool>> &columns,
        vector<vector<bool>> &boxes,
        vector<pair<size_t, size_t>> &spaces,
        size_t pos,
        bool &done
    ) {
        if (pos == spaces.size()) {
            done = true;
            return;
        }

        size_t i = spaces[pos].first;
        size_t j = spaces[pos].second;
        size_t k = (i / 3) * 3 + j / 3;
        for (size_t digit = 0; digit < 9; digit++) {
            if (!rows[i][digit] && !columns[j][digit] && !boxes[k][digit]) {
                rows[i][digit] = columns[j][digit] = boxes[k][digit] = true;
                board[i][j] = (char)(digit + '1');
                dfs(board, rows, columns, boxes, spaces, pos + 1, done);
                rows[i][digit] = columns[j][digit] = boxes[k][digit] = false;
            }
            if (done) {
                return;
            }
        }
    }
};

int main()
{
    vector<vector<char>> board{
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'},
    };
    Solution s;

    cout << "Input: board = ";
    print_board(board);

    s.solveSudoku(board);

    cout << "Output: ";
    print_board(board);

    return 0;
}
