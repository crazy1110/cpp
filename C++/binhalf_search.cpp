#include<iostream>
using namespace std;
int half_search(int a[],int low,int high,int key) 
{
	if(low>high)
	return -1;
	else{
		int mid=(low+high)/2;
		if(a[mid]==key)
		return mid;
		if(key>a[mid])
		return half_search(a,mid+1,high,key);
		else
		return half_search(a,low,mid-1,key);
	}
}
int main()
{
	int i,key;
	int a[16]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; 
	cout<<"输入待查找关键字:"<<endl;
	while(cin>>key)
	{
	int ans=half_search(a,0,14,key);
	if(ans!=-1)
	cout<<"查找成功,"<<"这是第"<<ans+1<<"个数"<<endl;
	else
	cout<<"查找失败!"<<endl;
	}
	return 0;
}
