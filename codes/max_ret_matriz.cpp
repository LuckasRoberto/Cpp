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
int res;

int maxret(vector<int> h){
	int res = 0;
	int a = 0;
	int i = 0;
	stack<int>s;
	while(i < sz(h)){
		if(s.empty() or h[s.top()] <= h[i]) s.push(i++);
		else{
			int tp = s.top();
			s.pop();
			if(s.empty()) a = h[tp]*(i); 
			else a = h[tp]*((i-1)-s.top());
		}
		res = max(res, a);
	}
	while(!s.empty()){
		int tp = s.top();
		s.pop();
		if(s.empty()) a = h[tp]*(i); 
		else a = h[tp]*((i-1)-s.top());
		res = max(res, a);
	}
	return res;
}

int max2dret(){
	for(int i = 0; i < n; ++i){
		if(i != 0){
			std::vector<int> v;
			for(int j = 0; j < m; j++){
				if(q[i][j] != 0) q[i][j] += q[i-1][j];
				v.push_back(q[i][j]);
			}
			res = max(res, maxret(v));
		}
	}
	return res;
}

int32_t main(){
	fio;
	cin >> n;
	cin >> m;
	for(int i = 0; i < n; i++){
		vector<int> v;
		for(int j = 0; j < m; j++){
			cin >> q[i][j];
			if(i == 0) v.pb(q[i][j]);
		}
		if(i==0) res = maxret(v);
	}
	cout << max2dret();
}