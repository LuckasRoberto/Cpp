#include <bits/stdc++.h>
using namespace std;

/* Lucas Nogueira - Problema: */
#define int long long
#define fur(i, a, b) for(int i = a; i < b; i++);
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) (int)(x).size()
#define oo 0x3f3f3f3f
#define maxn 10000
#define fio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(0);
#define endl '\n'
const double eps = 0.000000001;
const int64_t MOD = 10e9 + 7;

typedef vector<vector<int>> mi;
typedef pair<int, int> pii;
//c0d3

int n, m;
int q[maxn][maxn];

int kadanes(std::vector<int> v){
	int gbm = INT_MIN;
	int lm = 0;
	for(int i = 0; i < sz(v); i++){
		lm = max(lm, lm + v[i]);
		gbm = max(lm, gbm);
	}
	return gbm;
}

int max_quadrado(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++) q[i][j] += q[i-1][j];
	}
	int res = 0;
	for(int up = 1; up <= n; up++){
		for(int bt = up; bt <= n; bt++){
			std::vector<int> v;
			for(int i = 0; i <= m; i++) v.pb(q[bt][i] - q[up-1][i]);
			res = max(res, kadanes(v));
		}
	}
	return res;
}

int32_t main(){
	fio;
	cin >> n >> m;
	for(int i=1; i<=n;i++){
		for(int j=1; j<=m; j++){
			cin >> q[i][j];
		}
	}
	cout << max_quadrado();
}