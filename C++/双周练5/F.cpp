//·ëÈü·ï 6.10 
#include<iostream>
#include<cstring>
using namespace std;
int i,j,k;
int dp[9][11]={0};
void mj()
{
    memset(dp,0,sizeof(dp));
    for(j=0; j<=9; ++j)
        dp[1][j] = 1;
    dp[1][4] = 0;
    for(i=2; i<=8; ++i)
    {
        for(j=0; j<=9; ++j)
        {
            if(j==4) 
			continue;
            for(k=0; k<=9; ++k)
            {
                if(j==6&&k==2)
				 continue;
                dp[i][j] += dp[i-1][k];
            }
        }
    }
}

int answer(int x)
{
    int d[10];
    for(i=1;; i++)
    {
        d[i] = x%10;
        x = x/10;
        if(x==0) 
		break;
    }
    d[i+1] = 0;
    int sum = 0;
    for( ; i>=1; i--) 
    {
        for(k=0; k<d[i]; k++)
        {
            if(k==4 || (d[i+1]==6 && k==2))
			 continue;  
            sum += dp[i][k];
        }

        if(d[i]==4 || (d[i]==2 && d[i+1]==6))
            break;
        if(i==1)
            sum += dp[i][k];
    }
    return sum;
}

int main()
{
    int n,m;
    mj();
    while(cin>>n>>m)
    {
    	if(m==0&&n==0)
    	return 0;
    	int total=answer(m)-answer(n-1);
    	cout<<total<<endl;
	}
    return 0;
}
