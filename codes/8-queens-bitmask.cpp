#include <bits/stdc++.h>
using namespace std;

//Let's code together 
/* Lucas Nogueira - Problema: 8 Queens com otimização de bitmask */
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
const int maxn = 2e5 + 100;
const double eps = 0.000000001;
const int64_t MOD = 1e7+7;

typedef vector<vector<int>> mi;
typedef pair<int, int> pii;
// ~3~

const int tamanho = 8;
int x, y;
vector<vector<int>> sol;


void printTab(vector<vector<int>> &tab){
      for (int i = 0; i < tamanho; i++) {
            for (int j = 0; j < tamanho; j++) cout << tab[i][j];
            cout << endl;
        }
}


void resolve(vector<vector<int>> &tab, int linha, int linha_mask, int dia1_mask, int dia2_mask, int &formas){
    int tudo_cheio = (1 << (tamanho) ) - 1;

    if (linha_mask == tudo_cheio) {
        vector<int> v;
        
        for (int i = 0; i < tamanho; i++) {
            for (int j = 0; j < tamanho; j++) {
                if (tab[i][j] == 1) v.pb(j + 1);
            }
        }
        if( v[y] == x+1 ) sol.pb(v);              
        return;
    }
 
 
    int s = tudo_cheio & (~(linha_mask | dia1_mask | dia2_mask));
    
    while(s) {
        int p = s & (-s);
        int col = (int)log2(p);
        tab[linha][col] = 1;
        resolve(tab, linha + 1, linha_mask | p, (dia1_mask | p) << 1, (dia2_mask | p) >> 1, formas);
        s = s & (s - 1);
        tab[linha][col] = 0;
    }
    return;
}
 

int32_t main(){
      fio;
      int t;
      cin >> t;

      while(t--){
            int formas = 0;
            vector<vector<int>> tab;

            for (int i = 0; i < tamanho; i++) {
                  vector<int> tmp;
                  for (int j = 0; j < tamanho; j++) tmp.pb(0);
                  tab.pb(tmp);
            }
            
            cin >> x >> y;
            --x;
            --y;
            
            int linha_mask = 0;
            int dia1_mask = 0; // esquerda
            int dia2_mask = 0; // direita
            int linha = 0;
            
            
            sol.clear();
            resolve(tab, linha, linha_mask, dia1_mask, dia2_mask, formas);
            sort(all(sol));

            cout << "SOLN       COLUMN" << endl;
            cout << " #      1 2 3 4 5 6 7 8" << endl;
            cout << endl;
            int i = 1;
            for (auto z : sol) {
                  if(i < 10) cout << " ";
                  cout << i << "      ";
                  i++;
                  for(int i = 0; i < sz(z); i++){
                        if(i != sz(z)-1) cout << z[i] << " ";
                        else cout << z[i];
                  }
                  cout << endl;
            }
            if(t!=0) cout << endl;
      }
}
