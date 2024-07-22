#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

int a[51];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int lst = 0;
        rep(i, 1, n) cin >> a[i];

        auto calc = [&]() {
            rep(i, 1, n) {
                if (a[i] < 10) {
                    if (a[i] < lst) {puts("NO"); return;}
                    lst = a[i];
                } else {
                    int y = a[i] % 10;
                    int x = a[i] / 10;
                    if (x > y || x < lst) { // cannot do the operation
                        if (a[i] < lst) {puts("NO"); return;}
                        lst = a[i];
                    } else lst = y;
                }
            }
            puts("YES");   
        };

        calc();
    }
    return 0;
}