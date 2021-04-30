#include <bits/stdc++.h>
using namespace std;

//Let's code together 
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
#define fio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(0);
#define endal '\n'
const int maxn = 250000;
const double eps = 0.000000001;
const int64_t MOD = 1e7+7;

typedef vector<vector<int>> mi;
typedef pair<int, int> pii;
// ~3~

vector<int> g[maxn];
int vis[maxn];

int menor;
int maior;
int soma;

struct vertice{
	int menor;
    int maior;
    int soma;
	bool operator < (const vertice &outro) const{ return menor > outro.menor; }
};

void dfs(int i, int o){
    vis[i] = 1;
    menor = min(menor, i);
    maior = max(maior, i);
    soma += 1;
    for(auto z : g[i]){
        if (z != o && !(vis[z]) ) dfs(z, o);
    }
}

int nao_harmonico(struct vertice ve){
    int menor_i = ve.menor;
    int maior_i  = ve.maior;
    int soma_i = ve.soma;
    if(soma_i == maior_i - menor_i + 1) return 0;
    return 1;
}

int32_t main(){
    priority_queue <vertice> q;

    int res = 0;
    int n, m;
    cin >> n >> m;

    for(int i = 0 ; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            vertice ve;

            menor = oo;
            maior = -oo;
            soma = 0;
            dfs(i, i);

            ve.menor = menor;
            ve.maior = maior;
            ve.soma = soma;

            q.push(ve);
        }
    }

    while (!q.empty()) {
        vertice resul;
		vertice pq = q.top(); 
        q.pop();

		if ( nao_harmonico(pq)  ){
            vertice sq = q.top();
            q.pop();

            resul.menor = min(pq.menor, sq.menor);
            resul.maior = max(pq.maior, sq.maior);
            resul.soma  = pq.soma + sq.soma;

            if( nao_harmonico(resul) ) q.push(resul); 
            res++;
        } 
	}

    cout << res << endl;
}