#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string s,t,final;
	cin>>s>>t>>final;
	int w=s.find(t);
	while(w!=-1)
	{
		s.replace(w,t.length(),final);
		w=s.find(t);
	}
	cout<<s<<endl;
	return 0;
}
