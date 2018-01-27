#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
	int num[30];
	int n,key;
	cout<<"请输入待查找的数据总数："<<endl;
	cin>>n;
	cout<<"请输入待查找数据列表："<<endl; 
	for(int i=1;i<=n;i++)
	cin>>num[i];
	sort(num,num+n+1);
	cout<<"请输入待查找数据："<<endl;
	cin>>key;
	int low=1,high=n,mid;
	while(low<=high)
	{
		mid=(low + high) / 2;
		if(key==num[mid])
		{
			cout<<endl<<"查找成功"<<endl;
			break;
		}
		else if(key<num[mid])
		high = mid - 1;
		else 
		low = mid + 1;
	} 
	if(high<low)
	cout<<endl<<"查找失败"<<endl;
	return 0;
 } 
