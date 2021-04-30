#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define fur(i, a, b) for(int i = a; i < b; i++);
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss seconds
#define sz(x) (int)(x).size()
#define oo 0x3f3f3f3f
#define maxn 1010
#define fio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(0);
#define endl '\n'

typedef vector<vector<int>> mi;
priority_queue <int, vector<int>, greater<int>> pqm;


void printv(deque<int>v){
	cout << "(";
	for(auto t : v) cout << t << " ";
	cout << ")";
}

int32_t main(){
	fio;
	int n, k, m;
	while(1){
		cin >> n >> k >> m;
		deque <int> v;
		if (n+k+m == 0) break;
		
		int a;
		for(int i = 0; i < n; i++){
			cin >> a;
			v.pb(a);
		}
		
		//printv(v);
		//cout << endl;
		while(m--){
			int tmp = v.back();
			v.pop_back();
			v.push_front(tmp);
			//printv(v);
			//cout << endl;
		}
		printv(v);
		cout << v[k-1]<< endl;			
		//cout << endl;
	}
}
