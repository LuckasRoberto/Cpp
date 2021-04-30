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

int t[maxn];
int seq[maxn];

int mdc(int a, int b){
    if(b == 0) return a;
    else return mdc(b, a%b);
}

int op(int a, int b){
    int c = mdc(a, b);
    return c;
}

void init(int no, int esq, int dir){
    if(dir == esq){
        t[no] = seq[esq-1];
        return;
    }
    else if(esq > dir) return;
    int mid = esq + (dir-esq)/2;
    init(2*no, esq, mid);
    init(2*no+1, mid+1, dir);
    t[no] = op(t[2*no], t[2*no+1]);
}

void atualiza(int no, int esq, int dir, int pos, int valor){
    if(esq == dir){
        t[no] = valor;
    }
    else{
        int mid = esq + (dir-esq)/2;
        if(pos <= mid) atualiza(2*no, esq, mid, pos, valor);
        else atualiza(2*no+1, mid+1, dir, pos, valor);
        t[no] = op(t[2*no], t[2*no+1]);
    }
}

int consulta(int no, int esq, int dir, int tesq, int tdir){
    if(tesq > tdir) return 0;
    if(esq == tesq && dir == tdir) return arvore[no];
    int mid = esq + (dir-esq)/2;
    int res_esq = consulta(2*no, esq, mid, tesq, min(tdir, mid));
    int res_dir = consulta(2*no+1, mid+1, dir, max(tesq, mid+1), tdir);
    return op(res_dir, res_esq);
} 

int32_t main(){
    fio;
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> seq[i];
    init(1, 1, n);

    for(int i = 0; i < m; i++){
        int t;
        cin >> t;
        if(t == 1){
            int indice, valor;
            cin >> indice >> valor;
            atualiza(1, 1, n, indice, valor);
        }
        else if(t == 2){
            int e, d;
            cin >> e >> d;
            int mdc = consulta(1, 1, n, e, d);
        }
    }

    for(int i = 1; i <= 4*n; i++) cout << t[i] << endl;
}