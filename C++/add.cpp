#include<iostream>
using namespace std;
int main()
{
	cout<<"请输入矩阵阶数n："<<endl;
	int n;
	cin>>n; 
	int a[10][10],b[10][10];
	cout<<"请输入第一个n阶矩阵："<<endl;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	cin>>a[i][j];
	cout<<"请输入第二个n阶矩阵："<<endl;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	cin>>b[i][j];
	int count=0;
	cout<<"得到的相加矩阵为："<<endl;
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
