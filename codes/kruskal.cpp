#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define fur(i, a, b) for(int i = a; i < b; i++);
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) (int)(x).size()
#define oo 0x3f3f3f3f
#define maxn 10500
#define fio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(0);
#define endl '\n'

typedef vector<vector<int>> mi;

//C0d3
typedef pair<int,int>pii;
int n, m;


struct ar{
	int x, y;
	int c;

	bool operator< (const ar &o){
		return c < o.c;
	}
};

std::vector<ar> v;
int pai[maxn];
int peso[maxn];

int fp(int x){
	if(x == pai[x]) return x;
	return pai[x] = fp(pai[x]);
}

void unir(int x, int y){
	x = fp(x);
	y = fp(y);

	if(peso[x] < peso[y]) pai[x] = y;
	else if(peso[y] < peso[x]) pai[y] = x;
	else{
		pai[x] = y;
		peso[y]++;
	} 
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;
	for(int i = 0; i < n; i++) pai[i] = i;
	for(int i = 0; i < m; i++){
		int x, y, t;
		ar a;
		cin >> x >> y >> t;
		a.x = x;
		a.y = y;
		a.c = t;
		v.pb(a);
	}
	sort(all(v));

	vector<ar> mst;
	for(int i = 0; i < m; i++){
		if(fp(v[i].x) != fp(v[i].y)){
			unir(v[i].x, v[i].y);
			mst.pb(v[i]);
		}
	}

	for(auto z : mst){
		cout << z.x << " " << z.y << " | ";
		cout << z.c;
		cout << endl;
	}
}