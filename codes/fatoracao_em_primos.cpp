#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define fur(i, a, b) for(int i = a; i < b; i++);
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define ii first
#define ff second
#define sz(x) (int)(x).size()
#define oo 0x3f3f3f3f
#define maxn 100500
#define fio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(0);
#define endl '\n'
const double eps = 0.000000001;

typedef vector<vector<int>> mi;
typedef pair<int, int> pii;
//C0d3

vector<int> crivo(int n){
  vector<int> s(n+1, 1);
  vector<bool> prime(n+1, 1);

  prime[1] = 0;
  for(int i = 2; i<= n; i+=2) {
    s[i] = 2;
    prime[i] = 0;
  }
  for(int i = 3; i <= n; i+=2){
    if(prime[i] == 1){
      s[i] = i;
      for(int j = i; j*i <= n; j+=2){
        if(prime[i*j] == 1){
          prime[i*j] = 0;
          s[i*j] = i;
        }
      }
    }
  }

  return s;
}

void printfactors(int n){
  vector<int> s;
  s = crivo(n);

  int a = s[n];
  int cnt = 1;
  
  while(n > 1){
    n /= s[n];
    if(a == s[n]){
      cnt++;
      continue;
    }
    cout << a << " " << cnt << endl;
    a = s[n];
    cnt = 1;
  }
}

int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int n;
  cin >> n;
  printfactors(n);
}