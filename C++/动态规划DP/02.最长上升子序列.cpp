//·ëÈü·ï  6.5
#include<iostream>
using namespace std;
int main()
{
	int dp[100],v[100];
	while(cin>>v[0])
	{
		if(v[0]==0)
		return 0;
		int i,j,n=0,sum=0;
		
		while(getchar()!='\n')
		{
			n++;
			cin>>v[n];
		}
		for(i=0;i<=n;i++)
		{
			dp[i]=1;
			for(j=0;j<i;j++)
			{
				if(v[j]<v[i])
				dp[i]=max(dp[i],dp[j]+1);
			}
			sum=max(dp[i],sum);
		}
		cout<<sum<<endl;
	 } 
	 return 0;
}

