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
#define maxn 1000
#define fio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(0);
#define endl '\n'

typedef vector<vector<int>> mi;
//C0d3
int n, m;
int dis[maxn][maxn];

void floyd_warshall(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }
}

int32_t main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) dis[i][j] = 0;
            else dis[i][j] = oo;
        }
    }
    for(int i = 0; i < m; i++){
        int a, b, t;
        cin >> a >> b >> t;
        dis[a][b] = min(dis[a][b], t);
        dis[b][a] = min(dis[a][b], t);
    }

    floyd_warshall();

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cout << dis[i][j];
        cout << endl;
    }
}