//·ëÈü·ï   2017.10.6 
#include<iostream>
#include<algorithm>
using namespace std;
int n,i,r;
bool f=true;
struct station
{
	int x,y;
}sta[100001];
int main()
{
	int comp(station a,station b);
	while(cin>>n)
	{
		for(i=1;i<=n;i++)
		{
			cin>>sta[i].x>>sta[i].y;
		}
		sort(sta+1,sta+n+1,comp);
		for(i=n;i>=1;i--)
		{
			int R=sta[i].x-sta[i].y;
			r+=R;
			if(r<sta[i].x)
			{
				f=false; break;	
			}
		}
		if(f==false)
		cout<<"NO"<<endl;
		else
		cout<<"YES"<<endl;
	}
		return 0;
}
int comp(station a,station b)
	{
		return a.y>b.y;
	}
