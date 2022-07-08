#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
string sol2(int& STEP, int& MODUlUS) {
    int seed{0}, count{0};
    do {
        seed = (seed + STEP) % MODUlUS;
        count++;
    } while (seed != 0);
    if (count != MODUlUS) return "Bad Choice\n";
    return  "Good Choice\n";
}
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int step, mod;
    while (cin >> step >> mod) {
        cout << right << setw(10) << step << setw(10) << mod << "    "
             << left << (gcd(step, mod) == 1 ? "Good Choice\n" : "Bad Choice\n") << endl;
    }
    return 0;
}
