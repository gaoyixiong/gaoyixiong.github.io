#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll rd() {
	ll x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define N 2007
#define eb emplace_back
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

typedef long long T;

#define let  const auto
#define lett const T
#define letp const P 

#define z(x) ((x) == 0) // is zero

struct P {
    T x, y;
    P (T x = 0, T y = 0) : x(x), y(y) {}
    P operator + (letp &p) const {return {x + p.x, y + p.y};} 
    P operator - (letp &p) const {return {x - p.x, y - p.y};} 
    P operator - () const {return {-x, -y};}

    T operator | (letp &p) const {return x * p.x + y * p.y;} // dot
    T operator ^ (letp &p) const {return x * p.y - y * p.x;} // cross

    bool operator < (letp &p) const {return z(x - p.x) ? y < p.y : x < p.x;}
   
    // left(counterclockwise) = 1 | on = 0 | right(clockwise) = -1
    int ori(letp &p) const {T t = (*this) ^ p; return (t > 0) - (t < 0);}

} zero, p[N];

struct argcmp { // compared by polar angle
    bool operator() (letp &a, letp &b) const {
        const auto quad = [](letp &a) {
            if (a.y < 0) return 1; // halfplane with negative y
            if (a.y > 0) return 4;  // halfplane with positive y
            if (a.x < 0) return 5; // negative x-axis
            if (a.x > 0) return 3;  // positive x-axis
            return 2; // origin
        };
        const int qa = quad(a), qb = quad(b);
        if (qa != qb) return qa < qb;
        return (a ^ b) > 0;
    }    
};

bool onconv[N];

int main() {
	int n = rd(), ans = 0;
	rep(i, 1, n) {p[i].x = rd(); p[i].y = rd();}

	// convex hull
	vector<int> s, st;
    rep(i, 1, n) s.eb(i);
    sort(s.begin(), s.end(), [&](int &x, int &y){return p[x] < p[y];});
    const auto check = [](const vector<int> &st, int &u) {
        const auto back1 = st.back(), back2 = *prev(st.end(), 2);
        return (p[back1] - p[back2]).ori(p[u] - p[back2]) <= 0;
    };
    for (auto u : s) {
        while (st.size() > 1 && check(st, u)) st.pop_back();
        st.eb(u);
    }
    size_t k = st.size();
    s.pop_back(); reverse(s.begin(),s.end());
    for (auto u : s) {
        while (st.size() > k && check(st, u)) st.pop_back();
        st.push_back(u);
    }
    st.pop_back();
    for (auto x : st) onconv[x] = true;

    auto calc = [&](int x) {
    	s.clear();
    	rep(i, 1, n) if (i != x) s.eb(i);
    	sort(s.begin(), s.end(), [&](int a, int b) {return argcmp()(p[a] - p[x], p[b] - p[x]);});
    	ans += (onconv[s[0]] && onconv[s[n - 2]]);
    	rep(i, 0, n - 3) ans += (onconv[s[i]] && onconv[s[i + 1]]);
    };

   	rep(i, 1, n) if (!onconv[i]) calc(i);
   	printf("%d\n", ans + 1);	
	return 0;
}