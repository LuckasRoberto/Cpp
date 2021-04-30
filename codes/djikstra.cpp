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
#define maxn 60000
#define fio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(0);
#define endl '\n'

typedef vector<vector<int>> mi;

//C0d3
typedef pair<int,int> pii;
vector<pii> v[maxn];
int n, m, s, o;

int dis[maxn];
int p[maxn];

void djtk(int o){
	for(int i=0; i <= n; i++) dis[i] = oo;
	
	set<pair<int, int>> s;	
	dis[o] = 0;
	s.insert({dis[o], o});
	
	while(!s.empty()){
		int a = s.begin()->ss;
		s.erase(s.begin());
		for(auto z : v[a]){
			int to = z.ff;
			int len = z.ss;
			if(dis[a] + len < dis[to]){
				s.erase({dis[to], to});
				dis[to] = dis[a] + len;
				p[to] = a;
				s.insert({dis[to], to});
			}
		}
	} 
}

void menor_caminho(int o, int s){
	vector<int> path;
	for(int a = s; a != o; a = p[a]){
		path.pb(a);
	}
	path.pb(o);
	reverse(path.begin(), path.end());
	for(auto z : path) cout << z << " ";
}

int32_t main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b, t;
		cin >> a >> b >> t;
		v[a].pb({b, t});
		v[b].pb({a, t});
	}

	int o, s;
	cin >> o >> s;	
	djtk(o);
	cout << dis[s] << endl;
	menor_caminho(o, s);
}
