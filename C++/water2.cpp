//·ëÈü·ï   2017.10.6 
#include<iostream>
#include<algorithm>
using namespace std;
bool f=true;
int i,n;
struct station
{
	int x,y;
}sta[100008];
bool cmp(station a,station b)
	{
		return a.y>b.y;
	}
int main()
{
	while(cin>>n)
	{
		unsigned long long R,r=0;
		for(i=1;i<=n;i++)
		{
			cin>>sta[i].x>>sta[i].y;
		}
		sort(sta+1,sta+n+1,cmp);
		for(i=n;i>=1;i--)
		{
			R=(sta[i].y-sta[i].x);
			r+=R;
			if(r<sta[i].x)
			{
				f=false; break;	
			}
		}
		(f==false)?(cout<<"No"<<endl):(cout<<"Yes"<<endl);
	}
		return 0;
}

