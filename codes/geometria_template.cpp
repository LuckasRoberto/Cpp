#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define fur(i, a, b) for(int i = a; i < b; i++);
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(x) (int)(x).size()
#define oo 0x3f3f3f3f
#define maxn 10500
#define fio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(0);
#define endl '\n'
const double eps = 0.000000001;

typedef vector<vector<int>> mi;
//GA
typedef pair<int,int> ponto;
typedef pair<ponto, ponto>line;
typedef vector<ponto> poli;
//C0d3

ponto soma(ponto a, ponto b){
  ponto p;
  p.x = a.x + b.x;
  p.y = a.y + b.y;
  return p;
}

ponto neg(ponto a){
  ponto p;
  p.x = -a.x;
  p.y = -a.y;
  return p;
}

ponto dif(ponto a, ponto b){
  ponto p;
  ponto c = neg(b);
  p = soma(a, c);
}

double norma(ponto p){
  return (sqrt(p.x*p.x + p.y*p.y));
}
double dist(ponto a, ponto b){
  double xx = (a.x-b.x)*(a.x-b.x);
  double yy = (a.y-b.y)*(a.y-b.y);
  return (sqrt((xx) + (yy)));
}

double dot(ponto a, ponto b){
  return (a.x*b.x + a.y*b.y);
}
double cross(ponto a, ponto b){
  return (a.x*b.y - a.y*b.x);
}

double dist_pr(line l, ponto p){
  double crs = cross(dif(p, l.x), dif(l.y, l.x));
  return crs/dist(l.x, l.y);
}

double angle(ponto a, ponto b){
  double csine = dot(a, b)/(norma(a)*norma(b));
  double an = acos(csine);
}

double area(poli o){
  double area = 0;
  for(int i = 0; i < n; i++){
    ponto p1 = o[i];  
    ponto p2 = o[(i+1)%n];
    area += (p2.x + p1.x)*(p2.y - p1.y);
  }
  return area/2;
}

bool ccw(ponto a, ponto b, ponto c){
  int det = cross(dif(b, a), dif(c, a));
  if(det > 0) return 1; //esq
  if(det < 0) return -1 //dir
  return 0; //colinear;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

}