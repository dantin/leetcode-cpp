#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<vector<int>> rows, columns, boxes;
        for (size_t i = 0; i < 9; i++) {
            rows.push_back(vector<int>(9));
            columns.push_back(vector<int>(9));
            boxes.push_back(vector<int>(9));
        }

        for (size_t i = 0; i < 9; i++) {
            for (size_t j = 0; j < 9; j++) {
                char ch = board[i][j];
                if (ch == '.') {
                    continue;
                }

                size_t n = ch - '1';
                size_t k = (i / 3) * 3 + j / 3;

                rows[i][n] += 1;
                columns[j][n] += 1;
                boxes[k][n] += 1;

                if (rows[i][n] > 1 || columns[j][n] > 1 || boxes[k][n] > 1) {
                    return false;
                }
            }
        }

        return true;
    }
};

void print_board(vector<vector<char>> &board)
{
    cout << "[";
    for (auto rit = board.begin(); rit != board.end(); ++rit) {
        if (rit != board.begin()) {
            cout << endl << ",";
        }
        cout << "[";
        for (auto cit = rit->begin(); cit != rit->end(); ++cit) {
            if (cit != rit->begin()) {
                cout << ", ";
            }
            cout << "\"" << *cit << "\"";
        }
        cout << "]";
    }
    cout << "]" << endl;
}

int main()
{
    Solution s;
    vector<vector<vector<char>>> cases {
        {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
        },
        {
            {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
        },
    };

    for (auto board : cases) {
        cout << "Input: board =" << endl;
        print_board(board);

        bool retval = s.isValidSudoku(board);

        cout << "Output: " << (retval ? "true" : "false") << endl << endl;
    }

    return 0;
}
