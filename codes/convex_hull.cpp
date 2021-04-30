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
typedef pair<int, int> pt;
//C0d3

pt sm(pt a, pt b){
  return pt(a.x+b.x, a.y+b.y);
}
pt neg(pt a){
  return pt(-a.x, -a.y);
}

double cross(pt a, pt b){
  return (a.x*b.y - a.y*b.x);
}

bool cw(pt a, pt b, pt c){
  return cross(sm(b, neg(a)), sm(c, neg(a))) < 0;
}

bool ccw(pt a, pt b, pt c){
  return cross(sm(b, neg(a)), sm(c, neg(a))) > 0;
}

void convex_hull(vector <pt> &p){
  int m = sz(p);
  if(m == 1) return;
  pt p1 = p[0];
  pt p2 = p.back();
  
  vector <pt> up;
  vector <pt> down;
  
  up.pb(p1);
  down.pb(p1);
  for(int i = 0; i < m; i++){
    if(i == m-1 || ccw(p1, p2, p[i])){
      while(sz(up) >= 2 and cw(up[sz(up)-2], p[i], up[sz(up)-1])){
        up.pop_back();
      } 
      up.pb(p[i]);
    }
    if(i == m-1 || cw(p1, p2, p[i])){
      while(sz(down) >=2 and ccw(down[sz(down)-2], p[i], down[sz(down)-1])){
        down.pop_back();
      }
      down.pb(p[i]);
    }
  }

  p.clear();
  for(int i = 0; i <sz(up); i++)p.pb(up[i]);
  for(int i = sz(down)-2; i > 0; i--) p.pb(down[i]);
}

int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int n;
  
  cin >> n;
  set <pt> p;
  for(int i = 0; i < n; i++){
    pt c;
    cin >> c.x;
    cin >> c.y;
    p.insert(c);
  }

  vector<pt> hull;
  for(auto z : p){
    hull.pb(z);
  }

  convex_hull(hull);

  for(auto z : hull){
    cout << z.x << " " << z.y << " | "; 
  }
}

