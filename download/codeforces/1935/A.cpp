#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        string t; t = s; 
        reverse(t.begin(), t.end());
        if (t >= s) cout << s << endl;
        else cout << t << s << endl;
    }
    return 0;
}