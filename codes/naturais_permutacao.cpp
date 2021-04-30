#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define fur(i, a, b) for(int i = a; i < b; i++);
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss seconds
#define sz(x) (int)(x).size()
#define oo 0x3f3f3f3f
#define maxn 1050
#define fio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(0);
#define endl '\n'

typedef vector<vector<int>> mi;

vector <string> dic;

void permu(int l, int r, string s){
	if(l == r){
		dic.pb(s);
		//cout << s << endl;
	}
	
	for (int i = l; i <= r; i++){
		swap(s[l], s[i]);
		permu(l+1, r, s);
		swap(s[l], s[i]);	
	}
}

int fato (int n){
	if(n == 2) return 2; 
	if(n == 1) return 1;
	return n*fato(n-1);	
}

int32_t main(){
	int n;
	cin >> n;	
	string nat;
	
	for(int i = 1; i <= n; i++){
		nat += i + '0';
	}
	
	permu(0, sz(nat)-1, nat);
	
	map<string, int> mp;
	for(int i = 0; i < fato(n)-1; i++){
		string ww;
		for(int j = 0; j < n; j++){
			char a;
			cin >> a;
			ww += a;	
		}
		mp[ww] = 1;
	}
	
	for(auto z : dic){
		if(mp[z] != 1){
			for(auto y : z) cout << y << " ";
			break;	
		}
	}
}
