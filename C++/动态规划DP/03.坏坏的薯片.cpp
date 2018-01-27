//·ëÈü·ï  6.5
#include<iostream>
using namespace std;
int main() {
    int m,n;
    while(cin>>m>>n) {
        long long dp[1001];
        for(int i=1; i<=m; i++) {
            cin>>dp[i];
        }
        int x;
        for(int i=n+1; i<=m; i++) {
            x=1000000;
            for(int j=i-n; j<i; j++) {
                if(dp[j]<x)
                    x=dp[j];
            }
            dp[i]+=x;
        }
        cout<<dp[m]<<endl;
    }
}
/* 
#include<iostream>
using namespace std;
int main()
{
	int m,k;
	int i,j;
	int a[1006],b[1006];
	while(cin>>m>>k)
	{
		for(i=1;i<=m;i++)
		cin>>a[i];
		for(i=1;i<=k;i++)
		b[i]=a[i];
		for(i=k+1;i<=m;i++)
		{
			b[i]=b[i-k];
			for(j=i-k+1;j<i;j++)
			if(b[j]<b[i])
			b[i]=b[j];
			b[i]+=a[i];
		}
		cout<<b[m]<<endl;
	}
	return 0;
 }  */ 
