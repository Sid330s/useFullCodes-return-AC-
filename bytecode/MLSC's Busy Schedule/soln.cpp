#include <bits/stdc++.h>
using namespace std;

int main() {

    int t, d, m, over_shoot=0;

    set<int> free;
    set<int>::iterator first, last;

    for (int i = 1; i <= 100000 + 1; i++) {
        free.insert(i);
    }

    cin >> t;

    for (int i = 1; i <= t; i++) {

        cin >> d >> m;
        first = free.upper_bound(d);
        last = first;

        while (first != free.begin() && m > 0) {
            first--;
            m--;
        }

        free.erase(first, last);
        over_shoot += m;

        cout << over_shoot << endl;
    }

    return 0;
}
