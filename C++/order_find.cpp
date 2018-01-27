#include<iostream>
using namespace std;
int main()
{
	int a[20],i,key,j,len;
	cout<<"输入待查找序列长度:"<<endl;
	cin>>len;
	cout<<"输入待查找序列："<<endl;
	for(i=1;i<=len;i++)
	cin>>a[i];
	cout<<"输入待查找关键字："<<endl;
	cin>>key;
	a[0]=key;
	for(j=a[len];j>=1;j--)
	{
		if(a[j]==a[0])
		{
			cout<<"查找成功！"<<endl;
			break;
		}
		else 
		continue;
	 } 
	 if(j==0)
	 cout<<"查找失败！"<<endl;
	 return 0;
} 
