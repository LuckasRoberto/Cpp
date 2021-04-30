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

bool verdade[maxn];
bool vis[maxn];
int s[maxn];

vector<int> v[maxn];
bitset<maxn>caminho[maxn];

void dfs(int o, int raiz){
	vis[o] = 1;
	caminho[o][raiz] = 1;
	for(auto z : v[o]) if(vis[z] == 0) dfs(z, raiz);
}

int32_t main(){
	fio;
	int ee, ti, ve;
	cin >> ee >> ti >> ve;
	for(int i = 0; i  < ti; i++){
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		s[b] = 1;
	}
	for(int i = 1; i <= ee; i++) {
		memset(vis, 0, sizeof(vis));
		if(s[i] == 0) dfs(i,i);
	}
	for(int i = 0; i < ve ; i++){
		int x;
		cin >> x;
		verdade[x] = 1;
		for(int j = 1; j <= ee; j++) 
			if( (caminho[x]&caminho[j]).count() == caminho[x].count() ) 
				verdade[j] = 1; 
	}
	for(int i = 1; i <= ee; i++){
		if(verdade[i]) cout << i << " ";		
	}
}