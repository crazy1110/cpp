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
	cout<<"����������г���:"<<endl;
	cin>>len;
	cout<<"�����������:"<<endl;
	for(i=0;i<len;i++)
	cin>>a[i];
	cout<<"��������ҹؼ���:"<<endl;
	cin>>key;
	int ans=half_search(a,0,len-1,key);
	if(ans!=-1)
	cout<<"�����������д��ڸùؼ���!"<<endl;
	else
	cout<<"����ʧ��!"<<endl;
	return 0;
}
