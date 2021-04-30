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
const int maxn = 2500000;
const double eps = 0.000000001;
const int64_t MOD = 1e7+7;

typedef vector<vector<int>> mi;
typedef pair<int, int> pii;
// ~3~

int arvore[maxn];
int saco[maxn];

int op(int x, int y){
	return x+y;
}

void build_seg_tree(int no, int esq, int dir){
	if(esq == dir){
		arvore[no] = saco[dir];
		return;
	}	
	int mid = esq + (dir - esq)/2;
	build_seg_tree(2*no, esq, mid);
	build_seg_tree(2*no + 1, mid+1, dir);
	arvore[no] = op(arvore[2*no], arvore[2*no+1]);
}

void add_money(int no, int esq, int dir, int pos, int valor){
	if(esq == dir){ 
        if(esq == pos) arvore[no] += valor;
        else{
            arvore[no] = saco[esq];
        }
        return;
    }
	else{
		int mid = esq + (dir - esq)/2;
		if(pos <= mid) add_money(2*no, esq, mid, pos, valor);
		else add_money(2*no+1, mid+1, dir, pos, valor);
		arvore[no] = op(arvore[2*no], arvore[2*no+1]);
	}
}

void dar_money(int no, int esq, int dir, int pos){
	if(esq == dir){ 
        if(pos == esq){
            cout << arvore[no] << endl;
        }
        arvore[no] = saco[dir];
        return;
    }
	else{
		int mid = esq + (dir - esq)/2;
		if(pos <= mid) dar_money(2*no, esq, mid, pos);
		else dar_money(2*no+1, mid+1, dir, pos);
		arvore[no] = op(arvore[2*no], arvore[2*no+1]);
	}
}

int consulta(int no, int esq, int dir, int tesq, int tdir){
    if(tdir < esq || dir < tesq) return 0;
    if(tesq <= esq && dir <= tdir) return arvore[no];

    int mid = esq + (dir-esq)/2;
    int res_esq = consulta(2*no, esq, mid, tesq, tdir);
    int res_dir = consulta(2*no+1, mid+1, dir, tesq, tdir);
    return op(res_dir, res_esq);
} 


int32_t main(){
    fio;
    int t;
    int n, q;
    cin >> t;
    int caso = 1;
    while(t--){
        cout << "Case " << caso  << ":" << endl;
        caso++;
        cin >> n >> q;
        for(int i = 1; i <= n; i++) cin >> saco[i];
        build_seg_tree(1, 1, n);

        for(int i = 0; i < q; i++){
            int tipo;
            cin >> tipo;
    
            if(tipo == 1){
                int indice;
                cin >> indice;
                indice += 1;
                saco[indice] = 0;
                dar_money(1, 1, n, indice);
            }
            else if(tipo == 2){
                int indice, valor;
                cin >> indice >> valor;
                add_money(1, 1, n, indice+1, valor);
            }
            else if(tipo == 3){
                int esq, dir;
                cin >> esq >> dir;
                cout << consulta(1, 1, n, esq+1, dir+1) << endl;
            }
        }

    }

}