#include<iostream>
using namespace std;
int main()
{
	int a[20],i,key,j,len;
	cout<<"������������г���:"<<endl;
	cin>>len;
	cout<<"������������У�"<<endl;
	for(i=1;i<=len;i++)
	cin>>a[i];
	cout<<"��������ҹؼ��֣�"<<endl;
	cin>>key;
	a[0]=key;
	for(j=a[len];j>=1;j--)
	{
		if(a[j]==a[0])
		{
			cout<<"���ҳɹ���"<<endl;
			break;
		}
		else 
		continue;
	 } 
	 if(j==0)
	 cout<<"����ʧ�ܣ�"<<endl;
	 return 0;
} 
