#include <bits/stdc++.h>
using namespace std;

#define maxn 400000
int arvore[maxn];

int seq[maxn];
int op(int x, int y){
	return x+y;
}

void init(int no, int esq, int dir){
	if(esq == dir){
		arvore[no] = seq[esq-1];
		return;
	}	
	else if(esq > dir) return;
	int mid = esq + (dir - esq)/2;
	init(2*no, esq, mid);
	init(2*no + 1, mid+1, dir);
	arvore[no] = op(arvore[2*no], arvore[2*no+1]);
}

void atualiza(int no, int esq, int dir, int pos, int valor){
	if(esq == dir){ arvore[no] = valor;	}
	else{
		int mid = esq + (dir - esq)/2;
		if(pos <= mid) atualiza(2*no, esq, mid, pos, valor);
		else atualiza(2*no+1, mid+1, dir, pos, valor);
		arvore[no] = op(arvore[2*no], arvore[2*no+1]);
	}
}

int consulta(int no, int esq, int dir, int tesq, int tdir){
	if(tesq > tdir) return 0; //elemento neutro
	if(tesq == esq and tdir == dir) return arvore[no];
	int mid = esq + (dir - esq)/2;
	int res_esq = consulta(2*no, esq, mid, tesq, min(tdir, mid));
	int res_dir = consulta(2*no+1, mid+1, max(tesq, mid+1), tdir);
	return op(res_dir, res_esq);
}