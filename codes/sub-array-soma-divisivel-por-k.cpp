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
int n;
vector<int>arr;

int solve(int k) { 
    unordered_map <int, int>resto;
    int s = 0; 
    for (int i = 0; i < n; i++) { 
        s += arr[i]; 
        resto[((s%k)+k)%k]++; 
    }  
    int res = 0;
    res += resto[0];
    for (int i = 0; i < k; i++){
        // (resto[i] escolhe 2) possibilidades de i e j  
        res += ((resto[i])*(resto[i]-1))/2;
    }
    return res; 
} 

int32_t main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr.pb(a);
    }
    cout << solve(8);
}