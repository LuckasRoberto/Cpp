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
#define maxn 1010
#define fio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(0);
#define endl '\n'
const double eps = 0.000000001;
const int64_t MOD = 10e9 + 7;

typedef vector<vector<int>> mi;
typedef pair<int, int> pii;
//c0d3

int n, m;
int q[maxn][maxn];
int final;

int maxret(vector<int> h, int len){
	int res = 0;
	int a = 0;
	int i = 0;
	stack<int>s;
	while(i < len){
		if(s.empty() or h[s.top()] <= h[i]) s.push(i++);
		else{
			int tp = s.top();
			s.pop();
			if(s.empty()) a = (h[tp]+1)*(i+1); 
			else a = (h[tp]+1)*((i-1)-s.top()+1);
		}
		res = max(res, a);
	}
	while(!s.empty()){
		int tp = s.top();
		s.pop();
		if(s.empty()) a = (h[tp]+1)*(i+1); 
		else a = (h[tp]+1)*((i-1)-s.top()+1);
		res = max(res, a);
	}
	return res;
}

int32_t main(){
	fio;
	cin >> n >> m;
	for(int i =0; i < n; i++){
		for(int j = 0; j < m; j++) cin >> q[i][j];
	}
	final = 0;
	vector<int> v(m);
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < m-1; j++){
			if(q[i+1][j+1] + q[i][j] <= q[i][j+1] + q[i+1][j]) v[j]++;
			else v[j] = 0;
		}
		final = max(final, maxret(v, m-1));
	}
	cout << final << endl;
}