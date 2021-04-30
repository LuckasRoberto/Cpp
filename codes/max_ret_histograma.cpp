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
int n;

int maxret(std::vector<int> h){
	int res = 0;
	int a = 0;
	int i = 0;
	stack<int>s;
	while(i < sz(h)){
		if(s.empty() or h[s.top()] <= h[i]) s.push(i++);
		else{
			int tp = s.top();
			s.pop();
			if(s.empty()) a = h[tp]*(i-1); 
			else a = h[tp]*((i-1)-s.top());
		}
		res = max(res, a);
	}
	while(!s.empty()){
		int tp = s.top();
		s.pop();
		if(s.empty()) a = h[tp]*(i-1); 
		else a = h[tp]*((i-1)-s.top());
		res = max(res, a);
	}
	return res;
}

int32_t main(){
	fio;
	cin >> n;
	std::vector<int> v(n);
	for(int i =0; i < n; i++) cin >> v[i];
	cout << maxret(v);
}