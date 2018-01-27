//·ëÈü·ï 6.10
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int m,n;
	int i,j;
	int map[31][31],a[31][31];
	memset(map,0,sizeof(map));
	memset(a,0,sizeof(a));
	cin>>m>>n;
	for(i=1;i<=m;i++)
	for(j=1;j<=n;j++)
	cin>>map[i][j];
	a[1][1]=map[1][1];
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(j==1&&i==1)
			continue;
			else if(map[i][j]==-1)
			a[i][j]=0;
			else if(a[i-1][j]==0&&a[i][j-1]==0)
			a[i][j]=0;
			else
			{
				int s1=a[i-1][j];
				int s2=a[i][j-1];
				int s=max(s1,s2);
				a[i][j]=s+map[i][j];
			}
		}
	}
	if(a[m][n]!=0)
	cout<<a[m][n]<<endl;
	else
	cout<<"Xiao Ming is a stupid boy"<<endl;
	return 0;
 }  

