#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

inline int rd() {
    int x = 0;
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

#define N 200007

char s[N];

int to[26];

int main() {
    rep(i, 0, 25) to[i] = i;
    int n = rd();
    scanf("%s", s + 1);
    per(q, rd(), 1) {
        char c = getchar();
        while (!isalpha(c)) c = getchar();
        char d = getchar();
        while (!isalpha(d)) d = getchar();
        rep(i, 0, 25) if (to[i] == c - 'a') to[i] = d - 'a';
    }
    rep(i, 1, n) putchar(to[s[i] - 'a'] + 'a');
    return 0;
}