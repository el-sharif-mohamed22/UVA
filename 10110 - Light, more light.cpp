#include <iostream>
#include <cmath>
using namespace std;
int main() {
    unsigned int t;
    while (cin >> t, t != 0) {
        unsigned int root{static_cast<unsigned int>(sqrt(t))};
        cout << (root * root == t ? "yes" : "no") << endl;
    }
}
