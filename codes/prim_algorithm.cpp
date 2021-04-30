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

vector<pii> v[maxn];
int dis[maxn];
int vis[maxn];
int res;
int n, m;

int prim(){
	for(int i = 0; i < n; i++) dis[i] = oo;
	
	dis[0] = 0;
	set<pii>s;
	s.insert({dis[0], 0});

	while(1){
		int dv = -1;
		while(!s.empty()){
			int a = s.begin()->ss;
			s.erase(s.begin());
			if(!vis[a]) {
				dv = a;
				break;
			}
		}

		vis[dv] = 1;
		if(dv == -1) break;

		for(auto z : v[dv]){
			int to = z.ff;
			int len = z.ss;
			if(len < dis[to] and !vis[to]){
				s.erase({dis[to], to});
				dis[to] = len;
				s.insert({dis[to], to});
			}
		}
	}

	int cnt = 0;
	for(int i = 0; i < n; i++) cnt += dis[i];
	return cnt;
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 0; i < m; i++){
		int x, y, c;
		cin >> x >> y >> c;
		v[x].pb(pii(y, c));
		v[y].pb(pii(x, c)); 
	}

	res = prim();
	cout << res;
}