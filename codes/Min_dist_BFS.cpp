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
#define maxn 1050
#define fio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(0);
#define endl '\n'

typedef vector<vector<int>> mi;

vector<int>v[maxn];
int pred[maxn];
int dist[maxn];
int n, m;

int bfs(int s, int d){
	queue <int> q;
	bool vis[n];
	
	for(int i = 0; i < n; i++){
		pred[i] = -1;
		dist[i] = INT_MAX;
		vis[i] = 0;
	}
	
	vis[s] = 1;
	dist[s] = 0;
	q.push(s);
	
	while(!q.empty()){
		int ft = q.front();
		q.pop();
		for(int i = 0; i<sz(v[ft]); i++){
			int z  = v[ft][i];
			if(vis[z] == 0){
				vis[z] = 1;
				dist[z] = dist[ft] + 1;
				pred[z] = ft;				
				q.push(z);
				if(z == d) return 1;
			}
		}	
	}
	return 0;
}

void min_dista(int s, int d){
	
	if(bfs(s, d) == 0) {
		cout << "Infinito";
		return;
	}
	
	vector <int> caminho;
	int atual = d;
	caminho.pb(atual);
	
	while(pred[atual] != -1){
		caminho.pb(pred[atual]);
		atual = pred[atual];
	}
	
	cout << "Menor Dist: " << dist[d];
	cout << endl;
	cout << "Caminhos: " << endl;
	for(int i = sz(caminho)-1; i >= 0; i--){
		cout << caminho[i] << endl;	
	}	
}

int32_t main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;		
		v[x].pb(y);
		v[y].pb(x);	
	}
	
	int s, d;
	cin >> s >> d;
	min_dista(s, d);

}
