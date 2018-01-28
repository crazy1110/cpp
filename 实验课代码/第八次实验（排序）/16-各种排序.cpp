#include<iostream>
#include<cstring>
using namespace std;
void insert_sort(int a[],int len)     //���������㷨
{
	int i,j;
	for(i=2;i<=len;i++)
	{
	if(a[i]<a[i-1])
	{
		a[0]=a[i];
		a[i]=a[i-1];
		for(j=i-2;a[0]<a[j];j--)
		a[j+1]=a[j];
		a[j+1]=a[0];
	}
	}
 } 
void BInsertSort(int a[],int len)	//�۰�������� 
{
	int i,j;
	for(i=2;i<=len;i++)
	{
		a[0]=a[i];
		int low=1,high=i-1;
		while(low<=high)
		{
			int m=(low+high)/2;
			if(a[0]<a[m])
			high=m-1;
			else 
			low=m+1;
		}
		for(j=i-1;j>=high+1;j--)
		a[j+1]=a[j];
		a[high+1]=a[0];
	}
}
//������
void Swap(int *x, int *y)	//������ 
{

	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void Max_heapify(int array[], int i, int heap_size)
{
	int largest;
	int _left=2*i;
	int _right=2*i+1;

	if (_left<=heap_size && array[_left]>array[i])
	{
		largest=_left;
	}
	else
		largest=i;

	if (_right<=heap_size && array[_right]>array[largest])
	{
		largest=_right;
	}

	if (largest!=i)
	{
		Swap(&array[largest],&array[i]);
		Max_heapify(array,largest,heap_size);
	}
}

void Build_max_heap(int array[],int len)
{

	int heap_size=len;
	for (int i=len/2; i>=1; i--)
	{
		Max_heapify(array,i,heap_size);
	}
}

void Heapsort(int array[],int len)
{
	int heap_size=len;
	Build_max_heap(array,len);
	for (int i=len; i>=2; i--)
	{
		Swap(&array[1],&array[i]);
		heap_size--;
		Max_heapify(array,1,heap_size);
	}
} 
//��������� 
//ѡ������ 
void SelectionSort(int num[],int n)  
{  
 int i = 0;  
 int min = 0;  
 int j = 0;  
 int tmp = 0;  
 for(i = 1;i <= n;i++)  
 {  
    min = i;//ÿ�ν�min�ó���������ʼλ��Ԫ���±�   
    for(j = i;j <= n;j++)//���������飬�ҵ���СԪ�ء�   
    {  
      if(num[min]>num[j])  
      {  
       min = j;  
      }  
    }  
    if(min != i)//�����СԪ�ز�����������ʼλ��Ԫ�أ�������ʼԪ�ؽ���λ��   
    {  
      tmp = num[min];  
      num[min] = num[i];  
      num[i] = tmp;  
    }  
 }  
}  
//ѡ��������� 
//��������
void quickSort(int a[],int l,int r)  
{  
    if (l< r)  
    {        
        int i = l, j = r, x = a[l];  
        while (i < j)  
        {  
            while(i < j && a[j]>= x) // ���������ҵ�һ��С��x����  
                j--;   
            if(i < j)  
                a[i++] = a[j];  
            while(i < j && a[i]< x) // ���������ҵ�һ�����ڵ���x����  
                i++;   
            if(i < j)  
                a[j--] = a[i];  
        }  
        a[i] = x;  
        quickSort(a, l, i - 1); // �ݹ����  
        quickSort(a, i + 1, r);  
    }  
}   
//����������� 
int main()
{
	int a[10],len;
	cin>>len;
	for(int i=1;i<=len;i++)
	cin>>a[i];
	insert_sort(a,len);
	BInsertSort(a,len);
	Heapsort(a,len);
	SelectionSort(a,len);
	quickSort(a,1,len);
	for(int i=1;i<=len;i++)
	cout<<a[i]<<" ";
	return 0;
}
