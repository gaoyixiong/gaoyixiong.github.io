#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n & 1) {puts("NO"); continue;}
        puts("YES");
        char cur = 'A';
        for (int i = 1; i <= n; i += 2) {
            putchar(cur); putchar(cur);
            cur = (cur == 'A' ? 'B' : 'A');
        }
        puts("");
    }
    return 0;
}