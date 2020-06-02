#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,z;
		cin >> n >> z;
		int arr[n],sum=0;
		for(int i=0;i<n;i++){
			cin >> arr[i];
		}
		sort(arr,arr+n);

		for(int i=0;i<z;i++){
			sum += arr[i];
		}
		sum += arr[z-1]*(n-z); //Min time for finding correct a[z-1]
		int f=sum,s=sum,k=0;
		for(int i=z;i<n;i++){
			//Check if for i>z if those can be found in time less than for z//
			s+= (arr[i]-arr[i-1])*(n-1)-arr[k];
			k++;
			if(s<sum)sum=s;
		}
		s = f;
		int g=0;
		for(int i=0;i<z;i++)
		{
			k=i+1;
			g=arr[i];
			for(int j=z;j<n;j++)
			{
				s += (arr[j]-arr[j-1])*(n-j)-arr[k]+g;
				k++;
				if(s<sum)sum=s;
			}
			s=f;
		}
		cout << sum << endl;

	}


}