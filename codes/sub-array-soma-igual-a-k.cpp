#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define fur(i, a, b) for(int i = a; i < b; i++);
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) (int)(x).size()
#define oo 0x3f3f3f3f
#define maxn 1000500
#define fio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(0);
#define endl '\n'

typedef vector<vector<int>> mi;
//C0d3

int n, k;


int32_t main(){
    cin >> n >> k;

    vector<int>v;
    for(int i = 0; i <n; i++){
        int a;
        cin >> a;
        v.pb(a);
    }

    int res = 0;
    int pref = 0;
    unordered_map <int, int> cpref;
    cpref[pref]++;

    for(int i = 0; i<n; i++){
        pref += v[i];
        int need = pref - k;  // soma(l,r) = pref[r-1] - pref[l]
        res += cpref[need];
        cpref[pref]++;
    }
    cout << res;

}