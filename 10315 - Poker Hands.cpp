#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

bool has(const vector<int>& ar, int value) {
    return std::find(ar.begin(), ar.end(), value) - ar.begin() != ar.size();
}
class Card {
public:
    int value;
    char suit;
};
class Hand {
public:
    Card card[5]{};
    vector<int> suits;
    vector<int> values;
    bool consecutive {false};
    int rank{};
    vector<int> subRank;
    void input(const string& s) {
        stringstream x(s);
        for (Card & i : card) {
            char temp;
            x >> temp >> i.suit;
            switch (temp) {
                case 'T': i.value = 8;
                    break;
                case 'J': i.value = 9;
                    break;
                case 'Q': i.value = 10;
                    break;
                case 'K': i.value = 11;
                    break;
                case 'A': i.value = 12;
                    break;
                default: i.value = temp - '2';
            }
        }
    }
    void getValues() {
        values = vector<int> (13, 0);
        for (Card i : card) {
            values[i.value]++;
        }
    }
    void getSuits() {
        suits = vector<int> (4, 0);
        for (Card i : card) {
            switch (i.suit) {
                case 'C': suits[0]++;
                    break;
                case 'D': suits[1]++;
                    break;
                case 'H': suits[2]++;
                    break;
                case 'S': suits[3]++;
            }
        }
    }
    bool isConsecutive() {
        for (int i = 0; i < values.size(); ++i) {
            if (values[i] == 1) {
                for (int j = 0; j < 5; ++j) {
                    if (i + j >= 13 || values[i + j] != 1) {
                        return false;
                    }
                }
                return true;
            }
        }
        return false;
    }
    void getRank() {
        getValues();
        getSuits();
        consecutive = isConsecutive();

        // check for Straight flush
        if (consecutive && has(suits, 5)) {
            rank = 9;
            subRank.push_back(values.rend() - std::find(values.rbegin(), values.rend(), 1) - 1);
            return;
        }

        // check for Four of a kind
        if (has(values, 4)) {
            rank = 8;
            subRank.push_back(std::find(values.begin(), values.end(), 4) - values.begin());
            return;
        }

        // check for Full House
        if (has(values, 3) && has(values, 2)) {
            rank = 7;
            subRank.push_back(std::find(values.begin(), values.end(), 3) - values.begin());
            subRank.push_back(std::find(values.begin(), values.end(), 2) - values.begin());
            return;
        }

        // check for flush
        if (has(suits, 5)) {
            rank = 6;
            for (auto & i : card) {
                subRank.push_back(i.value);
            }
            std::sort(subRank.begin(), subRank.end());
            std::reverse(subRank.begin(), subRank.end());
            return;
        }

        // Straight
        if (consecutive) {
            rank = 5;
            subRank.push_back(values.rend() - std::find(values.rbegin(), values.rend(), 1) - 1);
            return;
        }

        // Three of a Kind
        if (has(values, 3)) {
            rank = 4;
            subRank.push_back(std::find(values.begin(), values.end(), 3) - values.begin());
            return;
        }

        // pair
        if (has(values, 2)) {
            rank = 2;
            subRank.push_back(std::find(values.begin(), values.end(), 2) - values.begin());
            values[std::find(values.begin(), values.end(), 2) - values.begin()] = 0;
            // check for 2 pairs
            if (has(values, 2)) {
                rank = 3;
                subRank.push_back(std::find(values.begin(), values.end(), 2) - values.begin());
                values[std::find(values.begin(), values.end(), 2) - values.begin()] = 0;
                std::sort(subRank.begin(), subRank.end());
                std::reverse(subRank.begin(), subRank.end());
                subRank.push_back(std::find(values.begin(), values.end(), 1) - values.begin());
                return;
            } else {
                for (int i = static_cast<int>(values.size()) - 1; i >= 0; --i) {
                    if (values[i] == 1) {
                        subRank.push_back(i);
                    }
                }
                return;
            }
        }

        // High Card
        rank = 1;
        for (auto & i : card) {
            subRank.push_back(i.value);
        }
        std::sort(subRank.begin(), subRank.end());
        std::reverse(subRank.begin(), subRank.end());
    }
};
string sol(const string& line) {
    Hand black{}; black.input(line.substr(0, 14)); black.getRank();
    Hand white{}; white.input(line.substr(15)); white.getRank();

    if (black.rank > white.rank)
        return "Black wins.\n";
    else if (white.rank > black.rank)
        return "White wins.\n";
    else {
        for (int i = 0; i < black.subRank.size(); ++i) {
            if (black.subRank[i] > white.subRank[i])
                return "Black wins.\n";
            else if (white.subRank[i] > black.subRank[i])
                return "White wins.\n";
        }
        return "Tie.\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string t;
    while (getline(cin, t), t.size() >= 10) {
        cout << sol(t);
    }
    return 0;
}

