//·ëÈü·ï 6.8 
#include<iostream>
#include<algorithm>
using namespace std;
struct  st
{
	int t;
	int s;
};
int cmp(st a,st b)
{
	return a.t<b.t;
}
int main()
{
	int n;
	while(cin>>n)
	{
		int sum=1;
		st m[n];
		for(int i=0;i<n;i++)
		cin>>m[i].s>>m[i].t;
		sort(m,m+n,cmp);
		int temp=m[0].t;
		for(int i=1;i<n;i++)
		{
			if(m[i].s>temp)
			{
				temp=m[i].t;
				sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

