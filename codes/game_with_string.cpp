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
#define fio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(0);
#define endl '\n'
const int maxn = 6000;
const double eps = 0.000000001;
const int64_t MOD = 998244353;

typedef vector<vector<int>> mi;
typedef pair<int, int> pt;
//c0d3

int su[26][maxn];
int mark[26][maxn][26];
int la[26];
int yes[26][maxn];

void solve(string s, int n){
    for(int i = 0; i <n; i++){
        int x = s[i] - 'a';
        la[x]++;
        for(int j = 1; j < n; j++){
            int y = s[(i+j)%n] - 'a';
            if(mark[x][j][y] == 1){
                yes[x][j]++;
                su[x][j]--;
                mark[x][j][y]++;
                yes[x][j]++;
            }
            else if(mark[x][j][y]){
                mark[x][j][y]++;
                yes[x][j]++;
            }
            else{
                mark[x][j][y]++;
                su[x][j]++;
            }
        }
    }
}

int32_t main(){
    string s;
    double res = 0;
    cin >> s;
    int n = sz(s);
    solve(s, n);
    for(int i = 0; i < 26; i++){
        if(la[i]){
            double t = 0;
            for(int j = 1; j < n; j++){
                double dd = su[i][j];
                double nn = su[i][j] + yes[i][j];
                t = max(t, dd/nn);
            }
            res += t*la[i]/double(n);
        }
    }
    cout << setprecision(9) << fixed << res << endl;
}