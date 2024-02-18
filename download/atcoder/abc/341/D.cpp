#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

inline ll rd() {
    ll x = 0;
    bool f = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}

int main() {
    ll n = rd(), m = rd(), k = rd();
    ll g = gcd(n, m);
    ll cnt = n / g + m / g - 2;
    ll bs = (k - 1) / cnt * n / g * m;
    ll rem = (k - 1) % cnt + 1;
    ll N = 0, M = 0, cur = 0;
    for (; rem; --rem) 
        if (N + n < M + m) {N += n; cur = N;}
        else {M += m; cur = M;}
    printf("%lld\n", bs + cur);
    return 0;
}