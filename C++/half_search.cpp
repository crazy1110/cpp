#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
	int num[30];
	int n,key;
	cout<<"����������ҵ�����������"<<endl;
	cin>>n;
	cout<<"����������������б�"<<endl; 
	for(int i=1;i<=n;i++)
	cin>>num[i];
	sort(num,num+n+1);
	cout<<"��������������ݣ�"<<endl;
	cin>>key;
	int low=1,high=n,mid;
	while(low<=high)
	{
		mid=(low + high) / 2;
		if(key==num[mid])
		{
			cout<<endl<<"���ҳɹ�"<<endl;
			break;
		}
		else if(key<num[mid])
		high = mid - 1;
		else 
		low = mid + 1;
	} 
	if(high<low)
	cout<<endl<<"����ʧ��"<<endl;
	return 0;
 } 
