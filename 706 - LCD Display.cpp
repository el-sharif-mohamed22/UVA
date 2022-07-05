#include <iostream>
#include <vector>
#include <string>

using namespace std;

// display number in a map
void segment(vector<vector<char>>& map, unsigned int n, unsigned int s, unsigned int index) {
    if (n != 1 && n != 4) for (int i = 0; i < s; ++i) map[0][index + i + 1] = '-';
    if (n != 1 && n != 2 && n != 3 && n != 7) for (int i = 0; i < s; ++i) map[1 + i][index] = '|';
    if (n != 5 && n != 6) for (int i = 0; i < s; ++i) map[1 + i][index + 1 + s] = '|';
    if (n != 0 && n != 1 && n != 7) for (int i = 0; i < s; ++i) map[1 + s][index + i + 1] = '-';
    if (n == 2 || n == 6 || n == 0 || n == 8) for (int i = 0; i < s; ++i) map[2 + s + i][index] = '|';
    if (n != 2) for (int i = 0; i < s; ++i) map[2 + s + i][index + 1 + s] = '|';
    if (n != 1 && n != 7 && n != 4) for (int i = 0; i < s; ++i) map[2 + 2 * s][index + i + 1] = '-';
}

// read input, return false if input isn't valid, ture otherwise
bool read(unsigned int& s, vector<unsigned int>& ar) {
    cin >> s;
    string temp; cin >> temp;
    if (stoi(temp) == 0 && s == 0) return false;
    ar.clear();
    for (char i : temp) ar.push_back(i - '0');
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned int s; vector<unsigned int> ar;

    while (read(s, ar)) {

        unsigned int index{0}, rows{2 * s + 3}, cols{ar.size() * (s + 2) + ar.size() - 1};
        vector<vector<char>> display(rows, vector<char> (cols, ' '));

        for (unsigned int i : ar) {
            segment(display, i, s, index);
            index += s + 3;
        }

        for (auto & i : display) {
            for (char & j : i) cout << j;
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
