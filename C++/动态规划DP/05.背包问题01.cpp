//·ëÈü·ï 6.8
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int a[1006];
	int v[1006],w[1006];
	int sv,n;
	while(cin>>sv>>n)
	{
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
		cin>>v[i]>>w[i];
		for(int i=0;i<n;i++)
		{
			for(int j=sv;j>=v[i];j--)
			{
				int t=a[j-v[i]]+w[i];
				a[j]=max(a[j],t);
			}
		}
		cout<<a[sv]<<endl;
	}
	return 0;
 } 

