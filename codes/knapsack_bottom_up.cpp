#include <bits/stdc++.h>
using namespace std;

/* Lucas Nogueira - Problema:  */
//Let's code together 

#define ff first
#define ss second
#define sz(x) (int)(x).size()
#define oo 0x3f3f3f3f
#define fio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(-1);
#define endl '\n'
#define int long long
#define fur(i, a, b) for(int i = a; i < b; i++);
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

const int64_t MOD = 1e7+7;
const double eps = 0.000000001;
const int maxn = 2e6 + 100;

typedef vector<vector<char>> mi;
typedef pair<int, int> pii;
// ~3~
//

int c[maxn];
int p[maxn];
int z[10000][10000];

int knp(int s, int n){
      for(int i = 0; i <= n; i++){
            for(int j = 0; j <= s; j++){
                  if(i == 0 || j == 0) z[i][j] = 0;
                  else{
                        if(p[i-1] <= j){
                              int a = c[i-1] + z[i-1][j - p[i-1]];
                              int b = z[i-1][j];
                              z[i][j] = max(a, b);
                        }
                        else{
                              z[i][j] = z[i-1][j];
                        }
                  }
            }
      }
      return z[n][s];
}

int32_t main(){
      fio;
      int n;
      int s;
      cin >> s >> n;

      for(int i = 0; i < n; i++){
            cin >> p[i];
            cin >> c[i];
      }

      cout << knp(s, n) << endl;
}



