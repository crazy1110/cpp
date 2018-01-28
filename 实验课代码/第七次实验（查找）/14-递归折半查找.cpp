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
	int len,i,a[100],key;
	cout<<"输入查找序列长度:"<<endl;
	cin>>len;
	cout<<"输入查找序列:"<<endl;
	for(i=0;i<len;i++)
	cin>>a[i];
	cout<<"输入待查找关键字:"<<endl;
	cin>>key;
	int ans=half_search(a,0,len-1,key);
	if(ans!=-1)
	cout<<"待查找序列中存在该关键字!"<<endl;
	else
	cout<<"查找失败!"<<endl;
	return 0;
}
