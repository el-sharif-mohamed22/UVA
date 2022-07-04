#include <iostream>
#include <vector>
using namespace std;

bool inRange(const int& i, const int& j, const unsigned int& rows, const unsigned int& cols) {
    return i >= 0 && j >= 0 && i < rows && j < cols;
}

void solve(vector<vector<char>>& map) {
    for (int r = 0; r < map.size(); ++r) {
        for (int c = 0; c < map[r].size(); ++c) {
            // found a mines, get it's adjacent safe squares and increment their values.
            if (map[r][c] == '*') {
                // getting the 8 adjacent cells
                for (int xShift = -1; xShift <= 1; ++xShift) {
                    for (int yShift = -1; yShift <= 1; ++yShift) {
                        int i{r + xShift}, j{c + yShift};
                        if (inRange(i, j, map.size(), map[r].size()) && map[i][j] != '*') {
                            map[i][j]++;
                        }
                    }
                }
            }
        }
    }
}

void read(vector<vector<char>>& map) {
    for (auto & i : map) {
        for (char & j : i) {
            cin >> j;
            // The initial value for every safe square is 0.
            if (j == '.') {
                j = '0';
            }
        }
    }
}

void print(vector<vector<char>>& map, const int& caseNumber) {
    // new line before every case, except case 1.
    if (caseNumber != 1) cout << endl;
    cout << "Field #" << caseNumber << ":" << endl;
    for (auto & i : map) {
        for (char & j : i) {
            cout << j;
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, count{1};
    while (cin >> n >> m, n != 0 || m != 0) {
        vector<vector<char>> map(n, vector<char>(m));
        read(map);
        solve(map);
        print(map, count);
        count++;
    }
    return 0;
}
