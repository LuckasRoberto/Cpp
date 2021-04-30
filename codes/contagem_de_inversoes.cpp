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

int mg(vector<int>&v){
    int inv = 0;
    if(sz(v) == 1) return 0;

    vector<int> u1, u2;
    for(int i = 0; i < sz(v)/2; i++) u1.pb(v[i]);
    for(int i = sz(v)/2; i < sz(v); i++) u2.pb(v[i]);

    inv += mg(u1);
    inv += mg(u2);

    u1.pb(oo);
    u2.pb(oo);

    int x = 0;
    int y = 0;
    
    for(int i = 0; i < sz(v); i++){
        if(u1[x] < u2[y]){
            v[i] = (u1[x]);
            x++;
        }
        else{
            v[i] = u2[y];
            y++;
            inv += sz(u1) - x - 1;
        }
    }

    return inv;
}

int32_t main(){
    fio;
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int>p(n);
        for(int i =0; i< n;++i){
            cin >> p[i];
        }

        cout << "(" << mg(p) << ")"<< endl;

    }
}