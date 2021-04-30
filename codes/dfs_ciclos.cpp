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
#define maxn 1200
#define fio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(0);
#define endl '\n'

typedef vector<vector<int>> mi;
typedef pair<int, int> pii;
//C0d3
int n, m;

vector<int> v[maxn];
vector<int> pai;
vector<int> cor;
int cs, ce;

bool dfs(int u, int p){
	cor[u] = 1;
	for(auto z : v[u]){
		if(z == p) continue;
		if(cor[z] == 0){
			pai[z] = u;
			if(dfs(z, u)) return 1;
		}
		else if(cor[z] == 1){
			cs = z;
			ce = u;
			return 1;
		}
	}
	cor[u] = 2;
	return 0;
}

void find_ciclos(){
	cor.assign(n, 0);
	pai.assign(n, -1);
	cs = -1;

	for(int i = 0; i < n; i++){
		if(cor[i] == 0 and dfs(i, pai[i])) break;
	}

	if(cs == -1) cout << "Não tem ciclos";
	else{
		vector<int> c;
		int a = ce;
		c.pb(cs);
		for(int i = ce; i != cs; i = pai[i]) c.pb(i);
		c.pb(cs);
		reverse(all(c));
		cout << "Tem ciclo:" << endl;
		for(auto z : c) cout << z << " ";
		cout << endl;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x); 
	}
	find_ciclos();
}