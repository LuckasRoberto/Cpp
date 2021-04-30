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
#define endal '\n'
const int maxn = 2007;
const double eps = 0.000000001;
const int64_t MOD = 1e7+7;

double p, h[maxn][maxn];
void dp(int n, int t){
    h[0][0]=1;
    for(int i=0; i<t ;i++){
        for(int j=0; j<n; j++){
            if(h[i][j]>0){
                h[i+1][j+1]+=h[i][j]*p;
                h[i+1][j] += h[i][j]*(1-p);
            }
        }
        h[i+1][n] += h[i][n];
    }
}
 
int32_t main(){
    int n, t;
    double res = 0;
    cin>>n>>p>>t;
    dp(n, t);
    for(int i=1;i<=n;i++) res += h[t][i]*i;
    cout << setprecision(9) << fixed << res << endl;
}