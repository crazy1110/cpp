#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,k;
	int left=0,f=0;
	int *queue;
	cin>>n>>k>>m;
	queue=(int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
	queue[i]=0;
	int p=0;
	while(f<n)
	{
		for(int j=0;j<n;j++)
		{
			if(queue[j]>=m)		//它已经拿了每个桃子
			continue;
			else if((queue[j]+p%k+1<m)&&(left==0))
			{
				queue[j]=queue[j]+p%k+1;
				p++;
			}
			else if((left==0)&&(queue[j]+p%k+1>=m))
			{
				left=queue[j]+(p%k)+1-m;
				queue[j]=m;
				p++;
				f++;
				cout<<j+1<<" ";
			}
			else if((left+queue[j]<m)&&(left!=0))
			{
				queue[j]+=left;
				left=0;
			}
			else if((queue[j]+left>=m)&&(left!=0))
			{
				left=left+queue[j]-m;
				queue[j]=m;
				f++;
				cout<<j+1<<" ";
			}
		}
	}
}
