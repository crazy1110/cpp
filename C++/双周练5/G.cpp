//·ëÈü·ï 6.10 
#include<iostream>
#include<cstring>
using namespace std;
int a[25],b[25],c[25];
int i,j;
int main()
{
	int n=1;
	while(scanf("%d",&a[n])!=EOF)
	{
		b[n]=1;
		n++;
	}
	memset(c,0,sizeof(c));
	n--;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<i;j++)
		{
			if(a[j]>a[i])
			b[i]=max(b[i],b[j]+1);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<i;j++)
		{
			if(a[i]>a[j])
			c[i]=max(c[i],c[j]+1);
		}
	}
	j=0;
	for(i=1;i<=n;i++)
	j=max(j,b[i]);
	cout<<j<<endl;
	j=0;
	for(i=1;i<=n;i++)
	j=max(c[i],j);
	j++;
	cout<<j<<endl;
	return 0;
}
