#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MAX_num = 100005;
int n, q, a, b, Arr[MAX_num], tmp[MAX_num];
vector<int> V[MAX_num];

void solve(int u){
	memset(tmp, 0, sizeof(tmp));
	int l = V[u].size();

	for(int i = 0; i < l; i++){
		int num = V[u][i];
		tmp[num]++;
	}

	for(int i = 1; i <= n; i++){
		if(i >= u) tmp[i] += tmp[i - u];
		Arr[i] += tmp[i];
	}
}

signed main(){
	cin >> n >> q;
	int sq = sqrt(n);

	for(int i = 1; i <= q; i++){
		cin >> a >> b;

		if(a > sq){
			for(int i = 0; a * i + b <= n; Arr[a * i + b]++, i++);
		}else{
			V[a].push_back(b);
		}
	}
	for(int i = 1; i <= sq; i++){
		if(V[i].size()){
			solve(i);
		}
	}

	for(int i = 1; i <= n; i++){
		if(i>1) cout << " ";
		cout << Arr[i];
	}

	cout << '\n';
	return 0;
}