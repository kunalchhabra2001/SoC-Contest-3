#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
typedef long double ld;

const int N = 1e5 + 5;

int p[N], size[N];
int arr[N], px[N];
bool dead[N];

int find(int v){
	if(v == p[v])return v;
	int y = p[v];
	int x = find(y);
	px[v] ^= px[y];
	return p[v] = x;
}

void combine(int u, int v){
	int xu = find(u);
	int xv = find(v);
	if(xu == xv){
		if(px[u] == px[v])dead[xu] = true;
		return;
	}
	if(size[xu] < size[xv])swap(xu, xv);
	size[xu] += size[xv];
	p[xv] = xu;
	px[xv] = 1^px[u]^px[v];
	dead[xu] |= dead[xv];
}

signed main(){
	
	cout<<setprecision(32);

	int n, m;
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		size[i] = 1;
		p[i] = i;
		px[i] = 0;
		dead[i] = false;
		cin>>arr[i];
	}
	int type, x, y, c, v;
	while(m--){
		cin>>type;
		if(type == 1){
			cin>>x>>c;
			arr[x] = c;
		}else if(type == 2){
			cin>>x>>y;
			combine(x, y);
		}else{
			cin>>x>>y>>v;
			int xx = find(x);
			int xy = find(y);
			if(xx != xy || dead[xx]){
				cout<<0<<'\n';
			}else{
				int num = v*1LL*arr[x];
				int den = arr[y];
				int g = __gcd(num, den);
				num /= g; den /= g;
				if(px[x]^px[y])cout<<'-';
				cout<<num<<'/'<<den<<'\n';
			}
		}
	}

	return 0;
}
