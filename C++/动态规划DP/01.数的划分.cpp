//·ëÈü·ï 6.5 
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n,k,i,j;
	int dp[205][105];
	dp[0][0]=1;
	//memset(dp,0,sizeof(dp));
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=k;j++)
		{
		if(i<j)
		dp[i][j]=dp[i-1][j];
		else
		dp[i][j]=dp[i-1][j-1]+dp[i-j][j];
		}
	}
	cout<<dp[n][k]<<endl;
	return 0;
}


