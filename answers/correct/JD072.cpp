#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> order = {"Hunter", "Gun", "Bear"};
    string s1, s2;
    while (cin >> s1 >> s2) {
        if (s1 == s2) {
            cout << "Tie" << endl;
            continue;
        }
        int idx1 = -1, idx2 = -1;
        for (int i = 0; i < 3; ++i) {
            if (order[i] == s1) idx1 = i;
            if (order[i] == s2) idx2 = i;
        }
        if ((idx1 + 1) % 3 == idx2) {
            cout << "Player1" << endl;
        } else {
            cout << "Player2" << endl;
        }
    }
    return 0;
}