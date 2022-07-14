#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool row(const vector<vector<short>>& sudoku, int n) {
    for (int i = 0; i < n; ++i) {
        int temp{0}, min{1};
        for (int j = 0; j < n; ++j) {
            temp = temp ^ sudoku[i][j];
            temp = temp ^ min;
            min++;
        }
        if (temp != 0) {
            return false;
        }
    }
    return true;
}

bool col(const vector<vector<short>>& sudoku, int n) {
    for (int j = 0; j < n; ++j) {
        int temp{0}, min{1};
        for (int i = 0; i < n; ++i) {
            temp = temp ^ sudoku[i][j];
            temp = temp ^ min;
            min++;
        }
        if (temp != 0) {
            return false;
        }
    }
    return true;
}

bool grid(const vector<vector<short>>& sudoku, int n) {
    int root = static_cast<int>(trunc(sqrt(n)));
    for (int j = 0; j < n; j += root) {
        for (int i = 0; i < n; i += root) {
            int temp{0}, min{1};
            for (int i2 = 0; i2 < root; ++i2) {
                for (int j2 = 0; j2 < root; ++j2) {
                    temp = temp ^ sudoku[i + i2][j2 + j];
                    temp = temp ^ min;
                    min++;
                }
            }
            if (temp != 0) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n; cin >> t;
    for (int f = 0; f < t; ++f) {
        cin >> n;
        vector<vector<short>> sudoku(n, vector<short>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> sudoku[i][j];
            }
        }

        if (row(sudoku, n) && col(sudoku, n) && grid(sudoku, n)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }

    }
    return 0;
}

