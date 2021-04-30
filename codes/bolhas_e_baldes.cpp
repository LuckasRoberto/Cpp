#include <bits/stdc++.h>
using namespace std;

/* Lucas Nogueira - Problema: musica */
#define int long long
#define fur(i, a, b) for(int i = a; i < b; i++);
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) (int)(x).size()
#define oo 0x3f3f3f3f
#define maxn 150
#define fio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(0);
#define endl '\n'
const double eps = 0.000000001;
const int64_t MOD = 10e9 + 7;

typedef vector<vector<int>> mi;
typedef pair<int, int> pii;
//c0d3:

int n;
int m;

int merge_sort(vector<int> &v){
	int inv = 0;
	if(sz(v) == 1) return 0;
	std::vector<int> u1;
	std::vector<int> u2;

	for(int i = 0; i < sz(v)/2; i++) u1.pb(v[i]);
	for(int i = sz(v)/2; i < sz(v); i++) u2.pb(v[i]);

	inv += merge_sort(u1);
	inv += merge_sort(u2);

	u1.pb(oo);
	u2.pb(oo);

	int ini = 0;
	int ini2 = 0;
	for(int i = 0; i < sz(v); i++){
		if(u1[ini] < u2[ini2]){
			v[i] = u1[ini];
			ini++;
		}
		else{
			v[i] = u2[ini2];
			ini2++;
			inv += (sz(u1))-ini;
		}
	}
	return inv;
}

int32_t main(){
	fio;
	while(1){
		vector<int> v;
		string s;
		getline(cin, s);
		
		if(sz(s) == 1 and s == "0") break;
		istringstream is(s);
		int a;

		while(is >> a) v.pb(a);
		int inv = merge_sort(v);

		if(inv%2 != 0) cout << "Marcelo";
		else cout << "Carlos";
		// cout << inv;
		cout << endl;
	}
}