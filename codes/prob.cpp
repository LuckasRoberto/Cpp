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
typedef pair<int, int> pt;
//c0d3

int32_t main(){
	string a;
	string b;
	cin >> a;
	cin >> b;

	int pp = 1;
	int pos_a = 0;
	int pos_b = 0;
	int inc = 0;

	double res = 0;

	for(auto c : a){
		if(c == '+') pos_a++;
		else pos_a--;
	}
	for(auto c : b){
		if(c == '+') pos_b++;
		else if(c == '-') pos_b--;
		else inc++;
	}
	int dif = abs(pos_a - pos_b);
	double ac = 0;
	for(int i = 0; i < (1 << inc); i++){
		int t = 0;
		for(int j = 0; j < inc; j++){
			if( (i >> j)&1 ) t++;
			else t--;
		}
		if(t == dif) ac++;
	}
	res = (ac/(1 << inc));
	cout << setprecision(10) << fixed << res << endl;
}