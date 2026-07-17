#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long swords = 0, blades = 0, spears = 0;
    long long total = 0;
    for (int i = 0; i < n; ++i) {
        int cnt;
        char type;
        cin >> cnt >> type;
        total += cnt;
        if (type == 'C') swords += cnt;
        else if (type == 'R') blades += cnt;
        else if (type == 'F') spears += cnt;
    }
    cout << "Total: " << total << " weapons" << endl;
    cout << "Total swords: " << swords << endl;
    cout << "Total blades: " << blades << endl;
    cout << "Total spears: " << spears << endl;
    cout << fixed << setprecision(2);
    if (total == 0) {
        cout << "Percentage of swords: 0.00 %" << endl;
        cout << "Percentage of blades: 0.00 %" << endl;
        cout << "Percentage of spears: 0.00 %" << endl;
    } else {
        double ps = 100.0 * swords / total;
        double pb = 100.0 * blades / total;
        double pf = 100.0 * spears / total;
        cout << "Percentage of swords: " << ps << " %" << endl;
        cout << "Percentage of blades: " << pb << " %" << endl;
        cout << "Percentage of spears: " << pf << " %" << endl;
    }
    return 0;
}