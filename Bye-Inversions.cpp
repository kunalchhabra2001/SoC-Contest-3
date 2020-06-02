#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_NUM 1000009
#define int long long

int fwd[MAX_NUM];
int arr[MAX_NUM];
int temp[MAX_NUM];
int n,k;

int main() {
  int t;
  cin >> t;
  for(int i=1;i<=t;i++){
    cin >> n >> k;
    memset(fwd, 0, sizeof(fwd));
    memset(temp, 0, sizeof(temp));
    int flag = 0;
    for(int i=1;i<=n;i++) {
      cin >> arr[i];
      temp[arr[i]]++;
      if(temp[arr[i]] > 1) flag = 1;
    }
    int t_inv = 0;
    for(int i=1;i<=n;i++) {
      t_inv += i-1;
      for(int j=arr[i];j>0;j=(j&(j-1))) t_inv -= fwd[j];
      for(int j=arr[i];j<MAX_NUM;j=(j|(j-1))+1) ++fwd[j];
    }
    int ans = t_inv-k;
    if(ans < 0) {
      ans *= -1;
      if(flag) ans = 0;
      else ans = ans%2;
    }
    cout<<"Case "<<t<<": "<<ans<<endl;
  }
}