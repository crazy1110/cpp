#include<iostream>
using namespace std;
int main()
{
	cout<<"������������n��"<<endl;
	int n;
	cin>>n; 
	int a[10][10],b[10][10];
	cout<<"�������һ��n�׾���"<<endl;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	cin>>a[i][j];
	cout<<"������ڶ���n�׾���"<<endl;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	cin>>b[i][j];
	int count=0;
	cout<<"�õ�����Ӿ���Ϊ��"<<endl;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		a[i][j]+=b[i][j];
		printf("%2d",a[i][j]);
		count++;
		if(count%n==0)
		cout<<endl;
	}
	return 0;
}
